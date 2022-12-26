<?php
// Prendo dal post le informazioni di registrazione
$username = $_POST['username'];
$password = $_POST['password'];
$email = $_POST['email'];

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
        if ($dati[0] == $password || $dati[1] == $username) {
            // Se sono corretti stampo il messaggio di errore
            echo "Username o email già esistenti";

            // Avviso che sarà rimandato alla pagina di registrazione
            header("refresh: 3; url=login.html");
            return;
        }
    }
    // Chiudo il file
    fclose($fp);
}

// Rimuovo tutti gli spazi dal nome utente.
$username = str_replace(" ", "_", $username);

// Creo una stringa con i dati dell'utente
$riga = $username . " " . $password . " " . $email . "\n";

// Apro il file in scrittura
$fp = fopen("dati.txt", "a");
// Scrivo la riga nel file
fwrite($fp, $riga);

// Chiudo il file
fclose($fp);

// Stampo il messaggio di benvenuto
echo "<h1 style='text-align: center'>Registrato con successo " . $username . "!</h1>";

// Avviso che sarà rimandato alla pagina di login
echo "Stai per essere reindirizzato alla pagina di login entro 3 secondi...";

header("refresh: 3; url=login.html");
?>
