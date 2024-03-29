<%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 16/02/2023
  Time: 21:15
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Valutazioni</title>
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

<!-- Verifico se esiste la sessione -->
<%
    if (session.getAttribute("utente") == null) {
        response.sendRedirect("login.jsp");
        return;
    }
%>

<jsp:useBean id="valutazioni" class="eu.anonymousgca.databeans.ValutazioniBean"/>
<jsp:useBean id="valutazione" class="eu.anonymousgca.databeans.ValutazioneTPSBean"/>
<jsp:setProperty name="valutazione" property="*"/>

<!-- Aggiungo a valutazioni la singola valutazione se non nulla da post -->
<%
    if (valutazione != null && valutazione.getDescrizione() != null) {
        valutazioni.addValutazioneTPS(valutazione);
    }
%>

<hr>

<div class="container">
    <div class="row text-center">
        <div class="col">
            <!-- Torna indietro a benvenuto.jsp -->
            <a href="benvenuto.jsp" class="btn btn-outline-primary w-100"><p class="h5 pt-1">Torna indietro</p></a>
        </div>
    </div>
</div>

<hr>

<div class="container">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Valutazioni:</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <!-- Stampo l'arraylist valutazioni -->
            <%
                for (int i = 0; i < valutazioni.size(); i++) {
                    out.println("<div class=\"row\">");
                    out.println("<div class=\"col\">");
                    out.println("<p class=\"h3\">" + valutazioni.getValutazioneTPS(i).getDescrizione() + "</p>");
                    out.println("</div>");
                    out.println("</div>");
                    out.println("<div class=\"row\">");
                    out.println("<div class=\"col\">");
                    out.println("<p class=\"h5\">" + valutazioni.getValutazioneTPS(i).getVoto() + "</p>");
                    out.println("</div>");
                    out.println("</div>");
                    out.println("<div class=\"row\">");
                    out.println("<div class=\"col\">");
                    out.println("<p class=\"h5\">" + valutazioni.getValutazioneTPS(i).getData() + "</p>");
                    out.println("</div>");
                    out.println("</div>");
                    out.println("<hr>");
                }
            %>
        </div>
    </div>
</div>

<hr>

<div class="container">
    <div class="row">
        <div class="col">
            <p class="h2 text-center">Inserisci valutazione:</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <form action="valutazioni.jsp" method="post">
                <div class="row">
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="text" class="form-control" id="descrizione" name="descrizione"
                                   placeholder="Descrizione">
                            <label for="descrizione">Descrizione</label>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="number" class="form-control" id="voto" name="voto" placeholder="Voto">
                            <label for="voto">Voto</label>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="date" class="form-control" id="data" name="data" placeholder="Data">
                            <label for="data">Data</label>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <button type="submit" class="btn btn-primary">Invia</button>
                    </div>
                </div>
            </form>
        </div>
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
