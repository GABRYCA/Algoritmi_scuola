<?php
include "connessione.php";
session_start();

// Check if user is already logged in, if yes then redirect him to profile page.
if (isset($_SESSION['loggedin'])) {
    header('Location: profilo.php');
    exit;
}

$con = connessione();

// Verifico se i dati sono stati inseriti.
if (!isset($_POST['username'], $_POST['password'])) {
    // Errore, non tutti i campi sono stati compilati.
    exit('Devi compilare tutti i campi necessari!');
}

// Controllo se username e password sono vuoti.
if (empty($_POST['username']) || empty($_POST['password'])) {
    // Errore, non tutti i campi sono stati compilati.
    exit('Devi compilare tutti i campi necessari!');
}

// Ottengo dati account con username specificato.
if ($stmt = $con->prepare('SELECT id_utente, password, activation_code FROM utente WHERE username = ?')) {
    // Parametri.
    $stmt->bind_param('s', $_POST['username']);
    $stmt->execute();
    // Salvo risultato.
    $stmt->store_result();

    if ($stmt->num_rows > 0) {
        $stmt->bind_result($id, $password, $activation_code);
        $stmt->fetch();

        // Account trovato, controllo password.
        // Uso l'hash della password inserita e la confronto con quella nel database.
        if (password_verify($_POST['password'], $password)) {

            // Successo, controllo se l'account è attivato.
            if (!$activation_code == 'activated') {
                // Account non attivato.
                exit('Il tuo account non è stato attivato, per favore controlla le tue email (e anche lo spam)!');
            }

            // Creo una nuova sessione.
            session_regenerate_id();
            $_SESSION['loggedin'] = TRUE; // Variabile per riconoscere se l'utente è loggato.
            $_SESSION['name'] = $_POST['username']; // Variabile per riconoscere il nome dell'utente.
            $_SESSION['id'] = $id; // Variabile per riconoscere l'id dell'utente nel database (utente.id_utente).

            echo 'Ciao ' . $_SESSION['name'] . ', ti sei loggato con successo! Per favore attendi un paio di secondi...';
            // Rimando alla pagina principale dopo 2 secondi.
            header("refresh:2;url=profilo.php");
        } else {
            // Password errata.
            echo 'Password e/o username errati! Stai per tornare alla pagina di login...';
            // Rimando alla pagina di login dopo 2 secondi.
            header("refresh:2;url=login.html");
        }
    } else {
        // Username errato.
        echo 'Password e/o username errati! Stai per tornare alla pagina di login...';
        // Rimando alla pagina di login dopo 2 secondi.
        header("refresh:2;url=login.html");
    }
    $stmt->close();
}
?>
