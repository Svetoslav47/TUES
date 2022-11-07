"""
Square of starts
"""

def main():
    side_length = None
    while(side_length == None):
        try:
            side_length = int(input("Enter side lenght:"))
            if(side_length <= 0):
                side_length = None
                print("Sorry but I have no idea how to draw squares with negative side length")
        except:
            print("This is not a number")
    #just to make the square more visible
    print("\n")
    draw_square(side_length)
    
def draw_square(side_length):
    for x in range(side_length):
        print("* " * side_length)

if __name__ == "__main__":
    main()