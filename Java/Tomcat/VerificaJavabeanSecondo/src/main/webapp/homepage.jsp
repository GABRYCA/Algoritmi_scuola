<%@ page import="eu.anonymousgca.verificajavabean.Palestra" %>
<%@ page import="eu.anonymousgca.verificajavabean.Corso" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
// Verifico se esiste la sessione e loggedin è true
if (session.getAttribute("loggedin") == null || !(boolean) session.getAttribute("loggedin")) {
    // Se non esiste la sessione o loggedin è false, reindirizzo alla pagina di login
    response.sendRedirect("login.jsp");
    return;
}

// Creo l'oggetto Palestra con l'id dato dalla sessione.
Palestra palestra = new Palestra();
palestra.setId((int) session.getAttribute("id"));
if (!palestra.selectPalestra()){
    // Se non esiste la palestra, reindirizzo alla pagina di login e distruggo la sessione
    session.invalidate();
    response.sendRedirect("login.jsp");
    return;
}
%>
<html lang="it" data-bs-theme="dark">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
            integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
    <title>Verifica - Home</title>
    <script>

        var modificandoCorsoNumero = -1;

        function inserisciCorso(){
            // Prendo dal modale i dati e li invio con JQuery a inserisciCorso Servlet in POST.
            var descrizione = $("#descrizione").val();
            var iscritti = $("#numeroIscritti").val();
            var postiTotali = $("#postiTotali").val();
            $.ajax({
                url: "inserisciCorso",
                type: "POST",
                data: {
                    descrizione: descrizione,
                    numeroIscritti: iscritti,
                    postiTotali: postiTotali
                },
                success: function (data) {
                    if (data === "success"){
                        alert("Operazione eseguita con successo!");
                        location.reload();
                    } else {
                        alert("Errore durante l'esecuzione dell'operazione!");
                    }
                },
                error: function (xhr, status, error) {
                    alert("Errore durante l'esecuzione dell'operazione!");
                }
            });
        }

        function modificaCorso(){
            var descrizione = $('#descrizioneModificata').val();
            var iscritti = $('#numeroIscrittiModificato').val();
            var postiTotali = $('#postiTotaliModificato').val();
            $.ajax({
                url: "modificaCorso",
                type: "POST",
                data: {
                    id: modificandoCorsoNumero,
                    descrizione: descrizione,
                    numeroIscritti: iscritti,
                    postiTotali: postiTotali
                },
                success: function (data) {
                    if (data === "success") {
                        alert("Operazione eseguita con successo!");
                        location.reload();
                    } else {
                        alert("Operazione eseguita con successo!");
                        location.reload();
                    }
                }
            });
        }

        function modificandoCorso(id){
            modificandoCorsoNumero = id;
        }
    </script>
</head>
<body class="font-monospace">

