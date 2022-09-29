s =input("Enter the first string : ")
r =input("Enter the second string : ")
x =int(input("Enter the position from where you want to swap : "))
s1= s[:x]
r1= r[:x]

s2=r1+s[x:]
r2=s1+r[x:]
print("String 1 = ",s2)
print("String 2 = ",r2)
