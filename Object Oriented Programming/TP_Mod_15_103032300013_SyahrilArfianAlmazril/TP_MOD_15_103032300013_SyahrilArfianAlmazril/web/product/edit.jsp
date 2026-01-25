<%-- 
    Document   : edit.jsp
    Created on : 19 Dec 2025, 22.06.18
    Author     : User
--%>

<%@ page import="java.sql.*" %>
<%@ page import="config.DBConnection" %>
<!DOCTYPE html>
<html>
<head>
  <title>Edit Barang</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">

<%
int id = Integer.parseInt(request.getParameter("id"));
Connection conn = DBConnection.getConnection();

PreparedStatement ps = conn.prepareStatement("SELECT * FROM barang WHERE id=?");
ps.setInt(1, id);
ResultSet rs = ps.executeQuery();
rs.next();
%>

<div class="container mt-5">
  <div class="card shadow mx-auto" style="max-width: 450px;">
    <div class="card-header bg-warning">
      Edit Barang
    </div>

    <div class="card-body">
      <form method="post">
        <div class="mb-3">
          <label class="form-label">Nama Barang</label>
          <input type="text" name="nama" class="form-control"
                 value="<%=rs.getString("nama_barang")%>" required>
        </div>

        <div class="mb-3">
          <label class="form-label">Harga</label>
          <input type="number" name="harga" class="form-control"
                 value="<%=rs.getInt("harga")%>" required>
        </div>

        <div class="mb-3">
          <label class="form-label">Stok</label>
          <input type="number" name="stok" class="form-control"
                 value="<%=rs.getInt("stok")%>" required>
        </div>

        <button type="submit" class="btn btn-warning w-100">Update</button>
        <a href="view.jsp" class="btn btn-secondary w-100 mt-2">Kembali</a>
      </form>

      <%
      if (request.getParameter("nama") != null) {
          PreparedStatement up = conn.prepareStatement(
              "UPDATE barang SET nama_barang=?, harga=?, stok=? WHERE id=?"
          );
          up.setString(1, request.getParameter("nama"));
          up.setInt(2, Integer.parseInt(request.getParameter("harga")));
          up.setInt(3, Integer.parseInt(request.getParameter("stok")));
          up.setInt(4, id);
          up.executeUpdate();
          response.sendRedirect("view.jsp");
      }
      %>

    </div>
  </div>
</div>

</body>
</html>


