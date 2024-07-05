package boshlangich_darslar.for_operatorlari.masalalar2;

import java.util.Scanner;

public class masala2_1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("n= ");
        int n = input.nextInt();
        double count=1, fact=1;
        for(int i =1; i<=n;i++){
            fact*=i;
            count+=1/fact;
        }
        System.out.printf("%d gacha bo'lgan yig'indi %.2f ga teg.", n, count);
    }
}
