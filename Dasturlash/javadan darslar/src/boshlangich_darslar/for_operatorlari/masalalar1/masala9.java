package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala9 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("n= ");
        int n = input.nextInt();
        float factorial=1;
        for(int i=1; i<=n; i++){
            factorial*=i;
        }
        System.out.printf("%d! %.0f ga teng.", n, factorial);
    }
}
