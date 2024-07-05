package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala1 {
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        System.out.print("sonni kiriting: ");
        int n= input.nextInt();
        int a=0;
        for(int i=0;i <=n;i++){
            a+=Math.pow(n+i, 3);
        }
        System.out.print(a);
    }
}
