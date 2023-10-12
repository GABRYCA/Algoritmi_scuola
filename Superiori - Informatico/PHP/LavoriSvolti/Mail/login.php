<?php
// Salvo dal post nome utente e password
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

        $usernameFile = $dati[6] ?? null;

        // Verifico se l'username e la password sono corretti
        if ($usernameFile == $username && $dati[7] == $password) {
            // Se sono corretti verifico se la password è scaduta
            if (date("d-m-Y") == $dati[8]) {
                // Se non è scaduta stampo il messaggio di benvenuto
                echo "<h1 style='text-align: center'>Benvenuto " . $dati[6] . "</h1>";

                // Stampo i dati dell'utente
                echo "<br>Nome: " . $dati[0];
                echo "<br>Cognome: " . $dati[1];
                echo "<br>Data di nascita: " . $dati[2];
                echo "<br>Indirizzo: " . $dati[3];
                echo "<br>Città: " . $dati[4];
                echo "<br>Email: " . $dati[5];
                echo "<br>Username: " . $dati[6];
                echo "<br>Data registrazione: " . $dati[8];
                echo "<br>Ora registrazione: " . $dati[9];

                return;
            } else {
                // Se è scaduta stampo il messaggio di errore
                echo "Password scaduta";
                return;
            }
        } else {
            // Se non sono corretti stampo il messaggio di errore
            echo "Username o password errati";

            // Avviso che sarà rimandato alla pagina di login
            header("refresh: 3; url=login.html");
            return;
        }
    }
    // Chiudo il file
    fclose($fp);
    return;
} else {
    // Se il file non esiste stampo il messaggio di errore
    echo "Non ci sono utenti registrati!";

    // Avviso che sta per essere reindirizzato alla pagina di registrazione
    echo "Stai per essere reindirizzato alla pagina di registrazione entro 5 secondi";
    // Reindirizzo alla pagina di registrazione
    header("refresh:5;url=registrazione.html");
}
?>
