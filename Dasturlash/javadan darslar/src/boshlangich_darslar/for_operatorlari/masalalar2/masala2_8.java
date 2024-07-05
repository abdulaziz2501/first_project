package boshlangich_darslar.for_operatorlari.masalalar2;

import java.util.Scanner;

public class masala2_8 {
    static int JuftX(int n){
        int a=0;
        int b=1;
        for(int i=0; i<n;i++){
            a+=2;
            b*=a;
        }
        return b;
    }

    static int ToqX(int n){
        int a=1;
        int b=1;
        for(int i=0; i<n;i++){
            b*=a;
            a+=2;
        }
        return b;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("x= ");
        float x = input.nextFloat();
        System.out.print("n= ");
        int n = input.nextInt();
        float count=1+x/2;
        for(int i=2;i<=n;i++){
            count+= 9;
        }
    }
}