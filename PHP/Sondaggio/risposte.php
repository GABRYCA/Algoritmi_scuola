<?php
session_start();

// Verifico se l'utente è loggato
if (!isset($_SESSION['username'])) {
    // Se non è loggato stampo il messaggio di errore
    echo "<h1 style='text-align: center'>Non sei loggato!</h1>";

    // Avviso che sarà rimandato alla pagina di login
    echo "Stai per essere reindirizzato alla home entro 3 secondi...";

    header("refresh: 3; url=index.html");
    return;
}

// Prendo i dati dal post (domanda1, domanda2, domanda3 etc...)
$risposte = $_POST;

// Verifico se il file risposte.txt esiste
// Se esiste leggo il file e mi salvo le risposte corrette e le sue statistiche
// Se non esiste creo il file e scrivo le risposte corrette e le statistiche aggiornate con l'utente che ha risposto
if (file_exists("risposte.txt")) {
    // Se esiste apro il file in lettura
    $fp = fopen("risposte.txt", "r");
    // Leggo il file riga per riga
    while (!feof($fp)) {
        // Salvo la riga in una variabile
        $riga = fgets($fp);
        // trim
        $riga = rtrim($riga);
        // Divido la riga in un array
        $dati = explode(" ", $riga);

        // Verifico se la domanda è corretta
        if ($dati[0] == $risposte[$dati[0]]) {
            // Se è corretta aggiorno le statistiche
            $dati[1] = $dati[1] + 1;
            $dati[2] = $dati[2] + 1;
        } else {
            // Se è sbagliata aggiorno le statistiche
            $dati[2] = $dati[2] + 1;
        }
    }
    // Chiudo il file
    fclose($fp);
    return;
} else {


    return;
}


?>