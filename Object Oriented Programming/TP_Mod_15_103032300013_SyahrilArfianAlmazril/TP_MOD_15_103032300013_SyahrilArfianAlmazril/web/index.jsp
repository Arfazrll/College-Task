<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Html.html to edit this template
-->
<%@ page contentType="text/html; charset=UTF-8" %>
<!DOCTYPE html>
<html>
<head>
  <title>Login</title>

  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">

</head>
<body class="bg-light">

<div class="container d-flex justify-content-center align-items-center vh-100">
  <div class="card shadow-lg" style="width: 380px;">
    <div class="card-body">
      <h3 class="text-center mb-4">Login Admin</h3>

      <form method="post" action="index.jsp">
        <div class="mb-3">
          <label class="form-label">Username</label>
          <input type="text" name="username" class="form-control" required>
        </div>

        <div class="mb-3">
          <label class="form-label">Password</label>
          <input type="password" name="password" class="form-control" required>
        </div>

        <button type="submit" class="btn btn-primary w-100">Login</button>
      </form>

      <%
        String u = request.getParameter("username");
        String p = request.getParameter("password");

        if (u != null && p != null) {
          if ("admin".equals(u) && "1234".equals(p)) {
            response.sendRedirect("product/view.jsp");
            return;
          } else {
      %>
          <div class="alert alert-danger mt-3 text-center">
            Username / password salah
          </div>
      <%
          }
        }
      %>

    </div>
  </div>
</div>

</body>
</html>


