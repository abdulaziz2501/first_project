o=["","o'n", "yigirma", "o'ttiz", "qirq"]
b=["", "bir", "ikki","uch","to'rt", "besh", "olti", "yetti", "sakkiz","to'qqiz"]

a=int(input("Enter number a: "))

if(a>=10 and a<=40):
    c=a//10
    d=a%10
    print(o[c], b[d], "- o'quv vazifasi")
else:
    print("bunday o'quv vazigfasi yo'q")