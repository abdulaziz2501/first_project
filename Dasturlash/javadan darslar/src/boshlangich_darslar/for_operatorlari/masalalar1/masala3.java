package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("sonni kiriting: ");
        int n=input.nextInt();
        float count=0;
        for(int i=0; i<n; i++){
                count+=Math.pow(-1, i)*(1+i*0.1);
        }
        System.out.printf("qiymati %.2f ga teng", count);
    }
}
