<?php
session_start();

// Verifico se l'utente è loggato
if (isset($_SESSION['username'])) {
    // Se è loggato stampo il messaggio di benvenuto
    echo "<h1 style='text-align: center'>Sei già loggato come " . $_SESSION['username'] . "</h1>";

    // Avviso che sarà rimandato alla pagina di login
    echo "Stai per essere reindirizzato alla pagina dei sondaggi entro 3 secondi...";
    header("refresh: 3; url=sondaggi.php");
    return;
}

// Prendo i dati di login dal post
$username = $_POST['username'];
$password = $_POST['password'];

// Verifico se il file dati.txt esiste
if (file_exists("dati.txt")) {
    // Se esiste apro il file in lettura
    $fp = fopen("dati.txt", "r");
    // Leggo il file riga per riga
    while (!feof($fp)) {
        // Salvo la riga in una variabile
        $riga = fgets($fp);
        // trim
        $riga = rtrim($riga);
        // Divido la riga in un array
        $dati = explode(" ", $riga);

        // Verifico se l'username e la password sono corretti
        if ($dati[0] == $username && $dati[1] == $password) {

            // Se sono corretti creo la sessione
            $_SESSION['username'] = $username;

            // Stampo il messaggio di benvenuto
            echo "<h1 style='text-align: center'>Benvenuto " . $dati[0] . "</h1>";

            fclose($fp);

            // Avviso che sarà rimandato alla pagina di login
            echo "Stai per essere reindirizzato alla pagina del sondaggio entro 3 secondi...";

            header("refresh: 3; url=sondaggio.php");
            return;
        }
    }
    // Chiudo il file
    fclose($fp);

    // Se non sono stati trovati dati corretti stampo il messaggio di errore
    echo "Username o password errati";
    return;
} else {
    // Se il file non esiste stampo il messaggio di errore
    echo "Non ci sono utenti registrati!";

    // Avviso che sarà rimandato alla pagina di login
    echo "Stai per essere reindirizzato alla pagina di registrazione entro 3 secondi...";

    header("refresh: 3; url=registrati.html");
    return;
}
?>
