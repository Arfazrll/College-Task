/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package controller;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "DataServlet", urlPatterns = {"/prosesData"})
public class DataServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String nim  = request.getParameter("nim");
        String nama = request.getParameter("nama");

        request.setAttribute("nim", nim);
        request.setAttribute("nama", nama.toUpperCase());

        request.getRequestDispatcher("index.jsp").forward(request, response);
    }
}
