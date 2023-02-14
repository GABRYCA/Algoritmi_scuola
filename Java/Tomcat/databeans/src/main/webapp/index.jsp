<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Index</title>
    <%! String messaggio = "Ciao: ";
    String nome = "Michele";
    String cognome = "Meloni";
    // Ora
    String orario = new java.util.Date().toString();
    %>
</head>
<body>
<h1><%= messaggio %> <%= nome %> <%= cognome %>, sono le <%= orario %></h1>
</h1>
<br/>
<a href="hello-servlet">Hello Servlet</a>
<%
    // Redirect automatico a login.jsp
    response.sendRedirect("login.jsp");
%>
</body>
</html>