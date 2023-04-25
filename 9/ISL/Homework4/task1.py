import re

phone_number = input("Enter phone number: ")
formatted_number = re.sub(r'^00', '+', phone_number)
print("Formatted phone number:", formatted_number)
