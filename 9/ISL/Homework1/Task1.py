"""
Algorithm that swaps 2 variables
"""

def main():
    a = int(input("Enter A:"))
    b = int(input("Enter B:"))
    print(f"Before swap A = {a}; B = {b}")
    (a, b) = swap(a, b)
    print(f"After swap A = {a}; B = {b}")

def swap(a, b):
    temp = a
    a = b
    b = temp
    return (a, b)

if __name__ == "__main__":
    main()