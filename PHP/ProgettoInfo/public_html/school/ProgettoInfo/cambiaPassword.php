<?php
include "../../../private/connessione.php";
session_start();

// Controllo che sia loggato.
if (!isset($_SESSION['loggedin'])) {
    header('Location: login.html');
    session_abort();
    exit;
}

// Verifico che i dati siano settati.
if (isset($_POST['newPassword']) && isset($_POST['newPasswordConfirm']) && isset($_POST['oldPassword'])) {
    // Controllo che non ci siano campi vuoti.
    if (empty($_POST['newPassword']) || empty($_POST['newPasswordConfirm']) || empty($_POST['oldPassword'])) {
        // Errore
        echo 'empty';
        exit;
    }

    // Controllo che la password non sia troppo corta.
    if (strlen($_POST['newPassword']) < 6) {
        // Errore.
        echo 'short';
        exit;
    }

    // Controllo che la password non sia troppo lunga.
    if (strlen($_POST['newPassword']) > 20) {
        // Errore.
        echo 'long';
        exit;
    }

    // Verifico che newPassword e newPasswordConfirm coincidano.
    if ($_POST['newPassword'] !== $_POST['newPasswordConfirm']) {
        // Errore.
        echo 'notMatch';
        exit;
    }

    $con = connessione();

    // Hash password.
    //$password = password_hash($_POST['newPassword'], PASSWORD_DEFAULT);

    // Verifico che la vecchia password (già in hash nel database) sia corretta.
    if ($stmt = $con->prepare('SELECT password FROM utente WHERE id_utente = ?')) {
        $stmt->bind_param('i', $_SESSION['id']);
        $stmt->execute();
        $stmt->store_result();
        if ($stmt->num_rows > 0) {
            $stmt->bind_result($password);
            $stmt->fetch();
            if (!password_verify($_POST['oldPassword'], $password)) {
                // Password errata.
                echo 'wrongPassword';
                exit;
            }
        } else {
            // Errore.
            echo 'error';
            exit;
        }
    } else {
        // Errore.
        echo 'error';
        exit;
    }

    // Aggiorno la password.
    if ($stmt = $con->prepare('UPDATE utente SET password = ? WHERE id_utente = ?')) {
        // Creo hash password in input newPassword e aggiorno il database.
        $password = password_hash($_POST['newPassword'], PASSWORD_DEFAULT);
        $stmt->bind_param('si', $password, $_SESSION['id']);
        $stmt->execute();
        // Successo.
        echo 'success';
    } else {
        // Errore.
        echo 'error';
        exit;
    }


    // Verifico che la vecchia password sia corretta.
    /*if ($stmt = $con->prepare('SELECT password FROM utente WHERE id_utente = ?')) {
        $stmt->bind_param('i', $_SESSION['id']);
        $stmt->execute();
        $stmt->store_result();
        if ($stmt->num_rows > 0) {
            $stmt->bind_result($password);
            $stmt->fetch();
            if (!password_verify($_POST['oldPassword'], $password)) {
                // Password errata.
                echo 'wrongPassword';
                exit;
            }
        } else {
            // Errore.
            echo 'error';
            exit;
        }
    } else {
        // Errore.
        echo 'error';
        exit;
    }

    // Aggiorna password
    if ($stmt = $con->prepare('UPDATE utente SET password = ? WHERE id_utente = ?')) {
        $stmt->bind_param('si', $password, $_SESSION['id']);
        $stmt->execute();

        // Successo
        echo 'success';
    } else {
        // Errore
        echo 'error';
        exit;
    }*/

} else {
    // Vuoto
    echo 'empty';
    exit;
}
?>