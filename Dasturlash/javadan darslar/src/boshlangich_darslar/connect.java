package boshlangich_darslar;

import java.sql.*;

public class connect {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/test_northwind";
            String username = "root";
            String password = "root";
            Connection conn = DriverManager.getConnection(url, username, password);
            String query = "SELECT * FROM products ORDER BY product_name";
            Statement pstmt=conn.createStatement();
            ResultSet rs = pstmt.executeQuery(query);
            System.out.print("Database Connected\n");
            while (rs.next()) {
                System.out.println(rs.getInt("product_id")+" -> " + rs.getString("product_name"));

            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}

