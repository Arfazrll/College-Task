<%-- 
    Document   : view
    Created on : 7 Dec 2025, 21.50.52
    Author     : User
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.ResultSet"%>
<!DOCTYPE html>
<html>
<head>
    <title>Daftar Barang</title>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">

<div class="container mt-5">

    <div class="d-flex justify-content-between align-items-center mb-3">
        <h2 class="mb-0">Daftar Barang</h2>
        <a href="<%= request.getContextPath() %>/index.jsp" class="btn btn-outline-secondary btn-sm">
            Kembali
        </a>
    </div>

    <div class="card shadow-sm">
        <div class="card-header d-flex justify-content-between align-items-center">
            <span class="fw-semibold">List Barang</span>
            <a href="<%= request.getContextPath() %>/BarangController?menu=add" class="btn btn-sm btn-primary">
                + Tambah Barang
            </a>
        </div>

        <div class="card-body p-0">
            <div class="table-responsive">
                <table class="table table-striped table-hover mb-0 align-middle">
                    <thead class="table-light">
                        <tr>
                            <th style="width: 60px;">ID</th>
                            <th>Nama</th>
                            <th style="width: 150px;">Harga</th>
                            <th style="width: 90px;">Aksi</th>
                        </tr>
                    </thead>
                    <tbody>
                    <%
                        ResultSet rs = (ResultSet) request.getAttribute("list");
                        boolean hasData = false;

                        if (rs != null) {
                            while (rs.next()) {
                                hasData = true;
                                int id = rs.getInt("id");
                                String nama = rs.getString("nama");
                                double harga = rs.getDouble("harga");
                    %>
                        <tr>
                            <td><%= id %></td>
                            <td><%= nama %></td>
                            <td>Rp <%= String.format("%,.2f", harga) %></td>
                            <td>
                                <a href="<%= request.getContextPath() %>/BarangController?menu=edit&id=<%= id %>"
                                   class="btn btn-sm btn-warning">
                                    Edit
                                </a>
                            </td>
                        </tr>
                    <%
                            }
                        }

                        if (!hasData) {
                    %>
                        <tr>
                            <td colspan="4" class="text-center text-muted py-3">
                                Belum ada data barang.
                            </td>
                        </tr>
                    <%
                        }
                    %>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
