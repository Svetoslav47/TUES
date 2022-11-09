
k = 0
while True:
    k = input("Please select currency:")

    if k not in ["BGN", "Euro"]:
        print("error")
        continue
    else:
        break

n = int(input("Please enter the amount of the selected currency?"))

if k == "BGN":
    p = n / 1.95583
    n = str(n)
    p = str(p)
    print("The value of your " + n + " leva in euros is " + p)

if k == "Euro":
    r = n * 1.95583
    n = str(n)
    r = str(r)
    print("The value of your " + n + " euro in leva is " + r)
