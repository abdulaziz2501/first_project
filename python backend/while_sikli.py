import random
# # 1- vazifa
# i=0
# while i!=5:
#     i += 1
#     print(str(i)*i)
#
# # 2-vazifa
# n=int(input("Sonni kiriting: "))
# count=0
# while n>0:
#     count+=n%10
#     n//=10
# print("Raqamlar yig'indisi: ", count)
#
# # 3-vazifa
# i=1
# count=0
# while i<=100:
#     count+=i
#     i+=2
# print(count)
#
# # 4-vazifa
# lst=[45,5,89,64,389,3156,684,648]
# max1 = lst[0]
# max2 = 0
# i = 1
# while i < len(lst):
#     if lst[i] > max1:
#         max2 = max1
#         max1 = lst[i]
#     elif lst[i] < max1:
#         if lst[i] > max2:
#             max2 = lst[i]
#     i += 1
# print(max2)
#
# # 5-vazifa
# a=random.choice(range(1,100))
# while 1:
#     n=int(input("1 dan 100 gacha son kiriting: "))
#     if n<a:
#         print("Juda past!")
#     elif n>a:
#         print("Juda baland!")
#     else:
#         print("To'g'ri topdiz")
#         break