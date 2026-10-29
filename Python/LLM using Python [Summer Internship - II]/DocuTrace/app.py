import re
from collections import defaultdict

import streamlit as st
import pymupdf

# --------------------------------------------------
# 1. PAGE CONFIGURATION
# --------------------------------------------------

st.set_page_config(
    page_title="DocuTrace AI",
    page_icon="📄",
    layout="wide"
)

st.title("📄 DocuTrace AI")
st.caption(
    "Evidence-Based Document Question Answering "
    "& Cross-Document Conflict Detection"
)

st.info(
    "Free prototype: Python-based retrieval and conflict "
    "rules. No paid API or downloaded language model."
)


# --------------------------------------------------
# 2. PDF TEXT EXTRACTION
# --------------------------------------------------

def extract_uploaded_pdf(uploaded_file):
    """Extract text while preserving source and page."""

    pages = []
    pdf_bytes = uploaded_file.getvalue()

    with pymupdf.open(
            stream=pdf_bytes,
            filetype="pdf"
    ) as doc:

        if doc.needs_pass:
            raise ValueError(
                "This PDF is password-protected."
            )

        for page_number, page in enumerate(doc, start=1):
            text = page.get_text("text").strip()

            if text:
                pages.append({
                    "document": uploaded_file.name,
                    "page": page_number,
                    "text": text
                })

    return pages


# --------------------------------------------------
# 3. EVIDENCE RETRIEVAL
# --------------------------------------------------

STOP_WORDS = {
    "what", "when", "where", "who", "why", "how",
    "is", "are", "was", "were", "the", "a", "an",
    "of", "in", "on", "for", "to", "and", "or",
    "does", "do", "did", "please", "tell", "me",
    "which", "from", "this", "that", "it"
}


def tokenize(text):
    return re.findall(r"\b[a-z0-9]+\b", text.lower())


def retrieve_evidence(question, pages, top_k=5):
    question_words = (
            set(tokenize(question)) - STOP_WORDS
    )

    if not question_words:
        return []

    results = []

    for item in pages:
        passage_words = set(tokenize(item["text"]))
        matched = question_words & passage_words

        if matched:
            score = len(matched) / len(question_words)

            results.append({
                **item,
                "score": round(score, 3),
                "matched_words": sorted(matched)
            })

    results.sort(
        key=lambda item: item["score"],
        reverse=True
    )

    return results[:top_k]


# --------------------------------------------------
# 4. CONFLICT DETECTION RULES
# --------------------------------------------------

TOPIC_RULES = {
    "Application deadline": [
        "application deadline",
        "deadline for application",
        "last date to apply",
        "apply by"
    ],
    "Registration fee": [
        "registration fee",
        "application fee",
        "registration charge"
    ],
    "Exam date": [
        "exam date",
        "examination date",
        "exam will be held"
    ],
    "Interview date": [
        "interview date",
        "interview will be held",
        "interview scheduled"
    ],
    "Event date": [
        "event date",
        "event will be held",
        "event scheduled"
    ]
}

MONTHS = (
    "January|February|March|April|May|June|July|"
    "August|September|October|November|December|"
    "Jan|Feb|Mar|Apr|Jun|Jul|Aug|Sep|Sept|Oct|Nov|Dec"
)

DATE_PATTERN = re.compile(
    rf"\b(?:\d{{1,2}}\s+(?:{MONTHS})\.?"
    rf"|(?:{MONTHS})\s+\d{{1,2}})"
    rf"(?:,?\s+\d{{4}})?\b",
    re.IGNORECASE
)

MONEY_PATTERN = re.compile(
    r"(?:Rs\.?|INR|₹)\s*[\d,]+(?:\.\d{1,2})?",
    re.IGNORECASE
)


def detect_conflicts(pages):
    grouped = defaultdict(list)

    for item in pages:
        sentences = re.split(
            r"(?<=[.!?])\s+",
            item["text"]
        )

        for sentence in sentences:
            sentence_lower = sentence.lower()

            for topic, phrases in TOPIC_RULES.items():
                if not any(
                        phrase in sentence_lower
                        for phrase in phrases
                ):
                    continue

                # Look for date or money values.
                found_dates = DATE_PATTERN.findall(sentence)
                found_money = MONEY_PATTERN.findall(sentence)

                candidates = (
                        [("date", value) for value in found_dates]
                        + [("amount", value) for value in found_money]
                )

                for attribute, value in candidates:
                    grouped[(topic, attribute)].append({
                        "topic": topic,
                        "attribute": attribute,
                        "value": value.strip(),
                        "document": item["document"],
                        "page": item["page"],
                        "passage": sentence.strip()
                    })

    conflicts = []

    for (topic, attribute), facts in grouped.items():
        normalized_values = {
            re.sub(r"\s+", " ", fact["value"])
            .strip()
            .casefold()
            for fact in facts
        }

        distinct_documents = {
            fact["document"] for fact in facts
        }

        if (
                len(normalized_values) > 1
                and len(distinct_documents) > 1
        ):
            conflicts.append({
                "topic": topic,
                "attribute": attribute,
                "statements": facts,
                "status": "Potential conflict"
            })

    return conflicts


