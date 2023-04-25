import re

password = input("Enter password: ")
if re.match(r'^(?=.*[A-Z])(?=.*\d).+$', password):
    print("Password created")
else:
    print("Wrong format")
