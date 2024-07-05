package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala8 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("a= ");
        int a = input.nextInt();
        System.out.print("n= ");
        int n = input.nextInt();
        float count=1;
        for(int i=1; i<=n; i++){
            count+=Math.pow(-1, i)*Math.pow(a, i);
        }
        System.out.printf("%.0f ", count);
    }
}