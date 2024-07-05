import math


print("1-misol\n")
n=int(input("sonni kiriting: "))
a=0
for i in range(n+1):
    a+=math.pow(n+i,3)
print(a)

print("2-misol\n")
m=int(input("sonni kiriting: "))
count=1
for i in range(1,m+1):
    count*=(i*0.1+1)
print(count)

print("3-misol\n")
s=int(input("sonni kiriting: "))
summ=0
for i in range(s):
    summ+=math.pow(-1, i)*(1+i*0.1)
print(summ)
count
print("4-misol\n")
k=int(input("sonni kiriting: "))
l=0
for i in range(1,k+1):
    q=i
    l+=1/q
print(l)
