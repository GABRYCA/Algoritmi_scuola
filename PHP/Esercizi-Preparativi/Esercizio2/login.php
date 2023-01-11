<?php
session_start();

if (isset($_SESSION['username'])){
    echo "<h3>Già loggato!</h3>";

    // Redirect a pagina dei videogiochi
    header("Location: videogiochi.php");
    return;
}

// Ottengo dati dal post (username e password)
$username = $_POST['username'];
$password = $_POST['password'];

// Leggo credenziali da file credenziali.txt
$credenziali = fopen("credenziali.txt", "r");

// Controllo se le credenziali sono corrette
while (!feof($credenziali)) {
    $line = fgets($credenziali);
    $line = rtrim($line);
    $line = explode(" ", $line);

    if ($line[0] == $username && $line[1] == $password) {
        // Credenziali corrette
        $_SESSION['username'] = $username;

        // Redirect a pagina dei videogiochi
        header("Location: videogiochi.php");
        fclose($credenziali);
        return;
    }
}

fclose($credenziali);


?>
