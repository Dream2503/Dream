import com.google.genai.Client;

import java.sql.*;
import java.util.*;
import java.util.regex.*;

class AIUtils {
    private static final int maxRetries = 5;
    private static final String APIKey = "AIzaSyAmas3XUYAesgTi_CDSh01Is5undGuhvbc";
    private static final String model = "gemini-3-flash-preview";
    private static final String pattern = "(\\d+)\\.\\s+(.*?)\\nA\\)\\s+(.*?)\\nB\\)\\s+(.*?)\\nC\\)\\s+(.*?)\\nD\\)\\s+(.*?)\\nAnswer:\\s*([A-D])";
    private static final String getTnameQuery = "SELECT tname FROM topics;";
    private static final String updateTnameQuery = "UPDATE topics SET tname = ? WHERE tname = ?";
    private static final String setTnameQuery = "INSERT INTO topics (tname) VALUES (?);";
    private static final String setQuestionsQuery = "INSERT INTO questions (qno, qtext, qopts, qans, tid) VALUES (?, ?, ?, ?, ?);";
    private static final String checkTopicPrompt = """
            Check if the New Topic exists within the list of Existing Topics.
            
            New Topic: %s
            Existing Topics: %s
            
            RULES:
            - Compare by meaning (e.g., JS = JavaScript)
            - If a match exists, return YES and the matched Existing Topic
            - Otherwise, return NO
            
            STRICT FORMAT:
            - If match: YES:<matched_topic>
            - If no match: NO
            - Do NOT add explanation
            - Do NOT use markdown
            - Keep plain text only
            """;
    private static final String generateQuestionPrompt = """
            Generate exactly 10 multiple choice questions on %s.
            
            STRICT FORMAT (follow EXACTLY, no deviation):
            
            1. Question text
            A) Option A
            B) Option B
            C) Option C
            D) Option D
            Answer: A
            
            RULES:
            - Do NOT use markdown
            - Do NOT add headings
            - Do NOT add answer key at bottom
            - Keep plain text only
            """;

    private static class Question {
        int number;
        String question;
        List<String> options;
        String answer;

        public Question(int number, String question, List<String> options, String answer) {
            this.number = number;
            this.question = question;
            this.options = options;
            this.answer = answer;
        }

        public String toString() {
            return "Q" + number + ": " + question + "\n" + "Options: " + options + "\n" + "Answer: " + answer + "\n";
        }
    }

    private static String decode(String text) {
        return text.replace("\\n", "\n").trim();
    }

    private static List<Question> parse(String rawText) {
        List<Question> questions = new ArrayList<>();
        Matcher matcher = Pattern.compile(pattern, Pattern.DOTALL).matcher(decode(rawText));

        while (matcher.find()) {
            questions.add(new Question(Integer.parseInt(matcher.group(1)), matcher.group(2).trim(), List.of(matcher.group(3).trim(),
                    matcher.group(4).trim(), matcher.group(5).trim(), matcher.group(6).trim()), matcher.group(7)));
        }
        return questions;
    }

    public static void generateQuestions(Connection connection, String topic) throws SQLException {
        List<String> names = new ArrayList<>();
        StringBuilder listBuilder = new StringBuilder();
        Client client = Client.builder().apiKey(APIKey).build();

        try (Statement statement = connection.createStatement(); ResultSet resultSet = statement.executeQuery(getTnameQuery)) {
            while (resultSet.next()) {
                names.add(resultSet.getString("tname"));
            }
        }
        for (String tname : names) {
            listBuilder.append("- ").append(tname).append("\n");
        }
        try {
            String response = client.models
                    .generateContent(model, checkTopicPrompt.formatted(topic, listBuilder.toString()), null)
                    .text()
                    .trim();

            System.out.println(response);

            if (response.toUpperCase().startsWith("YES:")) {
                String Matched = response.substring(4).trim();
                System.out.println(Matched);
                PreparedStatement ps = connection.prepareStatement(updateTnameQuery);
                ps.setString(1, topic);
                ps.setString(2, Matched);
                ps.executeUpdate();
                return;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }
        int tid = -1;

        try (PreparedStatement ps = connection.prepareStatement(setTnameQuery, Statement.RETURN_GENERATED_KEYS)) {
            ps.setString(1, topic);
            ps.executeUpdate();
            ResultSet resultSet = ps.getGeneratedKeys();

            if (resultSet.next()) {
                tid = resultSet.getInt(1);
            }
        }
        for (int i = 1; i <= maxRetries; i++) {
            try {
                List<Question> questions = parse(client.models.generateContent(model, generateQuestionPrompt.formatted(topic), null).text());

                try (PreparedStatement ps = connection.prepareStatement(setQuestionsQuery)) {
                    for (Question q : questions) {
                        ps.setInt(1, q.number);
                        ps.setString(2, q.question);
                        ps.setArray(3, connection.createArrayOf("text", q.options.toArray()));
                        ps.setString(4, q.answer);
                        ps.setInt(5, tid);
                        ps.addBatch();
                    }
                    ps.executeBatch();
                }
                break;

            } catch (Exception e) {
                System.out.println("Attempt " + i + " failed: " + e.getMessage());

                if (i == maxRetries) {
                    System.out.println("All retries failed. Cry quietly.");
                    break;
                }
                try {
                    Thread.sleep(2000 * i);
                } catch (InterruptedException ignored) {}
            }
        }
    }
}


class Main {
    static void main() {
        try {
            Class.forName("org.postgresql.Driver");
            String url = "jdbc:postgresql://aws-1-ap-southeast-2.pooler.supabase.com:5432/postgres";
            String user = "postgres.axatrnzhcuknelxyahcm";
            String password = "1p2o3i4u5y6t7r8e9w0q";
            Connection connection = DriverManager.getConnection(url, user, password);
            System.out.println("Connected successfully!");
            AIUtils.generateQuestions(connection, "Python basic");
            System.out.println("Done");
            connection.close();
        } catch (Exception e) {
            System.out.println("Connection failed!");
            e.printStackTrace();
        }
    }
}
