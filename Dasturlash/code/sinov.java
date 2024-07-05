import javax.swing.JOptionPane;

public class sinov {
    public static void main(String[] args) {
      
        String name =JOptionPane.showInputDialog("Ismingizni kiriting: ");
        int age=Integer.parseInt(JOptionPane.showInputDialog("Yoshingizni kiriting: "));
        int age1=2023-age;
        JOptionPane.showMessageDialog(null, "Salom "+name+"\nSizning yoshingiz "+age+" da va siz "+age1+" yilda tug'ilgansiz.");

    } 
}
 