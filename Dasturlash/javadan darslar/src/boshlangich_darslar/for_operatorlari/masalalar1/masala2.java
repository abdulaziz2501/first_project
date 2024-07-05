package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala2 {
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        System.out.print("sonni kiriting: ");
        int n=input.nextInt();
        float count=1;
        for(int i=1; i<=n; i++){
            count*=(i*0.1+1);
        }
        System.out.printf("ko'paytma %.2f ga teng.", count);
    }
}