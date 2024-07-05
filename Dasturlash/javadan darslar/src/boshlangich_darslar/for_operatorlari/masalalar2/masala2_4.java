package boshlangich_darslar.for_operatorlari.masalalar2;

import java.util.Scanner;

public class masala2_4 {
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
        float x = input.nextFloat();
        System.out.print("n= ");
        int n = input.nextInt();
        float count=1;
        for(int i=1; i<=n;i++){
            count+=Math.pow(-1,i)*(Math.pow(x,2*i)/factarial(2*i));
        }
        System.out.printf("%.1f ning %d darajadagi qiymati %.2f ga teng.", x, n, count);


    }
}
