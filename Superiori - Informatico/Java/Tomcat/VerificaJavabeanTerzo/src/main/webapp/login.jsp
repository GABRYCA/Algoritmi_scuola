<%@ page contentType="text/html;charset=UTF-8" language="java" %>
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
    <title>Formativa</title>
</head>
<body class="font-monospace text-light bg-black">

<%
    // Verifico se esiste la sessione.
    if (session.getAttribute("loggedin") != null && (boolean) session.getAttribute("loggedin")) {
        response.sendRedirect("principale.jsp");
        return;
    }
%>

<!-- Form di login -->
<div class="container">
    <div class="row">
        <div class="col">
            <p class="h1 text-center mt-3 mb-3">Login:</p>
        </div>
    </div>

    <p class="text-center text-danger">${error}</p>

    <!-- Tramite form chiedo e invio i dati per l'autenticazione -->
    <form action="autenticazione" method="post">
        <div class="row">
            <div class="col">
                <div class="form-floating">
                    <input type="text" class="form-control" id="floatingInput" placeholder="Nome Stazione" name="nomeStazione">
                    <label for="floatingInput">Nome Stazione</label>
                </div>
                <hr>
                <div class="form-floating">
                    <input type="password" class="form-control" id="floatingPassword" placeholder="Pin" name="pin">
                    <label for="floatingPassword">Pin</label>
                </div>
            </div>
        </div>
        <hr>
        <div class="row">
            <div class="col">
                <button type="submit" class="btn btn-primary w-100">Accesso</button>
            </div>
        </div>
    </form>
</div>




<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>