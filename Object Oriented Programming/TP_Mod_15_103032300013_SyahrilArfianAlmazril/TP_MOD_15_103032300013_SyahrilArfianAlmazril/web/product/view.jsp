<%-- 
    Document   : view.jsp
    Created on : 19 Dec 2025, 22.06.30
    Author     : User
--%>

<%@ page import="java.sql.*" %>
<%@ page import="config.DBConnection" %>
<!DOCTYPE html>
<html>
<head>
  <title>Data Barang</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">

<div class="container mt-5">
  <div class="card shadow">
    <div class="card-header bg-primary text-white d-flex justify-content-between align-items-center">
      <h5 class="mb-0">Data Barang</h5>
      <a href="add.jsp" class="btn btn-light btn-sm">+ Tambah Barang</a>
    </div>

    <div class="card-body">
      <table class="table table-bordered table-hover text-center">
        <thead class="table-primary">
          <tr>
            <th>ID</th>
            <th>Nama</th>
            <th>Harga</th>
            <th>Stok</th>
            <th>Aksi</th>
          </tr>
        </thead>
        <tbody>

        <%
          Connection conn = DBConnection.getConnection();
          Statement st = conn.createStatement();
          ResultSet rs = st.executeQuery("SELECT * FROM barang");

          while (rs.next()) {
        %>
          <tr>
            <td><%=rs.getInt("id")%></td>
            <td><%=rs.getString("nama_barang")%></td>
            <td>Rp <%=rs.getInt("harga")%></td>
            <td><%=rs.getInt("stok")%></td>
            <td>
              <a href="edit.jsp?id=<%=rs.getInt("id")%>" class="btn btn-warning btn-sm">Edit</a>
              <a href="?hapus=<%=rs.getInt("id")%>" 
                 class="btn btn-danger btn-sm"
                 onclick="return confirm('Yakin hapus data?')">
                 Hapus
              </a>
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

<%
String hapus = request.getParameter("hapus");
if (hapus != null) {
    PreparedStatement ps = conn.prepareStatement("DELETE FROM barang WHERE id=?");
    ps.setInt(1, Integer.parseInt(hapus));
    ps.executeUpdate();
    response.sendRedirect("view.jsp");
}
%>

</body>
</html>




