<?php
session_start();

if (!isset($_SESSION['username'])) {

    // Redirect a pagina dei videogiochi
    header("Location: login.html");
    return;
}
?>
<html>
<head>
    <meta charset="UTF-8">
    <title>Esercizio 1 - Classifica - GCA</title>
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
            <p class="h1 text-center mt-3">Classifica:</p>
        </div>
    </div>

    <hr>

    <div class="row">
        <div class="col text-center">
            <a class="btn btn-outline-primary" href="squadre.php">Torna alla pagina delle squadre</a>
            <a class="btn btn-outline-primary" href="riepilogo.php">Torna alla pagina di riepilogo</a>
        </div>
    </div>

    <hr>

    <!-- Riepilogo di tutte le squadre nella $_SESSION['squadre'] -->
    <?php
    if (isset($_SESSION['squadre'])) {
        // Il formato del vettore è:
        // array($squadraCasa, $punteggioCasa, $squadraOspite, $punteggioOspite);
        // Stampa la classifica ordinata e calcolata assegnando 3 punti per la vittoria, 1 per il pareggio e 0 per la sconfitta.

        $classifica = array();

        // Inizializzo la classifica con tutte le squadre e un punteggio di 0
        foreach ($_SESSION['squadre'] as $squadra) {
            $classifica[$squadra[0]] = 0;
            $classifica[$squadra[2]] = 0;
        }

        foreach ($_SESSION['squadre'] as $squadra) {
            if ($squadra[1] == $squadra[3]){
                $classifica[$squadra[0]] += 1;
                $classifica[$squadra[2]] += 1;
            } else if ($squadra[1] > $squadra[3]){
                $classifica[$squadra[0]] += 3;
                $classifica[$squadra[2]] += 0;
            } else {
                $classifica[$squadra[2]] += 3;
                $classifica[$squadra[0]] += 0;
            }
        }

        arsort($classifica);
        $i = 1;
        foreach ($classifica as $key => $value) {
            echo "<div class='row'>
                    <div class='col text-center'>
                        <p class='h3'>" . $i. "°" . " - " . $key . " - " . $value . " punti</p>
                    </div>
                </div>";
            $i++;
        }
    } else {
        echo "<div class='row'>
                <div class='col'>
                    <p class='text-center mt-3 h4'>Non ci sono squadre</p>
                </div>
              </div>";
    }
    ?>

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
