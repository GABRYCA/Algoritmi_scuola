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
    $tempFile = fopen("temp.txt", "a");

    $contatore = 0;

    // Leggo il file riga per riga
    while (!feof($fp)) {
        // Salvo la riga in una variabile
        $riga = fgets($fp);
        // trim
        $riga = rtrim($riga);
        // Divido la riga in un array
        $dati = explode(" ", $riga);

        // Verifico se la domanda è corretta
        if ($dati[0] == $risposte[$contatore]) {
            // Stampo una riga comunicando che la risposta è corretta
            echo "<h1 style='text-align: center'>La risposta alla domanda numero: " . $contatore . " è corretta!</h1>";
        } else {
            // Stampo una riga comunicando che la risposta è sbagliata
            echo "<h1 style='text-align: center'>La risposta alla domanda numero: " . $contatore . " è sbagliata!</h1>";
        }

        // Se ha risposto vero, incremento dati[1] (numero di risposte vere)
        // Se ha risposto falso, incremento dati[2] (numero di risposte false)
        if ($risposte[$contatore] == "true") {
            $dati[1]++;
        } else {
            $dati[2]++;
        }

        // Stampo una riga comunicando le risposte statistiche
        echo "<h1 style='text-align: center'>Numero persone che hanno risposto vero: " . $dati[1] . " - e falso: " . $dati[2] . "</h1>";
        echo "<hr>";

        // Scrivo la riga aggiornata nel file
        fwrite($tempFile, $dati[0] . " " . $dati[1] . " " . $dati[2]);
        // Se la riga non è l'ultima, aggiungo un a capo
        if (!feof($fp)) {
            fwrite($tempFile, "\n");
        }
        $contatore++;
    }
    // Chiudo il file
    fclose($fp);
    fclose($tempFile);
    unlink("risposte.txt");
    rename("temp.txt", "risposte.txt");
    return;
} else {



    return;
}


?>