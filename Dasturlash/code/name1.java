import java.lang.Math;
import java.util.Scanner;


public class name1 {

    static int yigindi(int a, int b) {
        int summa = 0;
        if(a>b){
            return -1;
        }
        else{
            for(int i = a; i<=b; i++){
                summa+=Math.pow(i, 2);
            }
            return summa;
        }
    }
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);
        System.out.print("a= ");
        int a=scanner.nextInt();
        System.out.print("\nb= ");
        int b=scanner.nextInt();
        System.out.println(yigindi(a, b));

    }
}
