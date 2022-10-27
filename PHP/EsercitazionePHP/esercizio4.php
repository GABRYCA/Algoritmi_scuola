<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>G.C. Ristorante</title>
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
</head>
<body class="bg-dark text-light text-center">

<!--
Esercizio n°4
Crea un array associativo cognome – nome – numero di maglia dei calciatori o
pallavolisti e mostrali in un form in ordine di numero di maglia o di cognome, in base
a quanto deciso dall’utente.
-->

<?php

// Array associativo con dati a caso di persone pallavoliste, ossia nome, cognome, numero maglia
$players = [
    "Rossi" => ["Mario", 10],
    "Bianchi" => ["Luca", 5],
    "Verdi" => ["Giuseppe", 7],
    "Neri" => ["Giovanni", 3],
    "Gialli" => ["Marco", 1],
    "Blu" => ["Giorgio", 2],
    "Arancioni" => ["Giacomo", 4],
    "Viola" => ["Gianluca", 6]
    ];

if ($_POST == true) {

// Verifico quale dei due ordine radio è selezionato
    if ($_POST['ordine'] == "numeroMaglia") {
        // Ordino l'array per il numero di maglia (che è il secondo parametro dell'array associativo).
        foreach ($players as $key => $row) {
            $numeroMaglia[$key] = $row[1];
        }
        // La documentazione di PHP è bella.
        array_multisort($numeroMaglia, SORT_ASC, $players);
    } else if ($_POST['ordine'] == "cognome") {
        // Ordino l'array per il cognome
        ksort($players);
    }

// Stampo il vettore ordinato
    foreach ($players as $cognome => $dati) {
        echo "<p>$cognome $dati[0] $dati[1]</p>";
    }

} else {

?>


<div class="container">
    <div class="row">
        <form method="post" action="<?php echo $_SERVER['PHP_SELF']?>">
            <!-- Faccio scegliere all'utente se vuole stampare in ordine di numero di maglia o cognome -->
            <div class="col-12">
                <div class="row">
                    <div class="col">
                        <p class="h5">Numero di maglia:</p>
                    </div>
                    <div class="col">
                        <input class="form-check" type="radio" name="ordine" id="ordine1" value="numeroMaglia" checked>
                    </div>
                </div>
                <div class="row" style="margin-top: 10px">
                    <div class="col">
                        <p class="h5">Ordina per cognome:</p>
                    </div>
                    <div class="col">
                        <input class="form-check" type="radio" name="ordine" id="ordine2" value="cognome">
                    </div>
                </div>
            </div>
            <div class="col-12" style="margin-top: 20px">
                <button type="submit" class="btn btn-primary">Ordina</button>
            </div>
        </form>
    </div>
</div>
<?php
}
?>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>