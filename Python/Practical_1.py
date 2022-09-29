a=int(input("Enter the coefficient of x^2 : "))
b=int(input("Enter the coefficient of x^1 : "))
c=int(input("Enter the coefficient of x^0 : "))

print("The Quadratic equation is : ",a,"x^2 +",b,"x^1 +",c)

d= pow(b,2)-(4*a*c)

x=(-b+pow(b,0.5))/(2*a)
y=(b+pow(b,0.5))/(2*a)
print("The roots of the Equation are :",x ," ",y)
