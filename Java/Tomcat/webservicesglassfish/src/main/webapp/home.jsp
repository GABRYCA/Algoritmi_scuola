<%@ page import="eu.anonymousgca.webservicesglassfish.UtenteBean" %>
<%@ page import="eu.anonymousgca.webservicesglassfish.ChiamateAPI" %><%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 30/04/2023
  Time: 13:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html lang="it" data-bs-theme="dark">
<!-- Verifico che ci sia la sessione attiva -->
<%
    if (session.getAttribute("loggedin") == null || !((boolean) session.getAttribute("loggedin"))) {
        response.sendRedirect("login.jsp");
        return;
    }

    if (session.getAttribute("utente") == null) {
        response.sendRedirect("login.jsp");
        return;
    }

    UtenteBean utente  = (UtenteBean) session.getAttribute("utente");
%>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/ui/1.13.2/jquery-ui.min.js"
            integrity="sha256-lSjKY0/srUM9BE3dPm+c4fBo1dky2v27Gdjm2uoZaL0=" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer">
    <link rel="icon" type="image/x-icon" href="favicon.webp">
    <title>Home - Messaggi</title>
    <script>

        var id_utente_contatto_selezionato = -1;

        // JQuery funzione che chiama post/utenti/contatti e legge il JSON e lo stampa.
        function debugContatti(){
            $.ajax({
                url: "api/post/utenti/contatti",
                type: "POST",
                data: {
                    "id_utente": <%= utente.getId_utente() %>
                },
                success: function (data) {
                    console.log(data);
                }
            });
        }

        function debugCaricaMessaggi(id_utente_contatto){
            $.ajax({
                url: "api/post/chat",
                type: "POST",
                data: {
                    "id_utente": <%= utente.getId_utente() %>,
                    "id_utente_contatto": id_utente_contatto
                },
                success: function (data) {
                    console.log(data);
                }
            });
        }

        // id_utente_contatto non è quello in sessione come parametro, ma quello che viene passato dalla funzione caricaContatti() (il contatto selezionato quindi).
        function caricaMessaggi(id_utente_contatto) {
            $.ajax({
                url: "api/post/chat",
                type: "POST",
                data: {
                    "id_utente": <%= utente.getId_utente() %>,
                    "id_utente_contatto": id_utente_contatto
                },
                dataType: "json", // Tipo di dato
                success: function (data) { // Funzione che viene eseguita se la chiamata ha successo

                    id_utente_contatto_selezionato = id_utente_contatto;

                    // Pulisco div con id="messaggi"
                    $("#messaggi").empty();

                    // Loop dei dati
                    // Append sarà al div con id="messaggi", poi si stampano tutti i messaggi.
                    // I messaggi inviati dall'utente in sessione saranno allineati a destra, quelli ricevuti a sinistra.
                    $.each(data, function (index, item) {
                        if (item.id_mittente === <%= utente.getId_utente() %>) {
                            // Visto che è il mittente, il messaggio lo allineo alla fine della riga (a destra) e cambio il colore del background in success.
                            $("#messaggi").append("<div class='row'>" +
                                "<div class='col'>" +
                                "<div class='row'>" +
                                "<div class='col'></div>" +
                                "<div class='col'>" +
                                "<div class='card text-white bg-success mb-3' style='max-width: 18rem;'>" +
                                "<div class='card-header'>" + item.id_mittente + "</div>" +
                                "<div class='card-body'>" +
                                "<p class='card-text'>" + item.testo + "</p>" +
                                "</div>" +
                                "</div>" +
                                "</div>" +
                                "</div>" +
                                "</div>" +
                                "</div>");
                        } else {
                            $("#messaggi").append("<div class='row'>" +
                                "<div class='col'>" +
                                "<div class='row'>" +
                                "<div class='col'>" +
                                "<div class='card text-white bg-secondary mb-3' style='max-width: 18rem;'>" +
                                "<div class='card-header'>" + item.id_mittente + "</div>" +
                                "<div class='card-body'>" +
                                "<p class='card-text'>" + item.testo + "</p>" +
                                "</div>" +
                                "</div>" +
                                "</div>" +
                                "<div class='col'></div>" +
                                "</div>" +
                                "</div>" +
                                "</div>");
                        }
                    });
                }
            });
        }

        // JQuery funzione che chiama post/utenti/contatti e legge il JSON, usando i dati ottenuti, al caricamento della pagina stampa i contatti in id="contatti".
        function caricaContatti(){
            $.ajax({
                url: "api/post/utenti/contatti",
                type: "POST",
                data: {
                    "id_utente": <%= utente.getId_utente() %>
                },
                dataType: "json", // Tipo di dato
                success: function(data) { // Funzione che viene eseguita se la chiamata ha successo
                    // Loop dei dati
                    $.each(data, function(index, item) {

                        var row = $("<div class='row text-center'>" +
                            "<div class='col'>" +
                            "<div class='row'>" + // Prima parte riga
                            "<div class='col'>" +
                            "<h5 class='mt-3'>" + item.nome + "</h5>" +
                            "</div>" +
                            "</div>" +
                            "<div class='row'>" + // Seconda parte riga
                            "<div class='col'>" +
                            "<h6 class='mt-3'>" + item.stato + "</h6>" +
                            "</div>" +
                            "<div class='col'>" +
                            "<h6 class='mt-3 text-end text-light text-opacity-50'>" + item.ultimo_accesso + "</h6>" +
                            "</div>" +
                            "</div>" +
                            "</div>"
                        );

                        // Pulsante
                        var button = $("<button class='btn btn-outline-primary h-100 w-100 mb-0 mx-0'><h5 class='pt-1'>Carica messaggi</h5></button>");
                        button.click(function() {
                            caricaMessaggi(item.id_utente); // Chiama funzione
                        });

                        // Aggiungo il pulsante
                        row.append($("<div class='col'></div></div>").append(button));

                        // Aggiungo la riga finale
                        $("#contatti").append(row);
                    });
                }
            }).fail(function() {
                alert("Errore");
            });
        }

        function caricaNomeLoggato() {
            $.ajax({
                url: "api/post/nome",
                type: "POST",
                data: {
                    "id_utente": <%= utente.getId_utente() %>
                },
                dataType: "json", // Tipo di dato
                success: function (data) { // Funzione che viene eseguita se la chiamata ha successo
                    $("#nomeLoggato").text(data.nome);
                }
            }).fail(function () {
                alert("Errore Loggato");
            });
        }

        function caricaListaUtentiNonContattati(){
            $.ajax({
                url: "api/post/utentiNonContattati",
                type: "POST",
                data: {
                    "id_utente": <%= utente.getId_utente() %>
                },
                dataType: "json", // Tipo di dato
                success: function(data) { // Funzione che viene eseguita se la chiamata ha successo
                    // Loop dei dati
                    $.each(data, function(index, item) {
                        $("#listaUtenti").append("<option value='" + item.id_utente + "'>" + item.nome + "</option>");
                    });
                }
            }).fail(function() {
                alert("Errore");
            });
        }


        // Avvio automatico funzione caricaContatti() al caricamento della pagina.
        $(document).ready(function () {
            caricaContatti();
            caricaNomeLoggato();
            caricaListaUtentiNonContattati();

            // Funzione che si attiva quando si preme il pulsante con id=buttonInviaMessaggio.
            $("#buttonInviaMessaggio").click(function () {

                if (id_utente_contatto_selezionato === -1){
                    alert("Seleziona un contatto");
                    return;
                }

                $.ajax({
                    url: "api/post/inviaMessaggio",
                    type: "POST",
                    data: {
                        "id_utente": <%= utente.getId_utente() %>,
                        "id_utente_contatto": id_utente_contatto_selezionato,
                        "testo": $("input[name=testoInviaMessaggio]").val()
                    },
                    dataType: "json", // Tipo di dato
                    success: function (data) { // Funzione che viene eseguita se la chiamata ha successo
                        caricaMessaggi(id_utente_contatto_selezionato);
                    }
                });
            });
        });
    </script>
