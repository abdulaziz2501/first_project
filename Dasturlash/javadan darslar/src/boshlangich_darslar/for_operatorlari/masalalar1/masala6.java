package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("a= ");
        int a = input.nextInt();
        System.out.print("b= ");
        int b = input.nextInt();

        for(int i=1; i<=b;i++){
            System.out.printf("%.0f ", Math.pow(a, i));
        }

    }

}
