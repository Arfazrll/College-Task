<%-- 
    Document   : edit
    Created on : 7 Dec 2025, 21.51.39
    Author     : User
--%>

<%-- 
    Document   : edit
    Created on : 7 Dec 2025, 21.51.39
    Author     : User
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.ResultSet"%>
<!DOCTYPE html>
<html>
<head>
    <title>Edit Barang</title>

    <!-- Bootstrap 5 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body class="bg-light">

<%
    ResultSet rs = (ResultSet) request.getAttribute("list");
    int id = 0;
    String nama = "";
    double harga = 0;

    if (rs != null && rs.next()) {
        id = rs.getInt("id");
        nama = rs.getString("nama");
        harga = rs.getDouble("harga");
    }
%>

<div class="container mt-5">
    <div class="card shadow-sm">
        <div class="card-header bg-warning text-dark">
            <h4 class="mb-0">Edit Barang</h4>
        </div>

        <div class="card-body">

            <form method="post"
                  action="<%= request.getContextPath() %>/BarangController?menu=update&id=<%= id %>">

                <div class="mb-3">
                    <label class="form-label">Nama Barang</label>
                    <input type="text" name="nama" value="<%= nama %>" class="form-control" required>
                </div>

                <div class="mb-3">
                    <label class="form-label">Harga Barang</label>
                    <input type="number" step="0.01" name="harga" value="<%= harga %>" class="form-control" required>
                </div>

                <button type="submit" class="btn btn-primary">Update</button>
                <a href="<%= request.getContextPath() %>/BarangController" class="btn btn-secondary ms-2">
                    Kembali
                </a>
            </form>

        </div>
    </div>
</div>

<!-- Bootstrap JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>

