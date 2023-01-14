while True:
    pin = input("Please enter your PIN code: ")
    if pin.isdigit():
        if len(pin) == 4:
            print("PIN code is created.")
            break
        else:
            print("PIN should be 4 digits long.")
    else:
        print("Please enter a number.")
