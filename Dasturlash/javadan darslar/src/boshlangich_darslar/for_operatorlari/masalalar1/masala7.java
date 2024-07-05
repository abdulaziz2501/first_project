package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("a= ");
        int a = input.nextInt();
        System.out.print("n= ");
        int n = input.nextInt();
        float count=0;
        for(int i=0; i<=n;i++){
            count+=Math.pow(a, i);
        }
        System.out.printf("%.0f ", count);
    }
}
