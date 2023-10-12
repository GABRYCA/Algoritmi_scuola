<?php
session_start();

if (!isset($_SESSION['username'])) {

    // Redirect a pagina dei videogiochi
    header("Location: login.html");
    return;
}

if (isset($_POST['squadraCasa']) && isset($_POST['squadraOspite'])) {
    $squadraCasa = $_POST['squadraCasa'];
    $squadraOspite = $_POST['squadraOspite'];
    $punteggioCasa = $_POST['puntiCasa'];
    $punteggioOspite = $_POST['puntiOspite'];

    if ($squadraCasa == $squadraOspite) {
        echo "<p class='text-center text-danger mt-3 h4'>Squadra casa e squadra ospite devono essere diverse!</p>";
    } else {

        // Controllo se in session c'è già una coppia di squadre squadraCasa-squadraOspite, se c'è aggiorno il valore.
        // Altrimenti lo inserisco.
        $presente = false;
        $numero = 0;
        if (isset($_SESSION['squadre'])){
            foreach ($_SESSION['squadre'] as $squadra) {
                if ($squadra[0] == $squadraCasa && $squadra[2] == $squadraOspite) {
                    $squadra[1] = $punteggioCasa;
                    $squadra[3] = $punteggioOspite;
                    // Aggiorno il valore in sessione
                    $_SESSION['squadre'][$numero] = $squadra;
                    echo "<p class='text-center text-success mt-3 h4'>Punteggio aggiornato!</p>";
                    $presente = true;
                    $numero++;
                }
            }
        }

        if (!$presente){
            $_SESSION['squadre'][] = array($squadraCasa, $punteggioCasa, $squadraOspite, $punteggioOspite);
        }
    }
}
?>
<html>
<head>
    <meta charset="UTF-8">
    <title>Esercizio 1 - Squadre - GCA</title>
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
            <p class="h1 text-center mt-3">Squadre:</p>
        </div>
    </div>

    <?php
    // Stampo le squadre salvate nell'array SESSION se ci sono
    if (isset($_SESSION['squadre'])) {
        // Stampo squadraCasa - squadraOspite
        // punteggioCasa - punteggioOspite
        foreach ($_SESSION['squadre'] as $squadra) {
            echo "<div class='row'>
                <div class='col'>
                    <p class='text-center mt-3 h4'>$squadra[0] - $squadra[2]</p>
                </div>
              </div>
              <div class='row'>
                <div class='col'>
                    <p class='text-center mt-3 h4'>$squadra[1] - $squadra[3]</p>
                </div>
              </div>
              <hr>";
        }

        echo "<div class='row'>
                <div class='col'>
                    <a class='btn btn-outline-primary text-center mt-3 h4 w-100' href='riepilogo.php'>Riepilogo</a>
                    <a class='btn btn-outline-primary text-center mt-3 h4 w-100' href='classifica.php'>Classifica</a>
                </div>
              </div>";
    }
    ?>
    <hr>

    <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
        <!-- Combobox contenete le squadre -->
        <div class="row">
            <div class="col">
                <p class="h3">Squadra di casa</p>
                <select class="form-select" name="squadraCasa" id="squadraCasa" required>
                    <option value="0" disabled>Seleziona squadra</option>
                    <option value="Inter">Inter</option>
                    <option value="Milan">Milan</option>
                    <option value="Juventus">Juventus</option>
                    <option value="Roma">Roma</option>
                    <option value="Napoli">Napoli</option>
                </select>
                <!-- Input per il numero di punti -->
                <div class="row mt-3">
                    <div class="col-2">
                        <label for="puntiCasa" class="form-label mt-2">Punti</label>
                    </div>
                    <div class="col-10">
                        <input type="number" class="form-control" name="puntiCasa" id="puntiCasa" min="0" required>
                    </div>
                </div>
            </div>
            <div class="col">
                <p class="h3">Squadra ospite</p>
                <select class="form-select" name="squadraOspite" id="squadraOspite" required>
                    <option value="0" disabled>Seleziona squadra</option>
                    <option value="Inter">Inter</option>
                    <option value="Milan">Milan</option>
                    <option value="Juventus">Juventus</option>
                    <option value="Roma">Roma</option>
                    <option value="Napoli">Napoli</option>
                </select>
                <!-- Input per il numero di punti -->
                <div class="row mt-3">
                    <div class="col-2">
                        <label for="puntiOspite" class="form-label mt-2">Punti</label>
                    </div>
                    <div class="col-10">
                        <input type="number" class="form-control" name="puntiOspite" id="puntiOspite" min="0" required>
                    </div>
                </div>
            </div>
        </div>
        <hr>
        <div class="row">
            <div class="col">
                <!-- Submit -->
                <button type="submit" class="btn btn-primary mt-3 w-100">Invia</button>
            </div>
        </div>
    </form>


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
