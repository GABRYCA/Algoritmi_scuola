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
<body class="bg-dark">

<!--
Esercizio n°1
Creare un form che riceva una stringa in input e stampi:
• Il numero di consonanti e di vocali
• Il numero di caratteri uguali ad uno inserito sempre dall’utente
• Il numero di caratteri di tipo numerico
• La frequenza con cui un carattere inserito dall’utente si presenta
• Il numero di parole di cui è composta (ogni parola termina con un carattere di
punteggiatura o con lo spazio)
-->

<?php

// Creo un array con le vocali
$vocali = array("a", "e", "i", "o", "u");

// Creo un array con le consonanti
$consonanti = array("b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z");

// Conto il numero di vocali e consontanti presenti nella stringa
function contaVocaliConsonanti($stringa, $vocali, $consonanti){
    $contaVocali = 0;
    $contaConsonanti = 0;
    for ($i = 0; $i < strlen($stringa); $i++) {
        if (in_array($stringa[$i], $vocali)) {
            $contaVocali++;
        } elseif (in_array($stringa[$i], $consonanti)) {
            $contaConsonanti++;
        }
    }
    return array($contaVocali, $contaConsonanti);
}

// Prendo input dal form
if ($_POST == true){
    if (isset($_POST["stringa"])){
        $stringa = $_POST["stringa"];
        $stringa = strtolower($stringa);
        $contaVocaliConsonanti = contaVocaliConsonanti($stringa, $vocali, $consonanti);
        $contaVocali = $contaVocaliConsonanti[0];
        $contaConsonanti = $contaVocaliConsonanti[1];

        // Stampo un toast con il numero di vocali e consonanti
        echo "<script>$.toast({
            heading: 'Numero di vocali e consonanti',
            text: 'Vocali: $contaVocali, consonanti: $contaConsonanti',
            position: 'top-right',
            loaderBg: '#ff6849',
            icon: 'info',
            hideAfter: 10000,
            stack: 6
        })</script>";

        if (isset($_POST["carattere"])){
            $carattere = $_POST["carattere"];
            $carattere = strtolower($carattere);
            $contaCarattere = 0;
            for ($i = 0; $i < strlen($stringa); $i++) {
                if ($stringa[$i] == $carattere) {
                    $contaCarattere++;
                }
            }
            // Stampo un toast con il numero di caratteri uguali al carattere inserito
            echo "<script>$.toast({
                heading: 'Numero di caratteri uguali a $carattere e frequenza:',
                text: 'Numero: $contaCarattere<br>' +
                'Frequenza: " . round($contaCarattere / strlen($stringa) * 100, 2) . "%',
                position: 'top-right',
                loaderBg: '#ff6849',
                icon: 'info',
                hideAfter: 10000,
                stack: 6
            })</script>";
        }

        // Conto il numero di numeri della stringa
        $contaNumeri = 0;
        for ($i = 0; $i < strlen($stringa); $i++) {
            if (is_numeric($stringa[$i])) {
                $contaNumeri++;
            }
        }

        // Stampo un toast con il numero di numeri
        echo "<script>$.toast({
            heading: 'Numero di numeri:',
            text: '$contaNumeri',
            position: 'top-right',
            loaderBg: '#ff6849',
            icon: 'info',
            hideAfter: 10000,
            stack: 6
        })</script>";

        // Conto il numero di parole
        $contaParole = 1;
        for ($i = 0; $i < strlen($stringa); $i++) {
            if ($stringa[$i] == " " || $stringa[$i] == "." || $stringa[$i] == "," || $stringa[$i] == "!" || $stringa[$i] == "?") {
                $contaParole++;
            }
        }

        // Stampo un toast con il numero di parole
        echo "<script>$.toast({
            heading: 'Numero di parole:',
            text: '$contaParole',
            position: 'top-right',
            loaderBg: '#ff6849',
            icon: 'info',
            hideAfter: 10000,
            stack: 6
        })</script>";
    } else {
        // Stampo un toast d'errore che comunica all'utente che non è stato inserita una stringa
        echo "<script>$.toast({
            heading: 'Errore',
            text: 'Non hai inserito una stringa',
            icon: 'error',
            position: 'top-right',
            stack: false
        })</script>";
    }
}

?>

<div class="container text-center text-light">
    <p class="h1 text-light">Esercizio 1</p>

    <!-- Form per ottenere in input una stringa -->
    <form class="text-center" action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
        <div class="form-group">
            <input type="text" class="form-control" id="stringa" name="stringa" placeholder="Inserisci una stringa">
        </div>
        <br>
        <div class="form-group">
            <label for="carattere">Inserisci un carattere particolare da contare</label>
            <input type="text" class="form-control" id="carattere" name="carattere" placeholder="Carattere">
        </div>

        <button type="submit" class="btn btn-primary">Invia</button>
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