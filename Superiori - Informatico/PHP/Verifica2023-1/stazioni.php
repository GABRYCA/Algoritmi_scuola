<?php
session_start();

// Controllo se esiste la sessione, se esiste rimando alla pagina squadre.php
if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit;
}

if (isset($_GET['stazione']) && isset($_GET['tempMax']) && isset($_GET['tempMin'])) {
    $timestamp = time();

    $stazione = $_GET['stazione'];
    $tempMax = $_GET['tempMax'];
    $tempMin = $_GET['tempMin'];
    $esiste = false;

    if (file_exists("stazioni.txt")){
        $esiste = true;
    }

    // Salvo i dati sul file con il formato: stazione timestamp tempMax tempMin
    $file = fopen("stazioni.txt", "a");

    if ($file) {
        if ($esiste){
            fwrite($file, "\n");
        }
        fwrite($file, $stazione . " " . $timestamp . " " . $tempMax . " " . $tempMin);
    }

    fclose($file);

    echo "<p class='h6 text-center text-success mt-2'>Dato inserito con successo!</p>";
}

// Array con i nomi delle stazioni
$stazioni = array("Trento", "Milano", "Torino", "Firenze", "Bologna", "Roma", "Napoli", "Bari", "Messina");

?>
<html>
<head>
    <meta charset="UTF-8">
    <title>Verifica - Stazioni - GCA</title>
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

<div class="container mt-3">
    <div class="row">
        <div class="col">
            <p class="h2 text-center">Inserisci dati:</p>
        </div>
    </div>
    <hr>
    <div class="row border border-dark rounded-3 p-3">
        <div class="col">

            <form method="get" action="<?php echo $_SERVER['PHP_SELF'];?>">
                <p class="h3 text-center">Seleziona stazione:</p>
                <div class="row">
                    <div class="col">
                        <select class="form-select" name="stazione" aria-label="Default select example">
                            <?php
                            foreach ($stazioni as $stazione) {
                                echo "<option value='$stazione'>$stazione</option>";
                            }
                            ?>
                        </select>
                    </div>
                </div>
                <div class="row mt-3">
                    <div class="col">
                        <label for="tempMax" class="form-label">Temperatura massima:</label>
                        <input type="number" class="form-control" name="tempMax" placeholder="Temperatura massima" max="50">
                    </div>
                    <div class="col">
                        <label for="tempMax" class="form-label">Temperatura minima:</label>
                        <input type="number" class="form-control" name="tempMin" placeholder="Temperatura minima" max="50">
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <button type="submit" class="btn btn-primary mt-3 w-100">Invia</button>
                    </div>
                </div>
            </form>

        </div>
    </div>

    <hr>

    <div class="row">
        <div class="col">
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
