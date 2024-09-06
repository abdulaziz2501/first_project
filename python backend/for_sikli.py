# # 1-vazifa
# k=int(input("k ni kiriting: "))
# n=int(input("n ni kiriting: "))
# for i in range(n):
#     print(k, end=' ')
#
# # 2-vazifa
# n=int(input("n ni kiriting: "))
# count=0
# for i in range(1, n):
#     if i%2:
#         count+=i
# print(count)
#
# # 3-vazifa
# n=int(input("n ni kiriting: "))
# count=0
# for i in range(1, n):
#     if i%3==0 and i%9!=0:
#         count+=i
# print(count)
#
# # 4-vazifa
# n=int(input("n ni kiriting: "))
# count=0
# for i in range(1, n):
#     count+=i*i
# print(count)
#
# # 5-vazifa
# txt=input("So'zni kiriting")
# new_txt=''
# n=int(input(f"1 dan {len(txt)} gacha son kiriting: "))
# if n<=len(txt):
#     for i in range(len(txt)):
#         if i !=n-1:
#             new_txt+=txt[i]
#     print(txt, new_txt)
#
# # 6-vazifa
# narx=int(input("Butun narxni kiritng"))
# if narx>=100000:
#     narx-=narx*0.1
#     print(f"sizda 10% skidka bor va {narx} so'm to'laysiz")
# elif narx>=50000:
#     narx-=narx*0.05
#     print(f"sizda 5% skidka bor va {narx} so'm to'laysiz")
# else:
#     print(f"sizda skidka yo'q va {narx} so'm to'laysiz")
#
# # 7-vazifa
# a = int(input("A ni kiriting (A < B): "))
# b = int(input("B ni kiriting: "))
# count = 0
# for i in range(b-1, a, -1):
#     print(i)
#     count += 1
# print(f"Sonlar soni: {count}")
# #
# # 8-vazifa
# narx=int(input("1 kg uchun narxni kiriting: "))
# for i in range(1,11):
#     print(f"{i} kg uchun narx {narx*i} ga teng. ")
#
# # 9-vazifa
# narx=int(input("1 kg uchun narxni kiriting: "))
# for i in range(1,11):
#     print(f"{i*0.1:.1f} kg uchun narx {narx*i*0.1} ga teng. ")
#
# # 10 -vazifa
# a = int(input("A ni kiriting (A < B): "))
# b = int(input("B ni kiriting: "))
# kvadrat = 1
# summa = 0
# for i in range(a, b+1):
#     kvadrat = i * i
#     summa += kvadrat
#     print(f"{i}-> {kvadrat}")
# print(summa)
#
# # 11-vazifa
# a=int(input("a ni kiriting: "))
# n=int(input("n ni kiriting: "))
# for i in range(1, n+1):
#     daraja=a**i
#     print(f"{a} ning {i}-darajasi: {daraja}")
#
# # 12-vazifa
# a=int(input("a ni kiriting: "))
# n=int(input("n ni kiriting: "))
# for i in range(1, n+1):
#     kopaytma=a*i
#     print(f"{a} * {i} = {kopaytma}")