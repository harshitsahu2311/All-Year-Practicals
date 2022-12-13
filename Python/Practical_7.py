def indices(first, second):
    for i in second:
        if i in first:
            print(str1.index(i))
        if i not in first:
            print(-1)


str1 = input("Enter the first string:\n")
str2 = input("Enter the second string:\n")
indices(str1, str2)
