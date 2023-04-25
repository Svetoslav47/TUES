import re

word = input("Enter a word: ")
if re.match(r'^m\w{2}e$', word):
    print("Match")
else:
    print("No match")
