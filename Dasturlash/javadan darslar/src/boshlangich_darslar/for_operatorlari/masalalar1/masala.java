package boshlangich_darslar.for_operatorlari.masalalar1;

import java.util.Scanner;

public class masala {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("sonni kiriting: ");
        int n=input.nextInt();
        float count=0, a;
        for(int i=1; i<=n;i++){
            a=i;
            count+=1/a;
        }
        System.out.printf("yigindi %.2f ga teng.", count);
    }
}