# --------------------------------------------------
# 5. USER INTERFACE: UPLOAD
# --------------------------------------------------

st.sidebar.header("Document workspace")

uploaded_files = st.sidebar.file_uploader(
    "Upload PDF documents",
    type=["pdf"],
    accept_multiple_files=True
)

pages = []
errors = []

if uploaded_files:
    for uploaded_file in uploaded_files:
        try:
            pages.extend(
                extract_uploaded_pdf(uploaded_file)
            )
        except Exception as error:
            errors.append(
                f"{uploaded_file.name}: {error}"
            )

for error in errors:
    st.sidebar.error(error)

document_names = sorted({
    item["document"] for item in pages
})

total_pages = len({
    (item["document"], item["page"])
    for item in pages
})

conflicts = detect_conflicts(pages)

# --------------------------------------------------
# 6. DASHBOARD METRICS
# --------------------------------------------------

col1, col2, col3 = st.columns(3)

col1.metric(
    "PDF documents",
    len(document_names)
)

col2.metric(
    "Pages with extracted text",
    total_pages
)

col3.metric(
    "Potential conflicts",
    len(conflicts)
)

if not uploaded_files:
    st.warning(
        "Upload one or more text-based PDFs using "
        "the sidebar to begin."
    )
    st.stop()

if not pages:
    st.error(
        "No selectable PDF text was extracted. "
        "Scanned PDFs may require OCR."
    )
    st.stop()

# --------------------------------------------------
# 7. QUESTION ANSWERING
# --------------------------------------------------

st.header("1. Ask your documents")

question = st.text_input(
    "Enter your question",
    placeholder="What is the application deadline?"
)

if st.button("Find evidence", type="primary"):
    if not question.strip():
        st.warning("Please enter a question.")
    else:
        evidence = retrieve_evidence(question, pages)

        if not evidence:
            st.warning(
                "No matching evidence was found. "
                "This keyword-based search may miss "
                "relevant passages."
            )
        else:
            st.subheader("Retrieved evidence")

            if len(evidence) > 1:
                st.caption(
                    "Multiple passages are shown. "
                    "Review them for possible disagreements."
                )

            for index, item in enumerate(evidence, start=1):
                with st.expander(
                        f"Evidence {index}: "
                        f"{item['document']} — Page {item['page']}",
                        expanded=True
                ):
                    st.write(item["text"])
                    st.caption(
                        f"Word-overlap score: {item['score']}"
                    )

            st.info(
                "This prototype retrieves evidence rather "
                "than generating a free-form LLM answer."
            )

# --------------------------------------------------
# 8. CONFLICT REPORT
# --------------------------------------------------

st.divider()
st.header("2. Cross-document conflict scan")

if not conflicts:
    st.success(
        "No potential conflicts detected by the current rules."
    )
    st.caption(
        "This does not prove the documents are consistent. "
        "Only supported topics and formats are checked."
    )
else:
    st.warning(
        f"{len(conflicts)} potential conflict(s) detected. "
        "Neither statement is automatically treated as correct."
    )

    for index, conflict in enumerate(conflicts, start=1):
        with st.expander(
                f"{index}. {conflict['topic']} "
                f"({conflict['attribute']})",
                expanded=True
        ):
            for statement in conflict["statements"]:
                st.markdown(
                    f"**Source:** {statement['document']} "
                    f"— Page {statement['page']}"
                )
                st.write("Value:", statement["value"])
                st.write("Evidence:", statement["passage"])
                st.divider()

            st.caption(
                "Recommended action: verify document versions "
                "or consult the issuing authority."
            )

# --------------------------------------------------
# 9. PPT-FRIENDLY SUMMARY CHART
# --------------------------------------------------

st.divider()
st.header("3. Analysis summary for project reporting")

if conflicts:
    topic_counts = defaultdict(int)

    for conflict in conflicts:
        topic_counts[conflict["topic"]] += 1

    st.subheader("Potential conflicts by topic")

    st.bar_chart(
        dict(topic_counts),
        horizontal=True
    )
else:
    st.write(
        "No conflict chart is available because no potential "
        "conflicts were detected in this scan."
    )

st.caption(
    "Results are generated by deterministic Python rules. "
    "False positives and missed conflicts are possible."
)
