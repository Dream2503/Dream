import torch
from datasets import load_dataset
from transformers import BertForSequenceClassification, BertTokenizer, Trainer, TrainingArguments

dataset = load_dataset("stanfordnlp/imdb")
dataset["train"] = dataset["train"].select(range(1000))
dataset["test"] = dataset["test"].select(range(250))
print(dataset["train"][0])

tokenizer = BertTokenizer.from_pretrained("bert-base-uncased")
tokenized_datasets = dataset.map(lambda examples: tokenizer(examples["text"], padding="max_length", truncation=True), batched=True)

model = BertForSequenceClassification.from_pretrained("bert-base-uncased", num_labels=2)

training_args = TrainingArguments(
        output_dir='results', eval_strategy="epoch", learning_rate=2e-5, per_device_train_batch_size=16, per_device_eval_batch_size=16,
        num_train_epochs=3, weight_decay=0.01, logging_dir='./logs', logging_steps=100,
)

trainer = Trainer(model=model, args=training_args, train_dataset=tokenized_datasets["train"], eval_dataset=tokenized_datasets["test"], )
trainer.train()

results = trainer.evaluate()
print(f"Evaluation results: {results}")


def predict_sentiment(text):
    inputs = tokenizer(text, return_tensors="pt", truncation=True, padding=True)
    inputs = {k: v.to(model.device) for k, v in inputs.items()}  # only if you have GPU connected
    outputs = model(**inputs)
    logits = outputs.logits
    predicted_class = torch.argmax(logits, dim=1).item()
    return "positive" if predicted_class == 1 else "negative"


sample_text = "I absolutely loved this movie!"
print(predict_sentiment(sample_text))

model.save_pretrained("./fine-tuned-model")
tokenizer.save_pretrained("./fine-tuned-model")

model = BertForSequenceClassification.from_pretrained("./fine-tuned-model")
tokenizer = BertTokenizer.from_pretrained("./fine-tuned-model")
