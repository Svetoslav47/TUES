with open('text.txt') as file:
    text = file.read()
    blacklisted_characters = ['.', ',', '(', ')', '"', '\n']
    for character in blacklisted_characters:
        text = text.replace(character, ' ')

    # find the longest words
    words = text.split(' ')
    words_with_7_letters = []
    for word in words:
        if len(word) == 7:
            words_with_7_letters.append(word)
    
    for word in words_with_7_letters:
        print(word)