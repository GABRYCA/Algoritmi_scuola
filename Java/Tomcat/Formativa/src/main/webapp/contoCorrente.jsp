<%@ page import="eu.anonymousgca.formativa.UtenteBean" %>
<%@ page import="eu.anonymousgca.formativa.MovimentiUtenteBean" %>
<%@ page import="eu.anonymousgca.formativa.MovimentoBean" %><%--
  Created by IntelliJ IDEA.
  User: gabry
  Date: 09/03/2023
  Time: 13:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    // Controllo se loggato.
    if (session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
        response.sendRedirect("login.jsp");
    }

    // Carico UtenteBean dall'id.
    int id = (int) session.getAttribute("id");
    UtenteBean utente = new UtenteBean();
    utente.setId(id);
    if (!utente.selectUtente()){
        out.println("Errore durante il caricamento dell'utente con id " + id);
    }

    // Carico i dati del conto corrente.
    MovimentiUtenteBean movimentiUtente = new MovimentiUtenteBean();
    movimentiUtente.setId_utente(id);
    if (!movimentiUtente.selectMovimenti()){
        out.println("Errore durante il caricamento dei movimenti dell'utente con id " + id);
    }
%>
<html>
<html lang="it" data-bs-theme="dark">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
            integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer">
    <link rel="icon" type="image/x-icon" href="/favicon.webp">
    <title>Conto Corrente</title>
    <script>
        var tipoOperazione = "";

        function setTipoOperazione(tipo) {
            tipoOperazione = tipo;
        }

        function eseguiOperazione(){
            var valore = document.getElementById("valore").value;
            var descrizione = document.getElementById("descrizione").value;
            if (valore === "" || descrizione === ""){
                alert("Inserisci tutti i campi!");
                return;
            }
            // Metto il valore in negativo o positivo in base al tipoOperazione.
            if (tipoOperazione === "prelievo"){
                valore = -valore;
            }
            $.ajax({
                url: "eseguiOperazione",
                type: "POST",
                data: {
                    valore: valore,
                    descrizione: descrizione
                },
                success: function (data) {
                    if (data === "success"){
                        alert("Operazione eseguita con successo!");
                        location.reload();
                    } else {
                        alert("Errore durante l'esecuzione dell'operazione!");
                    }
                }
            });
        }
    </script>
</head>
<body class="font-monospace text-light bg-black">

<!-- Dati cliente conto, nome, cognome -->
<div class="container">
    <div class="row text-center border-bottom border-light mt-3">
        <div class="col">
            <p class="h5">Numero conto: <%=utente.getNum_conto()%></p>
        </div>
        <div class="col">
            <p class="h5">Nome: <%=utente.getNome()%></p>
        </div>
        <div class="col">
            <p class="h5">Cognome: <%=utente.getCognome()%></p>
        </div>
    </div>

    <div class="row mt-3">
        <div class="col text-center">
            <p class="h3">Esegui operazione:</p>
        </div>
    </div>
    <div class="row justify-content-center text-center">
        <div class="col">
            <!-- Pulsante per effettuare un versamento -->
            <button type="button" class="btn btn-success w-100 mt-3" data-bs-toggle="modal"
                    data-bs-target="#operazioneModal" onclick="setTipoOperazione('versamento')">
                Versamento
            </button>
        </div>
        <div class="col">
            <!-- Pulsante per effettuare un prelievo -->
            <button type="button" class="btn btn-danger w-100 mt-3" data-bs-toggle="modal"
                    data-bs-target="#operazioneModal" onclick="setTipoOperazione('prelievo')">
                Prelievo
            </button>
        </div>
    </div>
    <hr>

    <div class="row">
        <div class="col">
            <p class="h1 text-center mt-3">Movimenti conto corrente:</p>
        </div>
    </div>
    <div class="row">
        <div class="col">
            <!-- Tabella con tutti i movimenti e il saldo totale -->
            <table class="table table-dark table-striped table-hover mt-3">
                <thead>
                <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Descrizione</th>
                    <th scope="col">Euro</th>
                </tr>
                </thead>
                <tbody>
                <%
                    for (MovimentoBean movimento : movimentiUtente.getMovimenti()) {
                        out.println("<tr>");
                        out.println("<td>" + movimento.getId() + "</td>");
                        out.println("<td>" + movimento.getDescrizione() + "</td>");
                        out.println("<td>" + movimento.getEuro() + "</td>");
                        out.println("</tr>");
                    }
                    // Saldo totale.
                    out.println("<tr>");
                    out.println("<td></td>");
                    out.println("<td>Saldo totale:</td>");
                    out.println("<td>" + utente.getSaldo() + "</td>");
                    out.println("</tr>");
                %>
                </tbody>
            </table>
        </div>
    </div>

    <!--- ZONA MODALI -->


    <!-- Modal per effettuare un versamento o un prelievo -->
    <div class="modal fade text-dark bg-dark bg-opacity-10" id="operazioneModal" tabindex="-1" aria-labelledby="modificaDatiModale" aria-hidden="true">
        <div class="modal-dialog modal-dialog-centered">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title fs-5">Inserire dati:</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
                </div>
                <div class="modal-body">
                    <div class="row">
                        <div class="col">
                            <!-- Descrizione -->
                            <label for="descrizione" class="form-label">Descrizione:</label>
                            <input type="text" class="form-control" id="descrizione" value="" placeholder="Descrizione">
                            <!-- Valore -->
                            <label for="valore" class="form-label">Valore:</label>
                            <input type="number" class="form-control" id="valore" value="" placeholder="Valore">
                            <!-- Input hidden id -->
                            <input type="hidden" id="id" name="id" value="<% out.println(utente.getId()); %>">
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
                            <button type="button" class="btn btn-danger w-100" onclick="eseguiOperazione()">Esegui</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

</div>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>
