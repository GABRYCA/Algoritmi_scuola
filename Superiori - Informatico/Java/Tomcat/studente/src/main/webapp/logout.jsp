<%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 28/12/2022
  Time: 12:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Logout</title>
</head>
<body>

<!-- Distrugge la sessione e rimanda alla pagLogin -->
<%
    session.invalidate();
    response.sendRedirect("pagLogin.jsp");
%>

</body>
</html>
