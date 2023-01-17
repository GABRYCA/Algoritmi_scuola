<?php
session_start();

if (isset($_GET['nomeEvento']) && isset($_GET['numeroPersone'])) {
    if (isset($_SESSION['eventi'])) {
        $eventi = $_SESSION['eventi'];

        // Verifico se in eventi è già presente un evento con lo stesso nome, nel caso lo sia, sommo al numero di persone precedente
        // la nuova quantità inserita
        $trovato = false;
        $numero = 0;
        foreach ($_SESSION['eventi'] as $evento) {
            if ($evento[0] == $_GET['nomeEvento']) {
                $evento[1] = $evento[1] + $_GET['numeroPersone'];
                // Aggiorno il valore in sessione
                $_SESSION['eventi'][$numero] = $evento;
                echo "<p class='text-center text-success mt-3 h4'>Prenotazione aggiornata!</p>";
                $trovato = true;
                $numero++;
            }
        }

        // Se non è stato trovato un evento con lo stesso nome, lo aggiungo
        if (!$trovato) {
            $_SESSION['eventi'][] = array($_GET['nomeEvento'], $_GET['numeroPersone']);
        }
    } else {
        $_SESSION['eventi'] = array();
        $_SESSION['eventi'][] = array($_GET['nomeEvento'], $_GET['numeroPersone']);
    }
}

?>
<html>
<head>
    <meta charset="UTF-8">
    <title>Esercizio 2 - Inserisci - GCA</title>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer"/>
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

<div class="container">

    <div class="row">
        <div class="col">
            <p class="h1 text-center mt-3">Inserimento prenotazioni:</p>
        </div>
    </div>

    <hr>

    <div class="row">
        <div class="col text-center">
            <a class="h3 btn btn-outline-primary" href="prenotazioni.php">Visualizza prenotazioni</a>
        </div>
    </div>

    <hr>

    <div class="row">
        <div class="col">
            <!-- Form con inserimento nome-evento, numero persone -->
            <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="get">
                <div class="mb-3">
                    <label for="nomeEvento" class="form-label">Nome evento:</label>
                    <input type="text" class="form-control" id="nomeEvento" name="nomeEvento" required>
                </div>
                <div class="mb-3">
                    <label for="numeroPersone" class="form-label text-center">Numero persone:</label>
                    <input type="number" class="form-control" id="numeroPersone" name="numeroPersone" required>
                </div>
                <button type="submit" class="btn btn-primary w-100">Invia</button>
            </form>
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
