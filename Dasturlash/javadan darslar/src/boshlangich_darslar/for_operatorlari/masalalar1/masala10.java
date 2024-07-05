package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala10 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("n= ");
        int n = input.nextInt();
        float factorial = 1;
        int count=0;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            count+=factorial;
        }
        System.out.printf("%d! lar yig'indisi %d ga teng.", n, count);
    }

}
