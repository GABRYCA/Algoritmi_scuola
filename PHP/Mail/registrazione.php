<?php
//Realizzare una serie di pagine che permettono la registrazione ad un sito.
//La prima pagina deve richiedere i dati anagrafici dell'utente (nome, cognome, data di
//nascita, indirizzo, città e mail).
//La seconda pagina (questa) deve memorizzare i dati anagrafici e salvandoli in un file; inviare una
//mail specificando una password temporanea di accesso ed uno username ed una validità di
//24 ore per la conferma.


//Dati anagrafici
$nome = $_POST['nome'];
$cognome = $_POST['cognome'];
$data = $_POST['data'];
$indirizzo = $_POST['indirizzo'];
$citta = $_POST['citta'];
$mail = $_POST['email'];

//Generazione username e password
$username = $nome . $cognome;
$password = rand(1000, 9999);

//Salvataggio dati in file
$fp = fopen("dati.txt", "a");
fwrite($fp, $nome . " " . $cognome . " " . $data . " " . $indirizzo . " " . $citta . " " . $mail . " " . $username . " " . $password . " " . date("d-m-Y") . " " . date("H:i:s") . " " . "0" . " " . "0" . "\n");
fclose($fp);

//Invio mail
$oggetto = "Registrazione";
$messaggio = "Gentile " . $nome . " " . $cognome . ",\n
Grazie per esserti registrato al nostro sito.\n
I tuoi dati sono:\n
Username: " . $username . "\n
Password: " . $password . "\n
La password è valida per 24 ore.\n
Cordiali saluti,\n
Il team di GCA";

// Setto gli header
$headers = "From: anonymousgca@anonymousgca.eu\r\n";
$headers .= "Reply-To: anonymousgca@anonymousgca.eu\r\n";
$headers .= "Return-Path: anonymousgca@anonymousgca.eu\r\n";
$headers .= "X-Mailer: PHP/" . phpversion();
// Content type
$headers .= "MIME-Version: 1.0\r\n";
$headers .= "Content-Type: text/plain; charset=ISO-8859-1\r\n";


// Invio la mail
if (mail($mail, $oggetto, $messaggio, $headers)) {
    echo "Mail inviata con successo a " . $mail;
} else {
    echo "Errore nell'invio della mail";
}