package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int a=0;
        for (int i = 1; i <= 2*n-1; i+=2) {
            System.out.printf("%d ", a+=i);
            if(a==Math.pow(n, 2))
                break;
        }

    }
}