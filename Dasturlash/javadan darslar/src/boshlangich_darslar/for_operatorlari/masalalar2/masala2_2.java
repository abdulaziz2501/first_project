package boshlangich_darslar.for_operatorlari.masalalar2;

import java.util.Scanner;

public class masala2_2 {
    static int factarial(int n){
        int fact=1;
        for(int i =1; i <=n;i++){
            fact*=i;
        }
        return fact;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("x= ");
        int x = input.nextInt();
        System.out.print("n= ");
        int n = input.nextInt();
        float count=0;
        for(int i=0; i<=n;i++){
            count+=Math.pow(x,i)/factarial(i);
        }
        System.out.printf("%d ning %d darajadagi qiymati %.2f ga teng.", x, n, count);
    }
}