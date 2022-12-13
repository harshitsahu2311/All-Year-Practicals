name = input('Enter your name: ')
name.split()
c = 0
s = '"[@_!#$%^&*()<>?/\|}{~:]"'
for i in range(len(name)):
    if name[i] in s or name[i].isdigit():
        c += 1
if c == 0:
    print("your name is " + name)
else:
    try:
        raise Exception('Invalid character')
    except Exception as e:
        print('invalid character in your name', e)
