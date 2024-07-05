package boshlangich_darslar.for_operatorlari;

import java.util.Scanner;
public class for_operatori {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("sonni kiriting: ");
        int a = input.nextInt();
        int natija=0;
        for (int i = 1; i <=a; i++) {
            System.out.print(i);
            if(i==a)
                System.out.print('=');
            else
                System.out.print('+');
            natija+=i;
        }
        System.out.print(natija);
        System.out.print("\n");
    }
}

