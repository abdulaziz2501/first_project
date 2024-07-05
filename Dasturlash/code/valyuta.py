print(" 1-USD\n 2-EUR\n 3-RUB\n 4-GBP\n 5-CHF\n 6-JPY\n 7-KZT\n 8-CAD\n 9-AED\n 10-UZB\n ")
UZB=["", 11345.00, 12750.00, 180.00, 14450.00, 12950.00, 95.00, 30.00, 8434.24, 2978.51, 1]
choice1=int(input("pul birligingizni kiriting: "))
choice2=int(input("qaysi pul birligiga alamashtirmoqchisiz: "))
money=int(input("Enter a money: "))
print(UZB[choice1]*money)
