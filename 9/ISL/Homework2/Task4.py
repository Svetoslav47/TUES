def input_with_validation(message_for_user, type_of_input):
    while (True):
        input_temp = input(message_for_user)
        # Check if input is a number
        if (input_temp.lstrip("-").replace(".", "", 1).isdigit()):
            if type_of_input == "int":
                input_temp = int(input_temp)
            elif type_of_input == "float":
                input_temp = float(input_temp)
            break
        else:
            print("Invalid input. Please enter a number.")
    return input_temp


coffee = ["Café Latte", "Caffe Americano",
          "Espresso", "Cappuccino", "Macchiato"]

customer_input = input_with_validation(
    "Please select a coffee option (0-4): ", "int")

if customer_input >= 0 and customer_input <= 4:
    print("You selected: ", coffee[customer_input])
else:
    print("Invalid number")

print("Have a good day")
