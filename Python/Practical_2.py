# Prime Program
n =int(input("Enter number: "))
s=2
while(s<n):
    if(n%s == 0):
        break
    s+=1
if(n==s):
    print("Prime Number\n")
else:
    print("Not Prime Number\n")
        

# Print Prime Numbers till n
print("Prime numbers till",n)       
for i in range(2,n+1):
    m=2
    while (m<i):
        if (i%m==0):
            break
        m+=1
    if(m==i):
        print(i)
                

# Print n prime numbers
print("\nNumber of Prime numbers = ",n)        
count =0
a=2
while (count < n):
    b=2
    while(b<a):
        if (a%b==0):
            break
        b+=1
    if(a==b):
        print(a)
        count+=1
    a+=1

