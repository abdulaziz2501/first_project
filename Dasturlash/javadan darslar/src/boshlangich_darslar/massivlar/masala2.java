package boshlangich_darslar.massivlar;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class masala2 {
    public static int[] Rand(int[] n){
        Random x = new Random();
        for(int i=0; i<n.length;i++){
            n[i]=x.nextInt(10);
        }
        return n;
    }
    public static void masala1(int arr[], int a){
        for(int i=0; i<arr.length;i++){
            if(a>arr[i]){
                System.out.println(arr[i]);
                break;
            }
        }
    }
    public static void masala2(int arr[], int a){
        for(int i=0; i<arr.length;i++){
            if(arr[i]<a && arr[i]>1){
                System.out.print(" "+i);
            }
        }
    }
    public static void masala3(int arr[], int k, int l){
        int count =0;
        for(int i=0; i<arr.length; i++){
            if(k>=1 && k<=l && k<=arr.length-1){
                count+=arr[i];
            }
        }
        System.out.println("\n"+count);
    }
    public static void masala4(int arr[], int k, int l){
        float count =0;
        int a=0;
        for(int i=0; i<arr.length; i++){
            if(k>=1 && k<=l && k<=arr.length-1){
                count+=arr[i];
                a++;
            }
        }
        System.out.println("\n"+count/a);
    }
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);
        System.out.print("n=");
        int n = scanner.nextInt();
        System.out.print("k=");
        int k = scanner.nextInt();
        System.out.print("l=");
        int l = scanner.nextInt();
        int arr[]=new int[n];
        System.out.print(Arrays.toString(Rand(arr))+"\n");
        masala4(arr, k, l);
    }
}
