package boshlangich_darslar.massivlar;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class masala {

    public static int[] sort(int[] n) {
        int temp = 0;
        for (int i = 0; i < n.length; i++) {
            for(int j=i+1;j<n.length;j++){
                if(n[i]>n[j]){
                    temp=n[i];
                    n[i]=n[j];
                    n[j]=temp;
                }
            }
        }
        return n;
    }
    public static int[] ReverseSort(int[] n) {
        int temp = 0;
        for (int i = 0; i < n.length; i++) {
            for(int j=i+1;j<n.length;j++){
                if(n[i]<n[j]){
                    temp=n[i];
                    n[i]=n[j];
                    n[j]=temp;
                }
            }
        }
        return n;
    }
    public static int[] Rand(int[] n){
        Random x = new Random();
        for(int i=0; i<n.length;i++){
            n[i]=x.nextInt(101);
        }
        return n;
    }

    public static void masala1(int n) {
        int[] a = new int[n];
        int b = 0;
        for (int i = 1; i < n * 2; i += 2) {
            a[b] = i;
            b++;
        }
        System.out.print(Arrays.toString(a) + "\n");
    }

    public static void masala2(int n) {
        int[] a = new int[n];
        int b = 2;
        for (int i = 0; i < n; i++) {
            a[i] = b;
            b += b;
        }
        System.out.print(Arrays.toString(a) + "\n");
    }

    public static void masala3(int n, int a, int b) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = a;
            a += b;
        }
        System.out.print(Arrays.toString(arr) + "\n");
    }

    public static void masala4(int n, long a, int b) {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = a;
            a *= b;
        }
        System.out.print(Arrays.toString(arr) + "\n");
    }

    public static void masala5(int n) {
        int[] arr = new int[n];
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 2; i < n; i++) {
            int a = 0;
            a += arr[i - 2] + arr[i - 1];
            arr[i] = a;
        }
        System.out.print(Arrays.toString(arr) + "\n");
    }
    public static void masala6(int n, int a, int b) {
        int[] arr = new int[n];
        arr[0] = a;
        arr[1] = b;
        for (int i = 2; i < n; i++) {
            int c = 0;
            for (int j = 0; j < i; j++) {
                c += arr[j];
            }
            arr[i] = c;
        }
        System.out.print(Arrays.toString(arr));
    }
    public static void masala7(int n) {
        Random x = new Random();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = x.nextInt(100 + 1);
        }
        System.out.print(Arrays.toString(arr) + "\n");
        for (int i = n - 1; i >= 0; i--) {
            System.out.print(arr[i] + " ");
        }

    }
    public static void masala8(int n) {
        Random x = new Random();
        int count = 0;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = x.nextInt(100 + 1);
        }
        System.out.print(Arrays.toString(arr) + "\n");
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] % 2 == 0) {
                System.out.print(arr[i] + " ");
                count++;
            }
        }
        System.out.print("\n" + count);

    }
    public static void masala9 ( int n){
        int[] arr = new int[n];
        System.out.print(Arrays.toString(Rand(arr)) + "\n");
        System.out.print(Arrays.toString(sort(arr))+'\n');
        System.out.print(Arrays.toString(ReverseSort(arr)));

    }
    public static void masala10 ( int n){
        int[] arr = new int[n];
        System.out.print(Arrays.toString(Rand(arr)) + "\n");
        System.out.print("Juftlar :");
        for(int i=0; i<arr.length;i++){
            if(arr[i]%2==0){
                System.out.print(i+" ");
            }
        }
        System.out.print("\nToqlar :");
        for (int j=arr.length-1;j>=0;j--){
            if(arr[j]%2==1){
                System.out.print(j+" ");
            }
        }

    }

    public static void masala11(int[] n, int k){
        for(int i=k-1; i>=0; i--){
            System.out.print(n[i]+" ");
        }
    }
    public static void masala12(int[] n){
        for(int i=1; i<=n.length;i+=2){
            System.out.printf("%d - index = %d elementiga\n", i+1, n[i]);
        }
    }
    public static void masala13(int[] n){
        for(int i=n.length-1; i>=0;i-=2){
            System.out.printf("%d - index = %d elementiga\n", i+1, n[i]);
        }
    }
    public static void masala14(int[] arr){
        for(int i =1;i<arr.length;i+=2){
            System.out.print(arr[i]+" ");
        }
        System.out.print("\n");
        for(int i =0;i<arr.length;i+=2){
            System.out.print(arr[i]+" ");
        }
    }
    public static void masala15(int[] arr){
        for(int i =0;i<arr.length;i+=2){
            System.out.print(arr[i]+" ");
        }
        System.out.print("\n");
        for(int i =1;i<arr.length;i+=2){
            System.out.print(arr[i]+" ");
        }
    }
    public static void masala16(int[] n){
        int arr[] = new int[n.length];
        int a=0, b=n.length/2;
        for(int i=0;i<=b;i++){
            arr[a]=n[i];
            a+=2;
            if (a>n.length-1){
                break;
            }
        }
        a=1;
        for(int i=n.length-1;i>=b;i--){
            arr[a]=n[i];
            a+=2;
            if (a>n.length-1){
                break;
            }
        }
        System.out.print(Arrays.toString(arr));
    }

    public static void main (String[]args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = input.nextInt();
        System.out.print("Enter a: ");
        int a = input.nextInt();
        System.out.print("Enter b: ");
        int b = input.nextInt();
        int[] arr=new int[n];
        System.out.print(Arrays.toString(Rand(arr))+"\n");

//        masala1(n);
//        masala2(n);
//        masala3(n,a,b);
//        masala4(n,a,b);
//        masala5(n);
//        masala6(n, a, b);
//        masala7(n);
//        masala8(n);
//        masala9(n);
//        masala10(n);
//        masala11(arr, b);
//        masala12(arr);
//        masala13(arr);
//        masala14(arr);
//        masala15(arr);
        masala16(arr);
    }

}
