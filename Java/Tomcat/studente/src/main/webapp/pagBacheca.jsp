<%@ page import="eu.anonymousgca.studente.Studente" %><%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 27/12/2022
  Time: 11:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta charset="UTF-8">
    <title>Bacheca</title>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.js"
            integrity="sha512-zlWWyZq71UMApAjih4WkaRpikgY9Bz1oXIW5G0fED4vk14JjGlQ1UmkGM392jEULP8jbNMiwLWdM8Z87Hu88Fw=="
            crossorigin="anonymous" referrerpolicy="no-referrer"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.css"
          integrity="sha512-wJgJNTBBkLit7ymC6vvzM1EcSWeM9mmOu+1USHaRBbHkm6W9EgM0HY27+UtUaprntaYQJF75rc8gjxllKs5OIQ=="
          crossorigin="anonymous" referrerpolicy="no-referrer"/>
    <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
            integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
</head>
<body class="font-monospace">

<%
    // Verifico se l'utente è loggato
    if (session.getAttribute("studente") == null) {
        response.sendRedirect("pagLogin.jsp");
        return;
    } else {
%>

<div class="container mt-3">
    <div class="row text-center">
        <div class="col">
            <!-- Pulsante per andare alla pagina del profilo -->
            <a href="pagProfilo.jsp" class="btn btn-primary">Profilo</a>
        </div>
        <div class="col">
            <!-- Pulsante per sloggarsi (Quando premuto distrugge la sessione) -->
            <a href="logout.jsp" class="btn btn-primary">Logout</a>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <p class="h2 text-center">Bacheca:</p>
        </div>
    </div>
</div>

<div class="container">

<%
        // Recupero l'utente loggato
        Studente studente = (Studente) session.getAttribute("studente");

        // Stampo i messaggi
        for (String messaggio : studente.getMessaggi()) {
            out.println("<div class=\"alert alert-success\" role=\"alert\">");
            out.println("<p class='h4'>" + messaggio + "</p>");
            out.println("</div>");
        }
%>

</div>

<%
    }
%>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>
