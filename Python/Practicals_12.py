t1 = (1, 2, 5, 7, 9, 2, 4, 6, 8, 10)
# a)
print('The first half of the tuple t1 is:')
for i in range(0, int(len(t1) / 2)):
    print(t1[i], end=' ')
print('\nThe second half of the tuple t1 is:')
for i in range(int(len(t1) / 2), int(len(t1))):
    print(t1[i], end=' ')

# b)
print("\nAll the even numbers in t1 are: ")
test = []
for i in t1:
    if i % 2 == 0:
        test.append(i)
test_tup = tuple(test)
print(test_tup)

# c)
t2 = (11, 13, 15)
conc = t1 + t2
print(type(conc))
print('The concatenation of t2 is: ' + str(conc))

# d)
values = list(conc)
print('The maximum value in the concatenated tuple is: ' + str(max(values)))
print('The minimum value in the concatenated tuple is: ' + str(min(values)))
