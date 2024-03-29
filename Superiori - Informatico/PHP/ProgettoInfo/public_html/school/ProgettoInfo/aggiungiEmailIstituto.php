<?php
include "../../../private/connessione.php";
session_start();

// Controllo se l'utente è loggato.
if (!isset($_SESSION['loggedin'])) {
    header('Location: login.html');
    exit;
}

// Controllo se emailIstituto è settata.
if (!isset($_POST['emailIstituto'])) {
    // Manca qualcosa, errore.
    exit('empty');
}

// Controllo se emailIstituto è vuota.
if (empty($_POST['emailIstituto'])) {
    // Manca qualcosa, errore.
    exit('empty');
}

// Valido emailIstituto.
if (!filter_var($_POST['emailIstituto'], FILTER_VALIDATE_EMAIL)) {
    // Email istituto non valida.
    exit('invalid');
}

$conn = connessione();
// Prendo l'id dalla sessione.
$id = $_SESSION['id'];

// Controllo se l'email istituto è già presente nel database e activation_code_istituto = "activated".
if ($stmt = $conn->prepare('SELECT id_utente FROM utente WHERE email_istituto = ? AND activation_code_istituto = ?')) {
    $attivato = "activated";
    $stmt->bind_param('ss', $_POST['emailIstituto'], $attivato);
    $stmt->execute();
    $stmt->store_result();
    if ($stmt->num_rows > 0) {
        // Email istituto già presente nel database.
        exit('exists');
    }
    $stmt->close();
}

// Controllo se l'email istituto esiste nella table luogo dominio_email_istituto, prendendo solamente la parte dopo la @.
$dominio_email_istituto = explode('@', $_POST['emailIstituto']);
if ($stmt = $conn->prepare('SELECT id_luogo FROM luogo WHERE dominio_email_istituto = ?')) {
    $stmt->bind_param('s', $dominio_email_istituto[1]);
    $stmt->execute();
    $stmt->store_result();
    if ($stmt->num_rows == 0) {
        // Email istituto non valida.
        exit('invalid');
    }
    $stmt->close();
}

// Se non presente, invio una email di conferma e imposto activation_code_istituto all'utente con id = $id.
$activation_code_istituto = uniqid();
if ($stmt = $conn->prepare('UPDATE utente SET activation_code_istituto = ?, email_istituto = ? WHERE id_utente = ?')) {
    $stmt->bind_param('ssi', $activation_code_istituto, $_POST['emailIstituto'], $id);
    $stmt->execute();
    $stmt->close();
}

// Invio email di conferma.
$to = $_POST['emailIstituto'];
$from = 'noreply@anonymousgca.eu';
$subject = 'Conferma email istituto';
$message = 'Clicca sul link per confermare la tua email istituto: https://www.anonymousgca.eu/school/ProgettoInfo/confirmEmailIstituto.php?activation_code_istituto=' . $activation_code_istituto;
$headers = 'From: ' . $from . "\r\n" . 'Reply-To: ' . $from . "\r\n" . 'X-Mailer: PHP/' . phpversion() . "\r\n" . 'MIME-Version: 1.0' . "\r\n" . 'Content-Type: text/html; charset=UTF-8' . "\r\n";
if (!mail($to, $subject, $message, $headers)) {
    // Errore.
    exit('error');
}

// Redirect alla pagina di profilo dopo 2 secondi.
header('Refresh: 2; URL=profilo.php');
exit('success');
?>
<head>
    <?php
    include "common/dipendenze-head.php";
    ?>
    <title>Aggiungi Email Istituto</title>
</head>
<body class="font-monospace bg-dark text-center text-light mt-5">
<?php
include "common/dipendenze-body.php";
?>
</body>
