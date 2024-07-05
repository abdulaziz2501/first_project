package boshlangich_darslar.for_operatorlari.masalalar2;

import java.util.Scanner;

public class masala2_5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("x= ");
        float x = input.nextFloat();
        System.out.print("n= ");
        int n = input.nextInt();
        float count=0;
        for(int i= 1;i<=n;i++){
            count+=Math.pow(-1,i-1)*(Math.pow(x,i)/i);
        }
        System.out.printf("%.1f ning %d dagi darajasi %.2f ga teng.", x, n, count);

    }
}
