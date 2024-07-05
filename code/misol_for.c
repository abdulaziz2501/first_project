#include <stdio.h>

int main() {
          
    printf("1-misol\n");
    int n, a=0;
    printf("sonni kiriting: ");
    scanf(%d, &n);
    for(int i=0;i <=n;i++){
        a+=pow(n+i, 3);
    }
    printfln(a);
    printf("2-misol\n");
    printf("sonni kiriting: ");
    int m=input.nextInt();
    float count=1;
    for(int i=1; i<=m; i++){
        count*=(i*0.1+1);
    }
    printff("ko'paytma %.2f ga teng.\n", count);
    printf("3-misol\n");
    printf("sonni kiriting: ");
    int s=input.nextInt();
    float summ=0;
    for(int i=0; i<n; i++){
        summ+=Math.pow(-1, i)*(1+i*0.1);
    }
    printff("qiymati %.2f ga teng\n", summ);
    printf("4-misol\n");
    printf("sonni kiriting: ");
    int k=input.nextInt();
    float l=0, q;
    for(int i=1; i<=k;i++){
        q=i;
        l+=1/q;
    }
    printff("yigindi %.2f ga teng.", l);
    

    return 0;
}
