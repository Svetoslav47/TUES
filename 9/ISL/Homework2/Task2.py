def celsius_to_fahrenheit(celsius):
    fahrenheit = (celsius * 9/5) + 32
    fahrenheit = round(fahrenheit, 2)
    return fahrenheit


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


def main():
    input_temp = input_with_validation(
        "Enter temperature in Celsius: ", "float")

    temperature_celsius = input_temp
    temperature_fahrenheit = celsius_to_fahrenheit(temperature_celsius)
    print("Temperature in Celsius: ", temperature_celsius)
    print("Temperature in Fahrenheit: ", temperature_fahrenheit)


if (__name__ == "__main__"):
    main()
