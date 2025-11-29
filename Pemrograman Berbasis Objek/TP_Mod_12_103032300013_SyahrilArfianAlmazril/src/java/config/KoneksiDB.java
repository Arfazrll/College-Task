/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package config;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author User
 */

public class KoneksiDB {

    private static final String URL  = "jdbc:mysql://localhost:3306/TP12_Pratikkan?useSSL=false&serverTimezone=UTC";
    private static final String USER = "root"; 
    private static final String PASS = "root";     

    public static Connection getConnection() throws SQLException {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException ex) {
            throw new SQLException("Driver MySQL tidak ditemukan", ex);
        }

        return DriverManager.getConnection(URL, USER, PASS);
    }
}