</head>
<body class="font-monospace bg-dark text-light">

<div class="container-fluid">

    <div class="row justify-content-center mt-3">
        <div class="col-3 bg-black bg-opacity-25 rounded-3 mx-1 border border-secondary-subtle">
            <p class="text-center mt-3">Sei loggato come: <span class="text-warning" id="nomeLoggato">errore</span></p>
        </div>
        <div class="col-3 bg-black bg-opacity-25 rounded-3 mx-1 pt-1 border border-secondary-subtle">
            <button class="text-center btn btn-outline-danger w-100 mt-1" onclick="location.href='logout'">Logout</button>
        </div>
    </div>

    <hr>

    <div class="row bg-black bg-opacity-25 pt-2 pb-2 mx-3 rounded-3 border border-primary">
        <div class="col">
            <!-- SELECT popolato da JQuery al caricamento della pagina. Quando premuto ne carica la pagina messaggi -->
            <select class="form-select" id="listaUtenti" aria-label="Utenti">
                <option selected>Seleziona un contatto</option>
            </select>
            <button class="btn btn-outline-primary w-100 mt-2" onclick="location.href='profilo'">Scrivi</button>
        </div>
    </div>

    <hr>

    <div class="row bg-black bg-opacity-10 border border-primary border-opacity-50 mx-3 mt-5 mb-5 p-3 rounded-4">
        <!-- Colonna dei contatti -->
        <div id="contatti" class="col-4 h-100">

        </div>
        <!-- Colonna dei messaggi che si caricano quando si preme su un contatto -->
        <div class="col-8 border-start border-primary">

            <div class="row">
                <div class="col overflow-y-scroll" id="messaggi">
                </div>
            </div>

            <div class="row">
                <div class="col">
                    <div class="input-group mb-3">
                        <input type="text" class="form-control" name="testoInviaMessaggio" placeholder="Scrivi un messaggio" aria-label="Scrivi un messaggio" aria-describedby="buttonInviaMessaggio">
                        <button class="btn btn-outline-primary" type="button" id="buttonInviaMessaggio">Invia</button>
                    </div>
                </div>
            </div>

        </div>
    </div>
</div>

</body>
</html>
