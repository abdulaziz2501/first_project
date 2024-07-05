package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("n= ");
        int n = input.nextInt();
        System.out.print("a= ");
        float a = input.nextFloat();
        for(int i =1; i<n;i++){
            a*=a;
        }
        System.out.print(a);
    }
}
