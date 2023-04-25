import re

text = input("Enter text: ")
hashtags = re.findall(r'#\w+', text)
for hashtag in hashtags:
    print(hashtag)
