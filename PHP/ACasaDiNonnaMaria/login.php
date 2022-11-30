<?php
session_start();
?>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>La casa di nonna Maria</title>
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
<body class="bg-dark bg-opacity-75 text-light font-monospace">
<div class="container-fluid">
    <div class="row justify-content-center bg-dark pt-1 rounded-bottom">
        <!-- Titolo A casa di Nonna Maria -->
        <div class="col-12">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <h1 class="text-center">A casa di Nonna Maria</h1>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<hr>

<div class="container">

    <div class="row">
        <div class="col">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <h2 class="text-center">Login:</h2>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <?php

    // Tramite SESSION salvo il login confrontandolo con i dati username e password interni, nel caso sia
    // già loggato allora non lo fa loggare nuovamente e mostra un'altra pagina, nel caso non lo sia stampo
    // il form di login qui sotto.

    // Controllo se esiste già la sessione:
    if (isset($_SESSION['username'])) {
        // Se esiste già la sessione, allora non faccio vedere il form di login e lo reindirizzo alla pagina
        // di benvenuto.
        header("Location: prodotti.php");
    } else {

        // Controllo se sono in stato di POST, se lo sono allora controllo se i dati inseriti sono corretti
        // e se lo sono allora creo la sessione e reindirizzo alla pagina di benvenuto.
        if (isset($_POST['username']) && isset($_POST['password'])) {

            // Verifico se esiste files/accounts.txt, se non esiste lo creo.
            // e aggiungo una riga con struttura:
            // username password
            // Di default:
            // admin admin
            if (!file_exists('files/accounts.txt')) {
                $file = fopen('files/accounts.txt', 'w');
                fwrite($file, "admin admin");
                fclose($file);
            }

            // Apro il file files/accounts.txt e leggo il contenuto:
            // username password
            // Divisi da uno spazio, e li salvo in un vettore associativo.
            $file = fopen("files/accounts.txt", "r");
            $accounts = array();
            while (!feof($file)) {
                $line = fgets($file);
                // rtrim rimuove gli spazi vuoti alla fine della stringa.
                $line = rtrim($line);
                $line = explode(" ", $line);
                $accounts[$line[0]] = $line[1];
            }
            fclose($file);

            $username = $_POST['username'];
            $password = $_POST['password'];

            if (isset($accounts[$username]) && $accounts[$username] == $password) {

                // Se i dati inseriti sono corretti, allora creo la sessione e reindirizzo alla pagina di benvenuto.
                $_SESSION['username'] = $_POST['username'];

                // Inizializzo in SESSION un carrello vuoto a matrice:
                $_SESSION['carrello'] = array();

                header("Location: prodotti.php");
                return;
            } else {
                // Se i dati inseriti non sono corretti, allora stampo un messaggio di errore.
                echo '<div class="row">
                        <div class="col">
                            <div class="container">
                                <div class="row">
                                    <div class="col-12">
                                        <h3 class="text-center">Username o password errati!</h3>
                                   
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <hr>';
            }
        }

    ?>

    <div class="row border border-dark rounded-3 pt-2 bg-dark bg-opacity-25 shadow">
        <div class="col">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <form action="login.php" method="post">
                            <div class="mb-3">
                                <label for="username" class="form-label">Username</label>
                                <input type="text" class="form-control" id="username" name="username" required>
                            </div>
                            <div class="mb-3">
                                <label for="password" class="form-label">Password</label>
                                <input type="password" class="form-control" id="password" name="password" required>
                            </div>
                            <button type="submit" class="btn btn-primary w-100">Login</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <?php
    }
    ?>

    <hr class="mt-5 mb-5">

    <div class="row justify-content-start">
        <div class="col">
            <!-- Tasto torna indietro alla homepage.html -->
            <a href="homepage.html" class="btn btn-primary w-100 mt-2">Torna alla homepage</a>
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
