import javax.xml.transform.stream.StreamSource;
import java.util.Scanner;

public class function {

    public int Prime(int n){
        /**Tub sonni aniqlab qaytarib beruvchi funksiya.
         */
        boolean number=true;
        for(int i=2; i<=n/2;i++){
            if(n%i==0)
                number=false;
        }
        if (number) {
            return n;
        }
        else {
            return 0;
        }
    }

    public void ToPrime(int n){
        /**
         * Kiritilgan songacha bo'lgan barcha tub sonnlarni chiqarib bereuvchi funksiya.
         *
         */
        boolean number;
        for(int i=2;i <=n;i++){
            number=true;
            for(int j=2; j<i;j++){
                if(i%j==0){
                    number=false;
                    break;
                }
            }
            if(number) {
                System.out.print(i);
                if (n == i)
                    System.out.print('.');
                else
                    System.out.print(", ");
            }
        }
    }
}
