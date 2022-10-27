<?php
// Prendo dati miglia e chilometri

if (!isset($_GET['miglia']) && !isset($_GET['KM'])){
    echo "Inserire dei dati!";
    return;
}

$miglia = $_GET['miglia'];
$chilometri = $_GET['km'];

// Controllo se sono entrambi vuoti, e allora invio un messaggio di errore
if (empty($miglia) && empty($chilometri)) {
    echo "Inserisci un valore";
} else {
    // Controllo se è stato inserito un valore in miglia
    if (!empty($miglia)) {
        // Converto miglia in chilometri
        $chilometri = $miglia * 1.609344;
        // Stampo il risultato
        echo "$miglia miglia corrispondono a $chilometri chilometri";
    } else {
        // Converto chilometri in miglia
        $miglia = $chilometri / 1.609344;
        // Stampo il risultato
        echo "$chilometri chilometri corrispondono a $miglia miglia";
    }
}

?>