<div class="container">
    <!-- Riga con nome palestra -->
    <div class="row mt-2">
        <div class="col">
            <p class="h1 text-center">Benvenuto alla palestra: <%=palestra.getNomePalestra()%></p>
        </div>
    </div>
    <hr>
    <!-- Descrizione della palestra e via -->
    <div class="row">
        <div class="col">
            <p class="h4 text-center">Descrizione: <%=palestra.getDescrizione()%></p>
        </div>
        <div class="col">
            <p class="h4 text-center">Luogo: <%=palestra.getVia()%> (<%=palestra.getCitta()%>)</p>
        </div>
    </div>
    <hr>
    <!-- Banner della palestra da imgUrl -->
    <div class="row justify-content-center text-center">
        <div class="col">
            <img src="<%=palestra.getImgUrl()%>" class="img-fluid" alt="Banner della palestra">
        </div>
    </div>
    <hr>

    <!-- Lista dei corsi con il numero di iscritti per ciascun corso e i posti totali. Con bottone per modificare/eliminare il corso.
    e in fondo il totale delle persone iscritte a tutti i corsi e il totale dei posti per tutti i corsi -->
    <div class="row">
        <div class="col">
            <p class="h4 text-center">Lista dei corsi</p>
            <table class="table table-striped table-hover">
                <thead>
                <tr>
                    <th scope="col">Descrizione</th>
                    <th scope="col">Iscritti</th>
                    <th scope="col">Posti</th>
                    <th scope="col">Azioni</th>
                </tr>
                </thead>
                <tbody>
                <%-- Ciclo per ogni corso --%>
                <%
                    palestra.loadListaCorsi();
                    if (palestra.getCorsi().getListaCorsi().size() == 0) {
                        out.println("<tr><td colspan='3' class='text-center'>Non ci sono corsi</td></tr>");
                    } else {
                    for (Corso corso : palestra.getCorsi().getListaCorsi()) { %>
                    <tr>
                        <td><%=corso.getDescrizione()%></td>
                        <td><%=corso.getNumeroIscritti()%></td>
                        <td><%=corso.getPostiTotali()%></td>
                        <td>
                            <button type="button" class="btn btn-outline-primary" data-bs-toggle="modal" data-bs-target="#modificaCorso" onclick="modificandoCorso('<%=corso.getId()%>')">
                                Modifica
                            </button>
                            <a href="eliminaCorso?id=<%=corso.getId()%>" class="btn btn-danger">Elimina</a>
                        </td>
                    </tr>
                <% }
                    // Totale posti e iscritti
                    out.println("<tr><td colspan='3' class='text-center'>Totale iscritti: " + palestra.getCorsi().getTotaleIscritti() + "</td>");
                    out.println("<td colspan='3' class='text-center'>Totale posti: " + palestra.getCorsi().getTotalePosti() + "</td></tr>");
                }%>
                </tbody>
            </table>
        </div>
    </div>

    <!-- Pulsante per aggiungere un corso -->
    <div class="row pt-4 pb-4">
        <div class="col">
            <button type="button" class="btn btn-outline-success w-100" data-bs-toggle="modal" data-bs-target="#aggiungiCorso">
                <p class="h2 pt-1">Aggiungi corso</p>
            </button>
        </div>
    </div>

    <!-- Pulsanti per eseguire una promozione -->
    <div class="row">
        <p class="h1 text-center">Promozioni:</p>
        <div class="col">
            <!-- Promuovi mySpace -->
            <a href="promuovi?id=1" class="btn btn-outline-warning w-100">
                <p class="h2 pt-1">Promuovi mySpace</p>
            </a>
        </div>
        <div class="col">
            <!-- Promuovi Facebook -->
            <a href="promuovi?id=2" class="btn btn-outline-primary w-100">
                <p class="h2 pt-1">Promuovi Facebook</p>
            </a>
        </div>
        <!-- Promuovi TikTok -->
        <div class="col">
            <a href="promuovi?id=3" class="btn btn-outline-danger w-100">
                <p class="h2 pt-1">Promuovi TikTok</p>
            </a>
        </div>
    </div>

    <hr>
</div>

<!-- Modale per l'aggiunta di un corso -->
<div class="modal fade text-light" id="aggiungiCorso" tabindex="-1" aria-labelledby="aggiungiCorso" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5">Inserire dati:</h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
            </div>
            <div class="modal-body">
                <div class="row">
                    <div class="col">
                        <!-- Dati corso (descrizione, numeroIscritti, postiTotali) -->
                        <!-- Descrizione -->
                        <div class="form-floating">
                            <input type="text" name="descrizione" id="descrizione" class="form-control" placeholder="Descrizione">
                            <label for="descrizione">Descrizione</label>
                        </div>
                        <hr>
                        <!-- Numero iscritti -->
                        <div class="form-floating">
                            <input type="number" name="numeroIscritti" id="numeroIscritti" class="form-control" placeholder="Numeri Iscritti">
                            <label for="numeroIscritti">Numero iscritti</label>
                        </div>
                        <hr>
                        <!-- PostiTotali -->
                        <div class="form-floating">
                            <input type="number" name="postiTotali" id="postiTotali" class="form-control" placeholder="Posti Totali">
                            <label for="postiTotali">Posti totali</label>
                        </div>
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
                        <button type="button" class="btn btn-danger w-100" onclick="inserisciCorso()">Esegui</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Modale per la modifica di un corso -->
<div class="modal fade text-light" id="modificaCorso" tabindex="-1" aria-labelledby="modificaCorso" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
            <div class="modal-header">
                <h1 class="modal-title fs-5">Dati modificati:</h1>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
            </div>
            <div class="modal-body">
                <div class="row">
                    <div class="col">
                        <!-- Dati corso (descrizione, numeroIscritti, postiTotali) -->
                        <!-- Descrizione -->
                        <div class="form-floating">
                            <input type="text" name="descrizioneModificata" id="descrizioneModificata" class="form-control" placeholder="Descrizione">
                            <label for="descrizione">Descrizione</label>
                        </div>
                        <hr>
                        <!-- Numero iscritti -->
                        <div class="form-floating">
                            <input type="number" name="numeroIscrittiModificato" id="numeroIscrittiModificato" class="form-control" placeholder="Numeri Iscritti">
                            <label for="numeroIscritti">Numero iscritti</label>
                        </div>
                        <hr>
                        <!-- PostiTotali -->
                        <div class="form-floating">
                            <input type="number" name="postiTotaliModificato" id="postiTotaliModificato" class="form-control" placeholder="Posti Totali">
                            <label for="postiTotali">Posti totali</label>
                        </div>
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
                        <button type="button" class="btn btn-danger w-100" onclick="modificaCorso()">Esegui</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>
