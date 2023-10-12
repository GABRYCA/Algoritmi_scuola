<%@ page import="eu.anonymousgca.databeans.AnagraficaBean" %>
<%@ page import="java.sql.SQLException" %><%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 02/03/2023
  Time: 14:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    if (session.getAttribute("loggedin") == null || !session.getAttribute("loggedin").equals(true)) {
        response.sendRedirect("login.jsp");
        return;
    }

    // Verifico se get id è vuoto
    if (request.getParameter("id") == null) {
        response.sendRedirect("anagrafica.jsp");
        return;
    }

    // Verifico se id è un numero
    try {
        Integer.parseInt(request.getParameter("id"));
    } catch (NumberFormatException e) {
        response.sendRedirect("anagrafica.jsp");
        return;
    }

    // Prendo i dati dal db
    String id = request.getParameter("id");
    String nome = "";
    String cognome = "";
    String indirizzo = "";

    AnagraficaBean anagraficaBean = new AnagraficaBean();
    anagraficaBean.setId(Integer.parseInt(id));
    try {
        anagraficaBean.getQuerySelect();
    } catch (SQLException e) {
        throw new RuntimeException(e);
    }

    if (anagraficaBean.getNome() != null) {
        nome = anagraficaBean.getNome();
    }

    if (anagraficaBean.getCognome() != null) {
        cognome = anagraficaBean.getCognome();
    }

    if (anagraficaBean.getIndirizzo() != null) {
        indirizzo = anagraficaBean.getIndirizzo();
    }
%>
<html>
<head>
    <meta charset="UTF-8">
    <title>Modifica - Anagrafica</title>
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

        // Internal Server Error (500) per qualche motivo, in PHP non succede.
        function modificaDatiFunzione(){

            // Prendo i dati dal form
            var nome = $("#nome").val();
            var cognome = $("#cognome").val();
            var indirizzo = $("#indirizzo").val();

            $.ajax({
                url: "ModificaAnagrafica",
                type: "POST",
                data: {
                    nome: nome,
                    cognome: cognome,
                    indirizzo: indirizzo,
                    id: "<%= id %>"
                },
                success: function (data) {
                    if (data === "success") {
                        $.toast({
                            heading: 'Successo',
                            text: 'Dati modificati con successo',
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
                    } else if (data === "error") {
                        $.toast({
                            heading: 'Errore',
                            text: 'Errore durante la modifica dei dati',
                            icon: 'error',
                            position: 'top-right',
                            loader: false,
                            stack: false,
                            hideAfter: 3000
                        });
                    } else {
                        $.toast({
                            heading: 'Errore',
                            text: 'Errore durante la modifica dei dati interno (' + data + ')',
                            icon: 'error',
                            position: 'top-right',
                            loader: false,
                            stack: false,
                            hideAfter: 3000
                        });
                    }
                },
                error: function (data) {
                    $.toast({
                        heading: 'Errore',
                        text: 'Errore durante la modifica dei dati (grave)',
                        icon: 'error',
                        position: 'top-right',
                        loader: false,
                        stack: false,
                        hideAfter: 3000
                    });

                    // Stampo errore
                    console.log(data);
                }
            });
        }
    </script>
</head>
<body class="font-monospace">

<div class="container">
    <div class="row mt-4">
        <div class="col">
            <p class="h1 text-center">Modifica - Anagrafica</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <!-- Pulsante per tornare alla pagina di anagrafica -->
            <a href="anagrafica.jsp" class="btn btn-outline-primary w-100">Torna alla pagina di anagrafica</a>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <%
                // Stampo dati letti dal db
                out.println("<p class=\"h3 text-center\">ID: " + id + "</p>");
                out.println("<p class=\"h3 text-center\">Nome: " + nome + "</p>");
                out.println("<p class=\"h3 text-center\">Cognome: " + cognome + "</p>");
                out.println("<p class=\"h3 text-center\">Indirizzo: " + indirizzo + "</p>");
            %>
        </div>
    </div>
    <hr class="mt-4">
    <div class="row">
        <div class="col">
            <!-- Pulsante per aprire un modale bootstrap che richiede i dati -->
            <button type="button" class="btn btn-primary w-100" data-bs-toggle="modal" data-bs-target="#modificaDatiModale">Modifica</button>
        </div>
    </div>
</div>

<!-- Modale bootstrap per richiedere i dati -->
<div class="modal fade text-dark bg-dark bg-opacity-10" id="modificaDatiModale" tabindex="-1" aria-labelledby="modificaDatiModale" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5">Edita SOLO i dati che vuoi aggiornare:</h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
            </div>
            <div class="modal-body">
                <div class="row">
                    <div class="col">
                        <!-- Nome -->
                        <label for="nome" class="form-label">Nome:</label>
                        <input type="text" class="form-control" id="nome" value="<% out.println(nome); %>" placeholder="Nome">
                        <!-- Cognome -->
                        <label for="cognome" class="form-label">Cognome:</label>
                        <input type="text" class="form-control" id="cognome" value="<% out.println(cognome); %>" placeholder="Cognome">
                        <!-- Indirizzo -->
                        <label for="indirizzo" class="form-label">Indirizzo:</label>
                        <input type="text" class="form-control" id="indirizzo" value="<% out.println(indirizzo); %>" placeholder="Indirizzo">
                        <!-- Input hidden id -->
                        <input type="hidden" id="id" name="id" value="<% out.println(id); %>">
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
                        <button type="button" class="btn btn-danger w-100" onclick="modificaDatiFunzione()">Modifica</button>
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
