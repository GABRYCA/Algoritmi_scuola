<?php
include "connessione.php";

if (isset($_GET['activation_code_istituto'])) {

    $conn = connessione();

    // Controllo se activation_code_istituto è settato.
    if (!isset($_GET['activation_code_istituto'])) {
        // Manca qualcosa, errore.
        exit('Codice di verifica mancante!');
    }

    // Controllo se activation_code_istituto è vuoto.
    if (empty($_GET['activation_code_istituto'])) {
        // Manca qualcosa, errore.
        exit('Codice di verifica mancante!');
    }

    $id = null;
    $email_istituto = null;
    $activation_code_istituto = $_GET['activation_code_istituto'];

    // Controllo se activation_code_istituto è presente nel database, se lo è, prendo l'id dell'utente.
    if ($stmt = $conn->prepare('SELECT id_utente, email_istituto FROM utente WHERE activation_code_istituto = ?')) {
        $stmt->bind_param('s', $activation_code_istituto);
        $stmt->execute();
        $stmt->store_result();
        if ($stmt->num_rows > 0) {
            $stmt->bind_result($id, $email_istituto);
            $stmt->fetch();
        } else {
            // Errore.
            exit("Codice di verifica non valido (non trovato)!");
        }
        $stmt->close();
    }

    // Se presente, imposto activation_code_istituto = "activated" all'utente corrispondente.
    if ($stmt = $conn->prepare('UPDATE utente SET activation_code_istituto = ? WHERE id_utente = ?')) {
        $attivato = "activated";
        $stmt->bind_param('ss', $attivato, $id);
        $stmt->execute();
        $stmt->close();
    }

    // Ottengo dai luoghi l'id del luogo corrispondente all'email istituto.
    $id_luogo = null;
    $dominio_email_istituto = explode('@', $email_istituto);
    if ($stmt = $conn->prepare('SELECT id_luogo FROM luogo WHERE dominio_email_istituto = ?')) {
        $stmt->bind_param('s', $dominio_email_istituto[1]);
        $stmt->execute();
        $stmt->store_result();
        if ($stmt->num_rows > 0) {
            $stmt->bind_result($id_luogo);
            $stmt->fetch();
        } else {
            // Errore.
            exit("Qualcosa è andato storto durante l'associazione al luogo!");
        }
        $stmt->close();
    }

    // Aggiungo ad appartenenza l'id dell'utente e dell'istituto se presenti.
    if ($stmt = $conn->prepare('INSERT INTO appartenenza (id_utente, id_luogo) VALUES (?, ?)')) {
        $stmt->bind_param('ii', $id, $id_luogo);
        $stmt->execute();
        $stmt->close();
    }

    // Rimando alla pagina del profilo dopo 2 secondi.
    header("refresh:2;url=profilo.php");
    exit("Email istituto confermata con successo!");
} else {
    // Errore.
    exit("Codice di verifica non valido!");
}