/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package controller;

import config.KoneksiDB;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author User
 */
@WebServlet(name = "DBTestServlet", urlPatterns = {"/testKoneksi"})
public class DBTestServlet extends HttpServlet {

    /**
     *
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html;charset=UTF-8");

        try (PrintWriter out = response.getWriter()) {

            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head><title>Test JDBC</title></head>");
            out.println("<body>");

            try (Connection conn = KoneksiDB.getConnection()) {
                out.println("<p>Koneksi JDBC ke database TP12_Pratikkan <b>BERHASIL</b>.</p>");

                out.println("<p>Data pada tabel <b>mahasiswa</b>:</p>");
                out.println("<ul>");

                Statement st = conn.createStatement();
                ResultSet rs = st.executeQuery("SELECT nim, nama FROM mahasiswa");

                while (rs.next()) {
                    out.println("<li>" + rs.getString("nim") + " - " + rs.getString("nama") + "</li>");
                }

                out.println("</ul>");

            } catch (SQLException e) {
                out.println("<p style='color:red;'>Koneksi JDBC GAGAL: " + e.getMessage() + "</p>");
            }

            out.println("</body>");
            out.println("</html>");
        }
    }
}