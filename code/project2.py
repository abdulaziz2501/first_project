x=int(input("Enter a number x: "))
y=int(input("Enter a number y: "))

if(y==0 and x!=0):
    print(1)
elif(y!=0 and x==0):
    print(2)
elif(y==0 and x==0):
    print(0)
else:
    print(3)