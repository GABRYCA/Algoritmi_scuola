<%@ page import="eu.anonymousgca.databeans.AnagraficaBean" %>
<%@ page import="eu.anonymousgca.databeans.AnagraficaListaBean" %>
<%@ page import="eu.anonymousgca.databeans.UtenteListaBean" %>
<%@ page import="eu.anonymousgca.databeans.UtenteBean" %><%--
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
    <title>Anagrafica</title>
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
    <script>
        function aggiungiAnagrafica(){
            $.ajax({
                url: "InserisciAnagrafica",
                type: "POST",
                data: {
                    nome: $("#nome").val(),
                    cognome: $("#cognome").val(),
                    indirizzo: $("#indirizzo").val(),
                    utente: $("#utente").val()
                },
                success: function (data) {
                    if (data === "success") {
                        $.toast({
                            heading: 'Successo',
                            text: 'Anagrafica aggiunta con successo',
                            showHideTransition: 'slide',
                            icon: 'success',
                            position: 'top-right',
                            stack: false,
                            hideAfter: 2000,
                            afterHidden: function () {
                                // Ricarico la pagina
                                location.reload();
                            }
                        });
                    } else {
                        $.toast({
                            heading: 'Errore',
                            text: 'Errore durante l\'aggiunta dell\'anagrafica',
                            showHideTransition: 'slide',
                            icon: 'error',
                            position: 'top-right'
                        });
                    }
                }
            });
        }

        function eliminaAnagrafica(id){
            $.ajax({
                url: "EliminaAnagrafica",
                type: "POST",
                data: {
                    id: id
                },
                success: function (data) {
                    if (data === "success") {
                        $.toast({
                            heading: 'Successo',
                            text: 'Anagrafica eliminata con successo',
                            showHideTransition: 'slide',
                            icon: 'success',
                            position: 'top-right',
                            stack: false,
                            hideAfter: 2000,
                            afterHidden: function () {
                                // Ricarico la pagina
                                location.reload();
                            }
                        });
                    } else {
                        $.toast({
                            heading: 'Errore',
                            text: 'Errore durante l\'eliminazione dell\'anagrafica',
                            showHideTransition: 'slide',
                            icon: 'error',
                            position: 'top-right'
                        });
                    }
                }
            });
        }
    </script>
</head>
<body class="font-monospace">

<!-- Verifico se esiste la sessione -->
<%
    if (session.getAttribute("loggedin") == null || !session.getAttribute("loggedin").equals(true)) {
        response.sendRedirect("login.jsp");
        return;
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
            <p class="h1 text-center">Anagrafica:</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <%
                AnagraficaListaBean anagraficaListaBean = new AnagraficaListaBean();
                anagraficaListaBean.selectAnagrafica();

                if (anagraficaListaBean.size() == 0) {
                    out.println("<p class='h3 text-center'>Non ci sono anagrafiche</p>");
                } else {
                    out.println("<div class='row'>");
                    for (AnagraficaBean anagraficaBean : anagraficaListaBean.getAnagrafica()) {
                        // Creo delle colonne per tutti i dati più un paio, uno per modificare i dati che apre una pagina e l'altro aprire una pagina dei voti -->
                        out.println("<div class='col-12 col-md-6 col-lg-4 col-xl-3'>");
                        out.println("<div class='card' data-aos='fade-up' data-aos-duration='1000'>");
                        out.println("<div class='card-body'>");
                        out.println("<p class='h5 card-title'>" + anagraficaBean.getNome() + " " + anagraficaBean.getCognome() + "</p>");
                        out.println("<p class='card-text'>");
                        out.println("<b>Nome:</b> " + anagraficaBean.getNome() + "<br>");
                        out.println("<b>Cognome:</b> " + anagraficaBean.getCognome() + "<br>");
                        out.println("<b>Indirizzo:</b> " + anagraficaBean.getIndirizzo() + "<br>");
                        out.println("</p>");
                        out.println("<div class='row'>");
                        out.println("<div class='col'>");
                        out.println("<a href='modificaAnagrafica.jsp?id=" + anagraficaBean.getUtente_idUtente() + "' class='btn btn-outline-primary w-100'><p class='h5 pt-1'>Modifica</p></a>");
                        out.println("</div>");
                        out.println("<div class='col'>");
                        out.println("<a href='visualizzaVoti.jsp?id=" + anagraficaBean.getUtente_idUtente() + "' class='btn btn-outline-primary w-100'><p class='h5 pt-1'>Voti</p></a>");
                        out.println("</div>");
                        out.println("</div>");
                        out.println("<hr>");
                        out.println("<div class='row'>");
                        out.println("<div class='col'>");
                        out.println("<button type='button' class='btn btn-outline-danger w-100' onclick='eliminaAnagrafica(" + anagraficaBean.getId() + ")'>Elimina</button>");
                        out.println("</div>");
                        out.println("</div>");
                        out.println("</div>");
                        out.println("</div>");
                        out.println("</div>");
                    }
                    out.println("</div>");
                }

            %>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <!-- Pulsante per aprire un modale bootstrap per aggiungere una nuova anagrafica -->
            <button type="button" class="btn btn-outline-primary w-100" data-bs-toggle="modal"
                    data-bs-target="#aggiungiAnagraficaModal">
                <p class="h5 pt-1">Aggiungi anagrafica</p>
            </button>
        </div>
    </div>
</div>

<!-- Modale #aggiungiAnagraficaModal -->
<!-- Modale bootstrap per richiedere i dati -->
<div class="modal fade text-dark bg-dark bg-opacity-10" id="aggiungiAnagraficaModal" tabindex="-1" aria-labelledby="aggiungiAnagraficaModal" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5">Inserisci dati anagrafica:</h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
            </div>
            <div class="modal-body">
                <div class="row">
                    <div class="col">
                        <!-- Nome -->
                        <label for="nome" class="form-label">Nome:</label>
                        <input type="text" class="form-control" id="nome" value="" placeholder="Inserisci il nome">
                        <hr>
                        <!-- Cognome -->
                        <label for="cognome" class="form-label">Cognome:</label>
                        <input type="text" class="form-control" id="cognome" value="" placeholder="Inserisci il cognome">
                        <hr>
                        <!-- Indirizzo -->
                        <label for="indirizzo" class="form-label">Indirizzo:</label>
                        <input type="text" class="form-control" id="indirizzo" value="" placeholder="Inserisci l'indirizzo">
                        <hr>
                        <!-- Scegli utente -->
                        <label for="utente" class="form-label">Utente:</label>
                        <select class="form-select" id="utente">
                            <option value="0" selected>Seleziona un utente</option>
                            <%
                                UtenteListaBean utenteListaBean = new UtenteListaBean();
                                utenteListaBean.selectUtenti();

                                for (UtenteBean utenteBean : utenteListaBean.getUtenti()) {
                                    out.println("<option value='" + utenteBean.getIdUtente() + "'>" + utenteBean.getUsername() + "</option>");
                                }
                            %>
                        </select>
                    </div>
                </div>
            </div>
            <div class="modal-footer text-center">
                <div class="row w-100 justify-content-center">
                    <div class="col">
                        <button type="button" class="btn btn-primary w-100" data-bs-dismiss="modal">Annulla</button>
                    </div>
                    <div class="col">
                        <!-- Submit form -->
                        <button type="button" class="btn btn-danger w-100" onclick="aggiungiAnagrafica()">Inserisci</button>
                    </div>
                </div>
            </div>
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
