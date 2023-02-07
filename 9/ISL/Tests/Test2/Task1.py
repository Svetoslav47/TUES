with open('text.txt') as file:
    text = file.read()
    blacklisted_characters = ['.', ',', '(', ')', '"', '\n']
    for character in blacklisted_characters:
        text = text.replace(character, ' ')

    # find the longest words
    words = text.split(' ')
    longest_words = []
    for word in words:
        if len(longest_words) == 0:
            longest_words.append(word)
        if len(word) > len(longest_words[0]):
            longest_words = [word]
        elif len(word) == len(longest_words[0]):
            longest_words.append(word)
        
    
    for word in longest_words:
        print(word)