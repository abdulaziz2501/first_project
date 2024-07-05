package boshlangich_darslar.for_operatorlari;

import java.util.Scanner;

public class fibonachi_recursiya {
    static long a=0,a1=1, a2=0;
    static void Fibonachi(long n){
        if(n>0){
            a2=a+a1;
            a=a1;
            a1=a2;
            Fibonachi(n-1);
        }

    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("n= ");
        long n = input.nextLong();
        Fibonachi(n);
        System.out.print(a2);
    }
}
