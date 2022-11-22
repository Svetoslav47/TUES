spam = ""
p = True
while p is True:
    spam = input("enter a list of numbers only or simbols only ")
    _list = spam.split(",")
    intowe = False
    charowe = False
    for i in range(len(_list)):
        try:
            _list[i] = _list[i].isdigit()
            intowe = True
        except ValueError:
            charowe = True
    if intowe is True and charowe is True:
        p = True
        print("there are simbols and numbers , please choose one !!!!")
    else:
        p = False

_list = list(set(_list))
for x in _list:
    print(x)
