package boshlangich_darslar.for_operatorlari.masalalar2;

import java.util.Scanner;

public class masala2_3 {
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
        for(int i=1; i<=n;i++){
            count+=Math.pow(-1,i-1)*(Math.pow(x,2*i-1)/factarial(2*i-1));
        }
        System.out.printf("%d ning %d darajadagi qiymati %.2f ga teng.", x, n, count);


    }
}
