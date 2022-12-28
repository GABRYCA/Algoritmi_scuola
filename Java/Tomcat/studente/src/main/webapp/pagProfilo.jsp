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
    <title>Profilo</title>
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
        <!-- Tre link/pulsanti, uno per aprire la bacheca, uno per cambiare la password e uno per sloggarsi -->
        <div class="col-12">
            <a href="pagBacheca.jsp" class="btn btn-primary">Bacheca</a>
            <a href="cambioPsw.jsp" class="btn btn-primary">Cambia password</a>
            <a href="logout.jsp" class="btn btn-primary">Logout</a>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <p class="h3 text-center">Informazioni Profilo:</p>
        </div>
    </div>
</div>

<%
        // Ottengo studente dalla sessione
        Studente studente =  (Studente) session.getAttribute("studente");

        // Stampo i dati dello studente
        out.println("<div class=\"container mt-3\">");
        out.println("<div class=\"row\">");
        out.println("<div class=\"col\">");
        out.println("<p class=\"h5\">Nome: " + studente.getNome() + "</p>");
        out.println("</div>");
        out.println("<div class=\"col\">");
        out.println("<p class=\"h5\">Cognome: " + studente.getCognome() + "</p>");
        out.println("</div>");
        out.println("</div>");
        out.println("<div class=\"row\">");
        out.println("<div class=\"col\">");
        out.println("<p class=\"h5\">Data di nascita: " + studente.getDataNascita() + "</p>");
        out.println("</div>");
        out.println("<div class=\"col\">");
        out.println("<p class=\"h5\">Indirizzo: " + studente.getIndirizzo() + "</p>");
        out.println("</div>");
        out.println("</div>");

        // Se e solo se la foto profilo non è una stringa nella, creo una img con src = foto profilo
        if (!studente.getFotoProfilo().equals("")) {
            out.println("<div class=\"row\">");
            out.println("<div class=\"col\">");
            out.println("<img src=\"" + studente.getFotoProfilo() + "\" class=\"img-fluid\" alt=\"Foto profilo\">");
            out.println("</div>");
            out.println("</div>");
        }
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
