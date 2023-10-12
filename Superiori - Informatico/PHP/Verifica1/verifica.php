<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Esercizio 6 di G.C.</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
</head>
<body class="text-center bg-dark text-light">
<br>
<?php
/* Cose da fare:
- Stampare un messaggio di errore per ogni campo non compilato (minuendo, sottraendo, differenza)
- Stampare un messaggio di errore se qualche campo inserito non è un numero
- Stampare un messaggio di errore se sottraendo è maggiore di minuendo
- Stampare un messaggio di errore se il valore differenza è diverso dal numero ottenuto da minuendo - sottraendo
- mostri una immagine con una spunta verde nel caso sia corretto l'inserimento
*/

// Controllo se i campi sono stati compilati
if ($_POST['minuendo'] != null && $_POST['sottraendo'] != null && $_POST['differenza'] != null){

    // Controllo se i campi sono numeri
    if (is_numeric($_POST['minuendo']) && is_numeric($_POST['sottraendo']) && is_numeric($_POST['differenza'])){

        // Controllo se sottraendo è maggiore di minuendo
        if ($_POST['sottraendo'] > $_POST['minuendo']){
            echo "<p class='h1'>Il sottraendo non può essere maggiore del minuendo!</p><br>
            <img src='https://www.gran-turismo.com/gtsport/decal/5846332036256661512_1.png' alt='Errore'>";
        } else {

            // Controllo se differenza è uguale a minuendo - sottraendo
            if ($_POST['differenza'] != $_POST['minuendo'] - $_POST['sottraendo']){
                echo "<p class='h1'>La differenza non è corretta!</p><br>
            <img src='https://www.gran-turismo.com/gtsport/decal/5846332036256661512_1.png' alt='Errore'>";
            } else {
                echo "<p class='h1'>La differenza è corretta!</p><br>
                <img class='img-fluid' src='https://cdn.pixabay.com/photo/2022/07/04/01/58/hook-7300191__340.png' alt='spunta verde'>";
            }
        }
    } else {
        echo "<p class='h1'>Uno dei campi non è un numero!</p><br>
            <img src='https://www.gran-turismo.com/gtsport/decal/5846332036256661512_1.png' alt='Errore'>";
    }
} else {
    echo "<p class='h1'>Uno dei campi non è stato compilato!</p><br>
            <img src='https://www.gran-turismo.com/gtsport/decal/5846332036256661512_1.png' alt='Errore'>";
}
?>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
</body>
