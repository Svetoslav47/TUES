'''
Currency exchange
'''

EURO_TO_LEV = 1.96

def main():
    currency = None
    while(currency == None):
        currency = input("Chose which currency you want to convert to the other. Lev or Euro\n").lower()

        if ((currency != "lev") and (currency != "euro")):
            print("this is not an option sorry")
            currency = None

    is_converting_from_euro = True
    if(currency == "lev"):
        is_converting_from_euro = False

    amount_of_money = None
    while(amount_of_money == None):
        try:
            amount_of_money = int(input("Enter the amount of money you have:"))
            if(amount_of_money < 0):
                print("Sorry but I cant solve your debth")
        except:
            print("This is not a number")
    
    after_converison = 0
    if(is_converting_from_euro):
        after_converison = amount_of_money * EURO_TO_LEV
    else:
        after_converison = amount_of_money / EURO_TO_LEV
    
    after_converison = round(after_converison, 2)

    if(currency[0] == "l"):
        print(f"This amounts to {after_converison} euro")
    else:
        print(f"This amounts to {after_converison} lev")
        


if __name__ == "__main__":
    main()