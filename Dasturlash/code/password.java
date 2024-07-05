import java.util.Scanner;

public class password{
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        String name =input.nextLine();
        String surname =input.nextLine();
        System.out.printf("My name is %s. My surname is %s .", name, surname);
    }
}