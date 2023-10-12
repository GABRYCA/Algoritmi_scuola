<%@ page import="eu.anonymousgca.verifica.verifica.Appartamento" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="eu.anonymousgca.verifica.verifica.Utente" %><%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 19/01/2023
  Time: 13:30
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta charset="UTF-8">
    <title>Caretti Verifica - Benvenuto</title>
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
<div class="container mt-3 mb-4">
    <div class="row">
        <div class="col">
            <p class="h2 text-center">Pannello di controllo degli appartamenti:</p>
        </div>
    </div>
    <hr>

    <!-- Usando la sessione della servlet, stampo la prima tabella con gli appartamenti disponibili (non archiviati) con tutti i dati e a fianco
    un bottone archivia per archiviare l'appartamento -->
    <%

        boolean loggato = false;
        Utente utente = null;
        String titoloArchivia = "Archivia";

        if (session.getAttribute("utente") != null){
            utente = (Utente) session.getAttribute("utente");
            loggato = true;

            // Stampo i dati dell'utente (nome, cognome, username e saldo)
            out.println("<div class='row text-center'>");
            out.println("<div class='col'>");
            out.println("<p class='h4'>Benvenuto " + utente.getNome() + " " + utente.getCognome() + "!</p>");
            out.println("</div>");
            out.println("</div>");
            out.println("<div class='row text-center'>");
            out.println("<div class='col'>");
            out.println("<p class='h5'>Username: " + utente.getUsername() + "</p>");
            out.println("</div>");
            out.println("</div>");
            out.println("<div class='row text-center'>");
            out.println("<div class='col'>");
            out.println("<p class='h5'>Saldo: " + utente.getSaldo() + "€</p>");
            out.println("</div>");
            out.println("</div>");
            out.println("<hr>");

            titoloArchivia = "Compra";

        }

        if (session.getAttribute("appartamenti") != null) {

            if (session.getAttribute("messaggio") != null) {
                out.println("<script>$.toast({text: '" + session.getAttribute("messaggio") + "', showHideTransition: 'slide', icon: 'success', loader: false, position: 'top-right', hideAfter: 3000})</script>");
                session.removeAttribute("messaggio");
            }

            ArrayList<Appartamento> appartamenti = (ArrayList<Appartamento>) session.getAttribute("appartamenti");
            if (appartamenti.size() > 0) {
                // Gli appartamenti come dati hanno citta, prezzo, tipoAnnuncio.
                out.println("<div class='row text-center border-bottom border-dark h4 mt-4'>" +
                        "<div class='col'>" +
                        "<p>Città:</p>" +
                        "</div>" +
                        "<div class='col'>" +
                        "<p>Prezzo:</p>" +
                        "</div>" +
                        "<div class='col'>" +
                        "<p>Tipo:</p>" +
                        "</div>" +
                        "<div class='col'>" +
                        "<p>Archivia:</p>" +
                        "</div>" +
                        "</div>");
                int num = 0;
                int numX = 0;
                for (Appartamento appartamento : appartamenti){
                    if (!appartamento.isArchiviato()){
                        // Aggiungo appartamento alla tabella
                        out.println("<div class='row text-center h4 border-bottom border-dark pt-3'>" +
                                "<div class='col'>" +
                                "<p>" + appartamento.getCitta() + "</p>" +
                                "</div>" +
                                "<div class='col'>" +
                                "<p>" + appartamento.getPrezzo() + "</p>" +
                                "</div>" +
                                "<div class='col'>" +
                                "<form action='CambiaAnnuncio' method='post'>" +
                                "<input type='hidden' name='idAppartamento' value='" + num + "'>" +
                                "<input type='submit' class='link link-primary btn btn-transparent' value='" + appartamento.getTipoAnnuncio() + "'>" +
                                "</form>" +
                                "</div>" +
                                "<div class='col'>" +
                                "<form action='Acquista' method='post'>" +
                                "<input type='hidden' name='idAppartamento' value='" + num + "'>" +
                                "<input type='submit' class='btn btn-primary' value='" + titoloArchivia + "'>" +
                                "</form>" +
                                "</div>" +
                                "</div>");
                        numX++;
                    }
                    num++;
                }

                if (numX == 0){
                    out.println("<div class='row text-center text-danger h5 pb-2 border-bottom border-dark pt-3'>" +
                            "<div class='col'>" +
                            "<p>Nessun appartamento disponibile</p>" +
                            "</div>" +
                            "</div>");
                }

                // ARCHIVIATI


                out.println("<hr class='mt-5 mb-5'><div class='row text-center h4 mt-4'>" +
                        "<div class='col'>" +
                        "<p class='h2'>Archiviati:</p>" +
                        "</div>" +
                        "</div>");

                if (loggato){
                    out.println("<div class='row text-center border-bottom border-dark h4 mt-4'>" +
                            "<div class='col'>" +
                            "<p>Città:</p>" +
                            "</div>" +
                            "<div class='col'>" +
                            "<p>Prezzo:</p>" +
                            "</div>" +
                            "<div class='col'>" +
                            "<p>Tipo:</p>" +
                            "</div>" +
                            "<div class='col'>" +
                            "<p>Proprietario:</p>" +
                            "</div>" +
                            "</div>");
                } else {
                    out.println("<div class='row text-center border-bottom border-dark h4 mt-4'>" +
                            "<div class='col'>" +
                            "<p>Città:</p>" +
                            "</div>" +
                            "<div class='col'>" +
                            "<p>Prezzo:</p>" +
                            "</div>" +
                            "<div class='col'>" +
                            "<p>Tipo:</p>" +
                            "</div>" +
                            "</div>");
                }

                num = 0;
                numX = 0;
                for (Appartamento appartamento : appartamenti){
                    if (appartamento.isArchiviato()){
                        // Aggiungo appartamento alla tabella

                        if (!loggato){
                            out.println("<div class='row text-center h4 border-bottom border-dark pt-3'>" +
                                    "<div class='col'>" +
                                    "<p>" + appartamento.getCitta() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p>" + appartamento.getPrezzo() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p>" + appartamento.getTipoAnnuncio() + "</p>" +
                                    "</div>" +
                                    "</div>");
                        } else {
                            out.println("<div class='row text-center h4 border-bottom border-dark pt-3'>" +
                                    "<div class='col'>" +
                                    "<p>" + appartamento.getCitta() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p>" + appartamento.getPrezzo() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p>" + appartamento.getTipoAnnuncio() + "</p>" +
                                    "</div>" +
                                    "<div class='col'>" +
                                    "<p>" + appartamento.getProprietario() + "</p>" +
                                    "</div>" +
                                    "</div>");
                        }

                        numX++;
                    }
                    num++;
                }

                if (numX == 0){
                    out.println("<div class='row text-center text-danger h5 pb-2 border-bottom border-dark pt-3'>" +
                            "<div class='col'>" +
                            "<p>Nessun appartamento archiviato</p>" +
                            "</div>" +
                            "</div>");
                }

            } else {
                out.println("<div class='row'><div class='col'><p class='text-center'>Non ci sono appartamenti disponibili</p></div></div>");
            }
        } else {
            out.println("<div class='row'><div class='col'><p class='text-center'>Non ci sono appartamenti disponibili (Non inizializzata)</p></div></div>");
        }
    %>

</div>
</body>
</html>
