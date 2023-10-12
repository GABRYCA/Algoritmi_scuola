<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Verifica G.C. 5BITI</title>
</head>
<body>
<h1><%= "Hello World!" %>
</h1>
<br/>
<a href="hello-servlet">Verifica G.C. 5BITI</a>
<%
    // Redirect alla pagina di login.
    response.sendRedirect("login.jsp");
%>
</body>
</html>