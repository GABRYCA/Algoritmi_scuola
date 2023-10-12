<?php
session_start();

// Controllo se esiste la sessione, se esiste rimando alla pagina squadre.php
if (isset($_SESSION['username'])) {
    header("Location: squadre.php");
    exit;
}

// Prendo email e password e li paragono con quelli in credenziali.txt
$email = $_POST['email'];
$password = $_POST['password'];

$credenziali = fopen("credenziali.txt", "r");

// Controllo se le credenziali sono corrette
while (!feof($credenziali)) {
    $line = fgets($credenziali);
    $line = rtrim($line);
    $line = explode(" ", $line);

    if ($line[0] == $email && $line[1] == $password) {
        // Credenziali corrette
        $_SESSION['username'] = $email;

        // Redirect a pagina dei videogiochi
        header("Location: squadre.php");
        fclose($credenziali);
        return;
    }
}

fclose($credenziali);

header("Location: login.html");
?>
