import re

number = input("Enter phone number: ")
pattern = r"^[189]\d{7}$"
if re.match(pattern, number):
    print("Valid")
else:
    print("Invalid")
