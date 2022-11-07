"""
Find area and perimeter of a shape
"""

PI = 3.14159265


def main():
    perimeter = 0
    area = 0

    shape = None
    while shape == None:
        shape = input(
            "Chose shape. Triangle, Square, Rectangle or a Circle:\n").lower()
        if shape not in ["triangle", "square", "circle", "rectangle"]:
            print("Thats not an option")
            shape = None

    if shape == "triangle":
        (perimeter, area) = calculate_for_triangle()

    elif shape == "square":
        (perimeter, area) = calculate_for_square()

    elif shape == "rectangle":
        (perimeter, area) = calculate_for_rectangle()

    else:
        (perimeter, area) = calculate_for_circle()

    print(f"The are of the {shape} is {area} and the perimeter is {perimeter}")


def calculate_for_triangle():
    side_a = input_with_catch(
        "Enter side a (its important that this is the side that you have the height for):")
    side_b = input_with_catch("Enter side b:")
    side_c = input_with_catch("Enter side c:")
    height = input_with_catch("Enter height:")

    perimeter = side_a + side_b + side_c
    area = (side_a * height) / 2
    return (perimeter, area)


def calculate_for_rectangle():
    width = input_with_catch("Enter width:")
    length = input_with_catch("Enter length:")

    perimeter = (2 * width) + (2 * length)
    area = width * length
    return (perimeter, area)


def calculate_for_square():
    side_length = input_with_catch("Enter side lenght:")

    perimeter = 4 * side_length
    area = side_length ** 2
    return (perimeter, area)


def calculate_for_circle():
    radius = input_with_catch("Enter the radius:")

    perimeter = PI * radius ** 2
    area = PI * radius * 2
    return (perimeter, area)


def input_with_catch(message_for_input,
                     message_for_catch="This is not a number"):
    input_number = None
    while input_number == None:
        try:
            input_number = int(input(message_for_input))
            if input_number <= 0:
                input_number = None
                print("It must be greater than 0")
        except ValueError:
            print(message_for_catch)

    return input_number


if __name__ == "__main__":
    main()
