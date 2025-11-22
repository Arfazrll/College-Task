<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>TP Mod 11</title>
    <style>
        body {
            margin: 0;
            font-family: Arial, Helvetica, sans-serif;
            background-color: #f5f5f5;
        }

        .container {
            max-width: 480px;
            margin: 80px auto;
            padding: 0 16px;
        }

        h1 {
            font-size: 42px;
            margin-bottom: 32px;
            font-weight: 600;
        }

        .tabs {
            display: flex;
            gap: 24px;
            margin-bottom: 32px;
            font-size: 18px;
        }

        .tab {
            text-decoration: none;
            font-weight: 600;
            color: #000000;
            position: relative;
        }

        .tab.active::after {
            content: "";
            position: absolute;
            left: 0;
            bottom: -6px;
            width: 40px;
            height: 3px;
            background-color: #000000;
        }

        .tab.register {
            color: #1a73e8;
        }

        .card {
            background-color: #ffffff;
            border-radius: 8px;
            padding: 32px 28px;
            box-shadow: 0 8px 20px rgba(0, 0, 0, 0.05);
        }

        .login-form label {
            display: block;
            font-size: 14px;
            margin-bottom: 6px;
        }

        .login-form input {
            width: 100%;
            border-radius: 6px;
            border: 1px solid #e0e0e0;
            padding: 12px 14px;
            font-size: 14px;
            margin-bottom: 18px;
            box-sizing: border-box;
        }

        .login-form button {
            border: none;
            border-radius: 6px;
            padding: 10px 26px;
            font-size: 14px;
            font-weight: 600;
            cursor: pointer;
            background-color: #1a73e8;
            color: #ffffff;
        }

        .login-form button:hover {
            opacity: 0.95;
        }
    </style>
</head>
<body>

<%
    String p = request.getParameter("page");
    if (p == null) {
        p = "login";   
    }
%>

<div class="container">
    <h1>TP Mod 11</h1>

    <div class="tabs">
        <a href="index.jsp?page=login"
           class="tab <%= "login".equals(p) ? "active" : "" %>">Login</a>
        <a href="index.jsp?page=register"
           class="tab register <%= "register".equals(p) ? "active" : "" %>">Register</a>
    </div>

    <div class="card">
        <form class="login-form"
              action="<%= "login".equals(p) ? "login" : "register" %>"
              method="post">

            <% if ("login".equals(p)) { %>
                <jsp:include page="login.jsp" flush="false"></jsp:include>
            <% } else { %>
                <jsp:include page="register.jsp" flush="false"></jsp:include>
            <% } %>

        </form>
    </div>
</div>
</body>
</html>
