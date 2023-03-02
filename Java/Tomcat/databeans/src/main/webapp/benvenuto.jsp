<%@ page import="eu.anonymousgca.databeans.UtenteBean" %><%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 10/02/2023
  Time: 13:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta charset="UTF-8">
    <title>Benvenuto</title>
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
    if (session.getAttribute("loggedin") == null || !session.getAttribute("loggedin").equals(true)) {
        response.sendRedirect("login.jsp");
        return;
    }
%>

<jsp:useBean id="utente" class="eu.anonymousgca.databeans.UtenteBean"/>
<!-- Imposto l'utente con username e password presi dal get -->
<jsp:setProperty property="*" name="utente"/>

<div class="container pt-3">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Benvenuto: <% out.println(session.getAttribute("username")); %></p>
        </div>
    </div>
</div>

<hr>

<div class="container">
    <div class="row">
        <div class="col">
            <p class="h2 text-center">Opzioni:</p>
        </div>
    </div>
    <div class="row text-center mt-3 p-3 border border-dark rounded-3">
        <div class="col">
            <!-- Apri anagrafica.jsp -->
            <a href="anagrafica.jsp" class="btn btn-outline-primary btn-lg btn-block" role="button" aria-pressed="true">Anagrafica</a>
        </div>
        <!--<div class="col">
            <a href="valutazioni.jsp" class="btn btn-outline-primary btn-lg btn-block" role="button" aria-pressed="true">Valutazioni</a>
        </div>-->
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>
