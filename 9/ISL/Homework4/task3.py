import re

product_id = input("Enter product ID: ")
if re.match(r'^[A-Z]{2}\d{2}$', product_id):
    print("Searching")
else:
    print("Wrong format")
