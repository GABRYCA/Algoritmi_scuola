<%@ page import="eu.anonymousgca.databeans.AnagraficaBean" %>
<%@ page import="eu.anonymousgca.databeans.AnagraficaListaBean" %>
<%@ page import="eu.anonymousgca.databeans.ValutazioniBean" %>
<%@ page import="eu.anonymousgca.databeans.ValutazioneTPSBean" %><%--
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
    <title>Voti</title>
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
        // Funzione che imposta un valore all'input con id #id numerico
        function setDati(id, descrizione, data, voto) {
            document.getElementById("id").value = id;
            document.getElementById("descrizione2").value = descrizione;
            document.getElementById("data2").value = data;
            document.getElementById("voto2").value = voto;
        }

        function eliminaVoto(id){
            // Con ajax elimino il voto
            $.ajax({
                url: "EliminaVoto",
                type: "POST",
                data: {
                    id: id
                },
                success: function (data) {
                    // Se la modifica è andata a buon fine
                    if (data === "success") {
                        // Mostro un toast di successo
                        $.toast({
                            heading: 'Successo',
                            text: 'Voto eliminato con successo',
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
                        // Mostro un toast di errore
                        $.toast({
                            heading: 'Errore',
                            text: 'Errore durante l\'eliminazione del voto',
                            showHideTransition: 'slide',
                            icon: 'error',
                            position: 'top-right',
                            hideAfter: 5000
                        });
                    }
                },
                error: function (data) {
                    console.log(data);
                }
            });
        }

        // Funzione modificaVoto
        function modificaVoto(){
            var voto = document.getElementById("voto2").value;
            var id = document.getElementById("id").value;
            var descrizione = document.getElementById("descrizione2").value;
            var data = document.getElementById("data2").value;
            // Ajax per la modifica del voto
            $.ajax({
                url: "ModificaVoto",
                type: "POST",
                data: {
                    id: id,
                    voto: voto,
                    descrizione: descrizione,
                    data: data
                },
                success: function (data) {
                    // Se la modifica è andata a buon fine
                    if (data === "success") {
                        // Mostro un toast di successo
                        $.toast({
                            heading: 'Successo',
                            text: 'Voto modificato con successo',
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
                        // Mostro un toast di errore
                        $.toast({
                            heading: 'Errore',
                            text: 'Errore durante la modifica del voto',
                            showHideTransition: 'slide',
                            icon: 'error',
                            position: 'top-right',
                            hideAfter: 5000
                        });
                    }
                }
            });
        }

        function aggiungiVoto(){
            var voto = document.getElementById("voto").value;
            var descrizione = document.getElementById("descrizione").value;
            var data = document.getElementById("data").value;
            var utente = document.getElementById("utente").value;
            // Ajax per la modifica del voto
            $.ajax({
                url: "InserisciVoto",
                type: "POST",
                data: {
                    voto: voto,
                    descrizione: descrizione,
                    data: data,
                    utente: utente
                },
                success: function (data) {
                    // Se la modifica è andata a buon fine
                    if (data === "success") {
                        // Mostro un toast di successo
                        $.toast({
                            heading: 'Successo',
                            text: 'Voto aggiunto con successo',
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
                        // Mostro un toast di errore
                        $.toast({
                            heading: 'Errore',
                            text: 'Errore durante l\'aggiunta del voto',
                            showHideTransition: 'slide',
                            icon: 'error',
                            position: 'top-right',
                            hideAfter: 5000
                        });
                    }
                },
                error: function (data){
                    console.log(data)
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
            <a href="anagrafica.jsp" class="btn btn-outline-primary w-100"><p class="h5 pt-1">Torna indietro</p></a>
        </div>
    </div>
</div>

<hr>


<div class="container">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Voti:</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <%
                ValutazioniBean valutazioniBean = new ValutazioniBean();
                valutazioniBean.setId(Integer.parseInt(request.getParameter("id")));
                valutazioniBean.selectValutazioni();

                if (valutazioniBean.size() == 0) {
                    out.println("<p class='h3 text-center'>Non ci sono voti</p>");
                } else {
                    out.println("<div class='row'>");
                    for (ValutazioneTPSBean valutazione : valutazioniBean.getValutazioniTPS()) {
                        // Creo delle colonne per tutti i dati più uno per il bottone che apre il modale per modificare il voto.
                        out.println("<div class='col-3'>");
                        out.println("<div class='card' data-aos='fade-up' data-aos-duration='1000'>");
                        out.println("<div class='card-body'>");
                        out.println("<p class='h5 text-center'>" + valutazione.getDescrizione() + "</p>");
                        out.println("<hr>");
                        out.println("<p class='h4 text-center'>" + valutazione.getData() + "</p>");
                        out.println("<hr>");
                        out.println("<p class='h2 text-center'>" + valutazione.getVoto() + "</p>");
                        out.println("<hr>");
                        out.println("<button type='button' class='btn btn-outline-primary w-100' data-bs-toggle='modal' data-bs-target='#modificaVoto' onclick='setDati(" + valutazione.getIdValutazioniTPS() + ",\"" + valutazione.getDescrizione() + "\",\"" + valutazione.getData() + "\"," + valutazione.getVoto() + ")'>Modifica</button>");
                        out.println("<hr>");
                        out.println("<button type='button' class='btn btn-outline-danger w-100' onclick='eliminaVoto(" + valutazione.getIdValutazioniTPS() + ")'>Elimina</button>");
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
            <!-- Pulsante che apre il modale per aggiungere un voto -->
            <button type="button" class="btn btn-outline-primary w-100" data-bs-toggle="modal" data-bs-target="#aggiungiVoto">Aggiungi voto</button>
        </div>
    </div>
</div>

<!-- Modal per modificare il voto -->
<!-- Modale bootstrap per richiedere i dati -->
<div class="modal fade text-dark bg-dark bg-opacity-10" id="aggiungiVoto" tabindex="-1" aria-labelledby="aggiungiVoto" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5">Inserire dati voto:</h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
            </div>
            <div class="modal-body">
                <div class="row">
                    <div class="col">
                        <!-- Descrizione -->
                        <label for="descrizione" class="form-label">Descrizione:</label>
                        <input type="text" class="form-control" id="descrizione" placeholder="Descrizione" value="" required>
                        <!-- Data -->
                        <label for="data" class="form-label">Data:</label>
                        <input type="date" class="form-control" id="data" placeholder="Data" value="" required>
                        <!-- Voto -->
                        <label for="voto" class="form-label">Voto:</label>
                        <input type="number" class="form-control" id="voto" placeholder="Voto" min="0" max="100" value="" required>
                        <!-- IdUtente -->
                        <input type="hidden" id="utente" value="<%=request.getParameter("id")%>">
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
                        <button type="button" class="btn btn-danger w-100" onclick="aggiungiVoto()">Inserisci</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Modal per modificare il voto -->
<!-- Modale bootstrap per richiedere i dati -->
<div class="modal fade text-dark bg-dark bg-opacity-10" id="modificaVoto" tabindex="-1" aria-labelledby="modificaVoto" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5">Inserire dati voto:</h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
            </div>
            <div class="modal-body">
                <div class="row">
                    <div class="col">
                        <!-- Descrizione -->
                        <label for="descrizione2" class="form-label">Descrizione:</label>
                        <input type="text" class="form-control" id="descrizione2" placeholder="Descrizione" value="" required>
                        <!-- Data -->
                        <label for="data2" class="form-label">Data:</label>
                        <input type="date" class="form-control" id="data2" placeholder="Data" value="" required>
                        <!-- Voto -->
                        <label for="voto2" class="form-label">Voto:</label>
                        <input type="number" class="form-control" id="voto2" placeholder="Voto" min="0" max="100" value="" required>
                        <!-- IdUtente -->
                        <input type="hidden" id="id" value="">
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
                        <button type="button" class="btn btn-danger w-100" onclick="modificaVoto()">Modifica</button>
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
