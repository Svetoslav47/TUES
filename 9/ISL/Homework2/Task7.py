with open("books.txt", "r") as f:
    for line in f:
        title = line.strip()
        code = title[0] + str(len(title))
        print(code)
