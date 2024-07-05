o=["","o'n", "yigirma", "o'ttiz", "qirq", "ellik", "oltmish", "yetmish", "sakson","to'qson"]
b=["", "bir", "ikki","uch","to'rt", "besh", "olti", "yetti", "sakkiz","to'qqiz"]
m=["", "yuz", "ming"]

a=int(input("Enter number a: "))

if(a>=100 and a<1000):
    e=a//100
    c=a%100//10
    d=a%10
    print(b[e], m[1], o[c], b[d],)
else:
    print("bunday son ro'yxatda yo'q")