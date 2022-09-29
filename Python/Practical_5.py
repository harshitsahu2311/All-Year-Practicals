print("Press 1- Counts Character \nPress 2- Replace function \nPress 3- First Occurence Delete \nPress 4- Delete all occurence \n")
choice = int(input("Enter the choice : "))


def Counts(s,a):
    count= 0
    for i in range(0,len(s)):
        if s[i] == a:
            count+=1

    print(count)

def Replace(s,a):
    b = input("Enter the character which you want after replacement: ")
    d=""
    for i in range(0,len(s)):
        if s[i] == a:
            d+=b
        else:
            d+=s[i]
    print(d)
    
def Delete(s,z):
    e=""
    for i in range(0,len(s)):
        if s[i] == z:
            e=s[:i]+s[i+1:]
            break
    print(e)

def Deleteall(s,y):
    print(s.replace(y, ''))

s=input("Enter the String : ")

if choice == 1:
    a=input("Enter the character : ")
    Counts(s,a)
elif choice == 2: 
    z=input("Enter the character which you want to replace: ")
    Replace(s,z)
elif choice ==3:
    v=input("Enter the character whose first occurence will delete : ")
    Delete(s,v)
elif choice == 4:
    y=input("Enter the character whose all occurence will delete : ")
    Deleteall(s,y)
else:
    print("Wrong input")
