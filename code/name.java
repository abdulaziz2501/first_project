import java.util.Scanner;
    
public class name{  
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);
        System.out.print("a= ");
        int a=scanner.nextInt();
        System.out.print("\nb= ");
        int b=scanner.nextInt();
        System.out.print("\nc= ");
        int c=scanner.nextInt();

        if(a<b && a<c){
            System.out.println(a);
            if(b>c){
                System.out.println(b);
            }
            else{
                System.out.println(c);
            }
        }
        else if(b<a && b<c){
            System.out.println(b);
            if(a>c){
                System.out.println(a);
            }
            else{
                System.out.println(c);
            }
        }
        else if(c<b && c<a){
            System.out.println(c);
            if(a>b){
                System.out.println(a);
            }
            else{
                System.out.println(b);
            }
        }

    }
}