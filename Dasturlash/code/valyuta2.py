print(" 1-USD\n 2-EUR\n 3-RUB\n 4-GBP\n 5-CHF\n 6-JPY\n 7-KZT\n 8-CAD\n 9-AED\n 10-UZB\n ")
USD=["", 1, 1.096, 0.014, 1.23, 1.099, 0.00778, 0.00217, 0.75198, 0.27, 0.00009]
EUR=["", 0.911, 1, 0.01298, 1.122, 1.002, 0.00709, 0.001, 0.68554, 0.24817, 0.0008]
RUB=["", 70.17,76.96, 1, 86.42, 77.12, 0.54, 0.15, 52.76, 19.10, 0.00621]
GBP=["", 0.81, 0.89, 0.011, 1, 0.89, 0.00631, 0.00176, 0.61, 0.22099, 0.00007]
CHF=["", 0.9096, 0.997, 0.01295, 1.12043, 1, 0.00707, 0.00197, 0.68406, 0.24763, 0.00008]
JPY=["",128.58, 141.033, 1.83, 158.371, 141.33, 1, 0.27859, 96.69, 35.00, 0.011]
KZT=["",458.27, 502.62, 6.52, 564.419, 503.669, 3.56, 1, 344.616, 124.752,  0.040]
CAD=["",1.32, 1.45, 0.01893, 1.63, 1.46, 0.01034, 0.00288, 1, 0.36195, 0.00012]
AED=["",3.67, 4.027, 0.0522, 4.5232,4.036, 0.02856, 0.00796, 2.76172, 1, 0.00033]
UZB=["", 11345.00, 12750.00, 180.00, 14450.00, 12950.00, 95.00, 30.00, 8434.24, 2978.51, 1]
choice1=int(input("pul birligingizni kiriting: "))
choice2=int(input("qaysi pul birligiga alamashtirmoqchisiz: "))
money=int(input("Enter a money: "))
while(True):
    if choice2==1:
        print(USD[choice1]*money, "dollar")
        break;
    if choice2==2:
        print(EUR[choice1]*money, "euro")
        break;
    if choice2==3:
        print(RUB[choice1]*money, "rubl")
        break;
    if choice2==4:
        print(GBP[choice1]*money, "funt-sterling")
        break;
    if choice2==5:
        print(CHF[choice1]*money, "frank")
        break;
    if choice2==6:
        print(JPY[choice1]*money, "yena")
        break;
    if choice2==7:
        print(KZT[choice1]*money, "tenge")
        break;
    if choice2==8:
        print(CAD[choice1]*money, "kanada dollar")
        break;
    if choice2==9:
        print(AED[choice1]*money, "dirham")
        break;
    if choice2==10:
        print(UZB[choice1]*money, "so'm")
        break;
    else:
        break;
