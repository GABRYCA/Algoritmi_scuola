<?php
session_start();

if (isset($_SESSION['username'])){
    header("Location: collegato.php");
    exit;
}

if (!isset($_POST['username']) || !isset($_POST['password'])){
    header("Location: login.php");
    exit;
}

// Apro il file credenziali.txt in lettura e leggo le credenziali
$file = fopen("credenziali.txt", "r");
$linea = fgets($file);
$linea = rtrim($linea);
$credenziali = explode(" ", $linea);
fclose($file);

// Controllo se le credenziali inserite corrispondono a quelle nel file
if ($_POST['username'] == $credenziali[0] && $_POST['password'] == $credenziali[1]){
    $_SESSION['username'] = $_POST['username'];
    header("Location: collegato.php");
    exit;
} else {
    echo "<h3>Credenziali errate.</h3>";
}

?>