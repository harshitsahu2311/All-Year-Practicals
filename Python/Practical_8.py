# a)
list = []
n = int(input('enter the length of list \n'))
for j in range(0, n):
    val = input('enter the values: ')
    list.append(val)
cubes = []
for i in list:
    if str(i).isdigit():
        if int(i) % 2 == 0:
            i = int(int(i) ** 3)
            cubes.append(i)
print('The cubed values of all the even digits in the given string using for loop are: ')
print(cubes)

# b)
list_comp = [int(cube)**3 for cube in list if cube.isdigit() and int(cube) % 2 == 0]
print('The cubed values of all the even digits in the given string using list comprehension are: ')
print(list_comp)
