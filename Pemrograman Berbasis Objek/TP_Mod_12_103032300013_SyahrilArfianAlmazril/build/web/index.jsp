<%-- 
    Document   : index
    Created on : 29 Nov 2025, 11.37.22
    Author     : User
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Form Input</title>
</head>
<body>

    <form action="prosesData" method="post">
        NIM:
        <input type="text" name="nim"><br><br>

        Nama:
        <input type="text" name="nama"><br><br>

        <input type="submit" value="Kirim">
    </form>

    <%
        String nim = (String) request.getAttribute("nim");
        String nama = (String) request.getAttribute("nama");

        if (nim != null && nama != null) {
    %>
        <br>
        NIM Anda adalah: <%= nim %><br>
        Nama Anda adalah: <%= nama %>
    <% } %>

</body>
</html>
