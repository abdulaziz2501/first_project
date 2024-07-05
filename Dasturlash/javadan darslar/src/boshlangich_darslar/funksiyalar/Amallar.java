package boshlangich_darslar.funksiyalar;

import java.util.Scanner;

public class Amallar {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        function funksiya = new function();
        int n=input.nextInt();
        System.out.print(funksiya.Prime(n));
        funksiya.ToPrime(18);
    }
}