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
    $activation_code_istituto = $_GET['activation_code_istituto'];

    // Controllo se activation_code_istituto è presente nel database, se lo è, prendo l'id dell'utente.
    if ($stmt = $conn->prepare('SELECT id_utente FROM utente WHERE activation_code_istituto = ?')) {
        $stmt->bind_param('s', $activation_code_istituto);
        $stmt->execute();
        $stmt->store_result();
        if ($stmt->num_rows > 0) {
            $stmt->bind_result($id);
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

    // Rimando alla pagina di login dopo 2 secondi.
    header("refresh:2;url=login.html");

    exit("Email istituto confermata con successo!");
} else {
    // Errore.
    exit("Codice di verifica non valido!");
}