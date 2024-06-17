import pandas as pd

# Replace 'file.csv' with your CSV file path
file_path = 'test.csv'

df = pd.read_csv(file_path)

print(df.columns)
print(df.shape)

df_single_correct = df[df["choice_type"] == "single"]
print(df_single_correct.columns)
print(df_single_correct.shape)
df_single_correct.to_csv("single_correct.csv", index = False)

