names = ["John", "Oscar", "Jacob"]

with open("names.txt", "w") as file:
    for name in names:
        file.write(name + "\n")
        
with open("names.txt", "r") as file:
    print(file.read())