def pyramid(n):
    k = n - 1
    for i in range(n):
        for j in range(0, k):
            print(end="  ")
        k -= 1
        for j in range(0, (2 * i) + 1):
            print("* ", end='')
        print("\r")


num = 5
pyramid(num)


def reverse(m):
    k = 0
    for i in range(m - 1, -1, -1):
        for j in range(k, 0, -1):
            print(end="  ")
        k += 1
        for j in range(0, (2 * i) + 1):
            print("* ", end='')
        print("\r")


num2 = 5
reverse(num2)
