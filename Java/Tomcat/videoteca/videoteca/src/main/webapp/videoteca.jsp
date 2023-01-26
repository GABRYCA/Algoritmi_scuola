<%@ page import="eu.anonymousgca.videoteca.DVD" %>
<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 20/01/2023
  Time: 17:13
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <head>
        <meta charset="UTF-8">
        <title>Videoteca - Videoteca</title>
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
              integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor"
              crossorigin="anonymous">
        <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
        <script src="https://code.jquery.com/jquery-3.6.1.min.js"
                integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.js"
                integrity="sha512-zlWWyZq71UMApAjih4WkaRpikgY9Bz1oXIW5G0fED4vk14JjGlQ1UmkGM392jEULP8jbNMiwLWdM8Z87Hu88Fw=="
                crossorigin="anonymous" referrerpolicy="no-referrer"></script>
        <link rel="stylesheet"
              href="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.css"
              integrity="sha512-wJgJNTBBkLit7ymC6vvzM1EcSWeM9mmOu+1USHaRBbHkm6W9EgM0HY27+UtUaprntaYQJF75rc8gjxllKs5OIQ=="
              crossorigin="anonymous" referrerpolicy="no-referrer"/>
        <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
                integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
    </head>
<body class="font-monospace">

<%
    if (session.getAttribute("loggato") == null){
        response.sendRedirect("login.jsp");
        return;
    }

    if (session.getAttribute("messaggio") != null){
        out.println("<script>$.toast({text: '" + session.getAttribute("messaggio") + "', showHideTransition: 'slide', icon: 'success', loader: false, position: 'top-right'});</script>");
        session.removeAttribute("messaggio");
    }
%>

<div class="container mt-4 mb-5">
    <div class="row">
        <div class="col">
            <p class="text-center h1">${titoloPagina}</p>
            <p class="text-center h5">${descrizionePagina}</p>
        </div>
    </div>

    <hr class="mt-3 mb-5">

    <div class="row">
        <div class="col">
            <p class="h2 text-center">DVD Disponibili:</p>
            <hr>
            <%
                out.println("<div class='row border-bottom border-dark'>" +
                        "<div class='col'>" +
                        "<p class='h4 text-center'>Codice</p>" +
                        "</div>" +
                        "<div class='col'>" +
                        "<p class='h4 text-center'>Titolo</p>" +
                        "</div>" +
                        "<div class='col'>" +
                        "<p class='h4 text-center'>Descrizione</p>" +
                        "</div>" +
                        "<div class='col'>" +
                        "<p class='h4 text-center'>Richiedi in prestito</p>" +
                        "</div>" +
                        "</div>");
                if (session.getAttribute("listaDVD") != null){
                    ArrayList<DVD> listaDVD = (ArrayList<DVD>) session.getAttribute("listaDVD");
                    int conta = 0;
                    for (DVD dvd : listaDVD) {
                        if (!dvd.isNoleggiato()){
                            out.println("<div class='row border-bottom border-dark pt-3'>" +
                                    "<div class='col'>" +
                                    "<p class='h4 text-center'>" + dvd.getCodice() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p class='h4 text-center'>" + dvd.getTitolo() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p class='h4 text-center'>" + dvd.getDescrizione() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<a class='btn btn-primary h4 text-center' href='Prestito?id=" + dvd.getCodice() + "'>Richiedi in prestito</a>" +
                                    "</div>" +
                                    "</div>");
                            conta++;
                        }
                    }

                    if (conta == 0){
                        out.println("<div class='row pt-3'>" +
                                "<div class='col'>" +
                                "<p class='h4 text-center text-danger'>Non ci sono DVD disponibili!</p>" +
                                "</div>" +
                                "</div>");
                    }
                } else {
                    out.println("<p class='text-center text-danger'>Non ci sono DVD disponibili!</p>");
                }
            %>
        </div>
    </div>

    <hr class="mt-5 mb-5">

    <div class="row">
        <div class="col">
            <p class="h2 text-center">DVD Noleggiati:</p>
            <hr>
            <%
                out.println("<div class='row border-bottom border-dark'>" +
                        "<div class='col'>" +
                        "<p class='h4 text-center'>Codice</p>" +
                        "</div>" +
                        "<div class='col'>" +
                        "<p class='h4 text-center'>Titolo</p>" +
                        "</div>" +
                        "</div>");
                if (session.getAttribute("listaDVD") != null){
                    ArrayList<DVD> listaDVD = (ArrayList<DVD>) session.getAttribute("listaDVD");
                    int conta = 0;
                    for (DVD dvd : listaDVD) {
                        if (dvd.isNoleggiato()){
                            out.println("<div class='row border-bottom border-dark pt-3'>" +
                                    "<div class='col'>" +
                                    "<p class='h4 text-center'>" + dvd.getCodice() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p class='h4 text-center'>" + dvd.getTitolo() + "</p>" +
                                    "</div>" +
                                    "</div>");
                            conta++;
                        }
                    }

                    if (conta == 0){
                        out.println("<div class='row pt-3'>" +
                                "<div class='col'>" +
                                "<p class='h4 text-center text-danger'>Non ci sono DVD noleggiati!</p>" +
                                "</div>" +
                                "</div>");
                    }
                } else {
                    out.println("<p class='text-center text-danger'>Non ci sono DVD disponibili!</p>");
                }
            %>
        </div>
    </div>

</div>
</body>
</html>
