def input_with_validation(message_for_user, type_of_input):
    while True:
        input_temp = input(message_for_user)
        # Check if input is a number
        if input_temp.lstrip("-").replace(".", "", 1).isdigit():
            if type_of_input == "int":
                input_temp = int(input_temp)
            elif type_of_input == "float":
                input_temp = float(input_temp)
            break
        else:
            print("Invalid input. Please enter a number.")
    return input_temp


with open("task5_input.txt", "r") as file:
    n = input_with_validation("Enter day number (starting from 0): ", "int")
    lines = file.readlines()
    line_to_print = lines[n]
    line_to_print = line_to_print[:-1]
    print(f"On day {n} Tom did {line_to_print} pull-ups.")
