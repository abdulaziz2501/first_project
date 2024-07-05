#include<stdio.h>


int main(){
    int a,b;
    int count1=0,count2=0,count3=0,c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    a+=1;
    c=a;
    for(int i=a;i<b;i++){
        count1+=i;
    }
    printf("for:      %d\n", count1);
    while(a<b){
        count2+=a;
        a++;
    }
    printf("while:    %d\n", count2);
    do{
        count3+=c;
        c++;
    }while(c<b);
    printf("do while: %d\n", count2);
    return 0;
}