package qayta_topshiriq;
import java.util.Scanner;

public class misol_for {
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        System.out.print("1-misol\n");
        System.out.print("sonni kiriting: ");
        int n= input.nextInt();
        int a=0;
        for(int i=0;i <=n;i++){
            a+=Math.pow(n+i, 3);
        }
        System.out.println(a);
        System.out.print("2-misol\n");
        System.out.print("sonni kiriting: ");
        int m=input.nextInt();
        float count=1;
        for(int i=1; i<=m; i++){
            count*=(i*0.1+1);
        }
        System.out.printf("ko'paytma %.2f ga teng.\n", count);
        System.out.print("3-misol\n");
        System.out.print("sonni kiriting: ");
        int s=input.nextInt();
        float summ=0;
        for(int i=0; i<n; i++){
            summ+=Math.pow(-1, i)*(1+i*0.1);
        }
        System.out.printf("qiymati %.2f ga teng\n", summ);
        System.out.print("4-misol\n");
        System.out.print("sonni kiriting: ");
        int k=input.nextInt();
        float l=0, q;
        for(int i=1; i<=k;i++){
            q=i;
            l+=1/q;
        }
        System.out.printf("yigindi %.2f ga teng.", l);
    }
}
