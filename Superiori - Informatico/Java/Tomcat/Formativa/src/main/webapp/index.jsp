<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Formativa</title>
</head>
<body>
<h1><%= "Formativa!" %>
</h1>
<br/>
<a href="hello-servlet">Formativa</a>
<%
    // Redirect alla pagina di login.
    response.sendRedirect("login.jsp");
%>
</body>
</html>