"""
Find area and perimeter of a shape
"""
PI = 3.14159265

def main():
    perimeter = 0
    area = 0

    shape = None
    while(shape == None):
        shape = input("Chose shape. Triangle, Square, Rectangle or a Circle:\n").lower()
        if(shape not in ["triangle", "square", "circle", "rectangle"]):
            print("Thats not an option")
            shape = None
    
    if(shape == "triangle"):
        print("📐")
    elif(shape == "square"):
        (perimeter, area) = calculate_for_square()
    elif(shape == "rectangle"):
        pass
    else:
        (perimeter, area) = calculate_for_circle()

    print(f"The are of the {shape} is {area} and the perimeter is {perimeter}")

def calculate_for_triangle():
    pass

def calculate_for_square():
    side_length = None
    while(side_length == None):
        try:
            side_length = int(input("Enter side lenght:"))
            if(side_length <= 0):
                side_length = None
                print("It must be greater than 0")
        except ValueError:
            print("This is not a number")
    
    perimeter = 4 * side_length
    area = side_length ** 2
    print(perimeter, area)
    return (perimeter, area)

def calculate_for_circle():
    radius = None
    while(radius == None):
        try:
            radius = int(input("Enter the radius:"))
            if(radius <= 0):
                radius = None
                print("It must be greater than 0")
        except ValueError:
            print("This is not a number")
    perimeter = PI * radius ** 2
    area = PI * radius * 2
    print(perimeter, area)
    return (perimeter, area)

if __name__ == "__main__":
    main()