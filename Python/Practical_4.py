test = input("Enter the test character: ")
# a)
if test.isalpha():
    print("The test character is a letter.")
elif test.isdigit():
    print("The test character is a numeric digit.")
elif test == ' ':
    print("The test character is whitespace.")
else:
    print("The test character is a special character.")

# b)
if test.isalpha():
    print("The test character is uppercase.") if test.isupper() else print("The test character is lowercase.")

# c)
out = {'0': 'zero', '1': 'one', '2': 'two', '3': 'three', '4': 'four', '5': 'five', '6': 'six', '7': 'seven',
       '8': 'eight', '9': 'nine', }
if test.isdigit():
    if test in out.keys():
        print(out[test])
