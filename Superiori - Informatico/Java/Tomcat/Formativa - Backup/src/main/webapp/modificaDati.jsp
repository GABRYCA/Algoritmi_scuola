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
        return;
    }

    // Carico UtenteBean dall'id.
    int id = (int) session.getAttribute("id");
    UtenteBean utente = new UtenteBean();
    utente.setId(id);
    if (!utente.selectUtente()){
        out.println("Errore durante il caricamento dell'utente con id " + id);
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
    <title>Dati Utente</title>
</head>
<body class="font-monospace text-light bg-black">

<div class="container">
    <div class="row mt-3">
        <div class="col">
            <p class="h1 text-center">Dati utente:</p>
        </div>
    </div>
    <hr>
    <div class="row mt-3 justify-content-center text-center">
        <div class="col">
            <p class="h3">Username: <span class="text-warning"><%= utente.getUsername() %></span></p>
        </div>
        <div class="col">
            <p class="h3">Nome: <span class="text-warning"><%= utente.getNome() %></span></p>
        </div>
        <div class="col">
            <p class="h3">Cognome: <span class="text-warning"><%= utente.getCognome() %></span></p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <!-- Ritorna al contoCorrente -->
            <a href="contoCorrente.jsp" class="btn btn-outline-warning btn-lg w-100">Torna al conto corrente.</a>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <p class="h3 text-center mt-4">Modifica dati:</p>
        </div>
    </div>
    <hr>
    <!-- Form per la modifica dei dati (precompilato con i dati già presenti) -->
    <div class="row">
        <div class="col">
            <form action="modificaDatiUtente" method="post">
                <div class="row">
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="text" class="form-control" id="username" placeholder="Username"
                                   name="username" value="<%= utente.getUsername() %>">
                            <label for="username">Username</label>
                        </div>
                    </div>
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="text" class="form-control" id="nome" placeholder="Nome"
                                   name="nome" value="<%= utente.getNome() %>">
                            <label for="nome">Nome</label>
                        </div>
                    </div>
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="text" class="form-control" id="cognome" placeholder="Cognome"
                                   name="cognome" value="<%= utente.getCognome() %>">
                            <label for="cognome">Cognome</label>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col">
                            <button type="submit" class="btn btn-outline-warning btn-lg w-100">Salva</button>
                        </div>
                    </div>
                </div>
            </form>
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
