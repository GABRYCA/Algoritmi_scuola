<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Esercizio 2 - Login - GCA</title>
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
<body>

<div class="container mt-5 mb-5">

<?php
session_start();
if ($_SESSION['username'] == null) {
    header("Location: login.html");
    return;
}

if (isset($_POST['videogioco']) && isset($_POST['punteggio'])){
    $videogioco = $_POST['videogioco'];
    $punteggio = $_POST['punteggio'];

    // Creo una copia temporanea del file e copio tutti i valori, poi ne creo uno nuovo con i valori aggiornati compreso quello
    // del videogioco appena modificato
    $file = fopen("videogiochi.txt", "r");
    $fileTemp = fopen("videogiochiTemp.txt", "w");

    while (!feof($file)) {
        $line = fgets($file);
        $line = rtrim($line);
        $line = explode(" ", $line);

        if (count($line) != 2) {
            continue;
        }

        if ($line[0] == $videogioco) {
            if ($line[1] < $punteggio) {
                $line[1] = $punteggio;
            }
        }

        fwrite($fileTemp, $line[0] . " " . $line[1]);
        fwrite($fileTemp, "\r\n");
    }

    fclose($file);
    fclose($fileTemp);

    unlink("videogiochi.txt");
    rename("videogiochiTemp.txt", "videogiochi.txt");
}

// Apro il file videogiochi.txt e creo un vettore associativo con nomegioco : punteggio letto da file
$videogiochi = fopen("videogiochi.txt", "r");
$videogiochiArray = array();

while (!feof($videogiochi)) {
    $line = fgets($videogiochi);
    $line = rtrim($line);
    $line = explode(" ", $line);

    // Controllo se il vettore line ha 2 elementi
    if (count($line) != 2) {
        continue;
    }

    $videogiochiArray[$line[0]] = $line[1];
}
fclose($videogiochi);

foreach ($videogiochiArray as $nomegioco => $punteggio) {
    // Per ogni videogioco stampo un form con nomevideogioco e punteggio, dal quale è possibile
    // modificare il punteggio che verrà salvato sul file.
    echo "<form action='videogiochi.php' method='post'>";
    echo "<div class='row'>";
    echo "<div class='col-6'>";
    echo "<h1>" . ucfirst($nomegioco) . "</h1>";
    echo "<input type='hidden' name='videogioco' value='$nomegioco'>";
    echo "<div class='row'>";
    echo "<div class='col'><input class='form-control' type='number' name='punteggio' value='$punteggio'></div>";
    echo "<div class='col'><input class='btn btn-outline-primary' type='submit' value='Salva'></div>";
    echo "</div></div></div></form>";
    echo "<hr>";
}

?>

    <div class="row">
        <div class="col">
            <!-- Pulsante per aprire la pagina riepilogo.php -->
            <a href="riepilogo.php" class="btn btn-outline-primary w-100">Riepilogo</a>
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