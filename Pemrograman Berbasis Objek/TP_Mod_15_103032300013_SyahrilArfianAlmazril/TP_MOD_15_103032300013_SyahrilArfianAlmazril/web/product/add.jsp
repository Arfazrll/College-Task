<%-- 
    Document   : add.jsp
    Created on : 19 Dec 2025, 22.06.07
    Author     : User
--%>

<%@ page import="java.sql.*" %>
<%@ page import="config.DBConnection" %>
<!DOCTYPE html>
<html>
<head>
  <title>Tambah Barang</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">

<div class="container mt-5">
  <div class="card shadow mx-auto" style="max-width: 450px;">
    <div class="card-header bg-success text-white">
      Tambah Barang
    </div>

    <div class="card-body">
      <form method="post">
        <div class="mb-3">
          <label class="form-label">Nama Barang</label>
          <input type="text" name="nama" class="form-control" required>
        </div>

        <div class="mb-3">
          <label class="form-label">Harga</label>
          <input type="number" name="harga" class="form-control" required>
        </div>

        <div class="mb-3">
          <label class="form-label">Stok</label>
          <input type="number" name="stok" class="form-control" required>
        </div>

        <button type="submit" class="btn btn-success w-100">Simpan</button>
        <a href="view.jsp" class="btn btn-secondary w-100 mt-2">Kembali</a>
      </form>

      <%
      if (request.getParameter("nama") != null) {
          Connection conn = DBConnection.getConnection();
          PreparedStatement ps = conn.prepareStatement(
              "INSERT INTO barang VALUES (null,?,?,?)"
          );
          ps.setString(1, request.getParameter("nama"));
          ps.setInt(2, Integer.parseInt(request.getParameter("harga")));
          ps.setInt(3, Integer.parseInt(request.getParameter("stok")));
          ps.executeUpdate();
          response.sendRedirect("view.jsp");
      }
      %>

    </div>
  </div>
</div>

</body>
</html>


