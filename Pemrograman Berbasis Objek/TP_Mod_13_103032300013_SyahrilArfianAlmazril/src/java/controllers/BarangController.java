/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controllers;

import JDBC.JDBC;
import java.io.IOException;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author User
 */
@WebServlet(name = "BarangController", urlPatterns = {"/BarangController"})
public class BarangController extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        request.setCharacterEncoding("UTF-8");
        String menu = request.getParameter("menu");
        JDBC db = new JDBC();

        try {
            // ===== TAMPIL DATA (DEFAULT) =====
            if (menu == null || menu.trim().isEmpty()) {

                ResultSet rs = db.getData("SELECT * FROM barang");
                request.setAttribute("list", rs);
                // view.jsp ada di folder product
                request.getRequestDispatcher("product/view.jsp")
                       .forward(request, response);

            // ===== FORM TAMBAH BARANG =====
            } else if ("add".equals(menu)) {

                request.getRequestDispatcher("product/add.jsp")
                       .forward(request, response);

            // ===== PROSES INSERT BARANG BARU =====
            } else if ("insert".equals(menu)) {

                String nama = request.getParameter("nama");
                String hargaStr = request.getParameter("harga");

                double harga = 0;
                if (hargaStr != null && !hargaStr.isEmpty()) {
                    harga = Double.parseDouble(hargaStr);
                }

                String sql = "INSERT INTO barang (nama, harga) VALUES ('" 
                             + nama + "', " + harga + ")";
                db.runQuery(sql);

                // kembali ke daftar barang
                response.sendRedirect("BarangController");

            // ===== FORM EDIT BARANG (AMBIL 1 RECORD) =====
            } else if ("edit".equals(menu)) {

                String id = request.getParameter("id");
                String sql = "SELECT * FROM barang WHERE id = " + id;

                ResultSet rs = db.getData(sql);
                request.setAttribute("list", rs);
                // edit.jsp ada di folder product
                request.getRequestDispatcher("product/edit.jsp")
                       .forward(request, response);

            // ===== PROSES UPDATE BARANG =====
            } else if ("update".equals(menu)) {

                String id = request.getParameter("id");
                String nama = request.getParameter("nama");
                String hargaStr = request.getParameter("harga");

                double harga = 0;
                if (hargaStr != null && !hargaStr.isEmpty()) {
                    harga = Double.parseDouble(hargaStr);
                }

                String sql = "UPDATE barang "
                           + "SET nama = '" + nama + "', harga = " + harga
                           + " WHERE id = " + id;

                db.runQuery(sql);

                // kembali ke daftar barang
                response.sendRedirect("BarangController");

            } else {
                // fallback kalau menu tidak dikenali
                response.sendRedirect("index.jsp");
            }

        } catch (NumberFormatException e) {
            throw new ServletException("Format angka salah: " + e.getMessage(), e);
        } catch (Exception e) {
            throw new ServletException(e);
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    public String getServletInfo() {
        return "BarangController - CRUD sederhana untuk tabel barang";
    }
}