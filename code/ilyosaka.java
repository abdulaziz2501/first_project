import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class ilyosaka {
    public static void main(String[] args) {
        Random random=new Random();
        Scanner scanner =new Scanner(System.in);
        System.out.print("n= ");
        int n=scanner.nextInt();
        int arr[] = new int[n];
        for(int i =0; i<n;i++){
            arr[i]=random.nextInt(100);
        }
        System.out.print(Arrays.toString(arr)+"\n");
        int a=arr[0];

        for(int i =1; i<arr.length;i++){
            arr[i-1]=arr[i];
        }
        arr[n-1]=a;
        System.out.print(Arrays.toString(arr)+"\n");
    }
}
