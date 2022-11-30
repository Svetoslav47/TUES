while True:
    arr = input("enter arra:\n").split(",")
    n = len(arr)
    arr = set(arr)
    for x in arr:
        if x.lstrip("-").isdigit():
            print("no")
            continue
    break

output = ""

for x in range(1, n+1):
    if str(x) not in arr:
        output += ("," + str(x))

print(output[1:])