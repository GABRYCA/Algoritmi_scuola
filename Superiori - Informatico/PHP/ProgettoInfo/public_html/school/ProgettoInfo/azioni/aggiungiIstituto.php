<?php
include "../../../../private/connessione.php";
session_start();

if (!isset($_SESSION['loggedin'])) {
    // Messaggio d'errore.
    echo 'Non sei loggato! Devi loggarti per accedere a questa pagina!';
    // Redirect alla pagina di login dopo 2 secondi.
    header("refresh:0;url=../login.html");
    exit;
}

$conn = connessione();

// Prendo dati dal form nome, città, dominio email (opzionale), link sito ufficiale opzionale, tipo_luogo
$nome = $_POST['nome'];
$citta = $_POST['citta'];
$tipoLuogo = $_POST['tipo_luogo'];
$dominioEmail = $_POST['dominio_email_istituto'] ?? NULL;
$linkSitoUfficiale = $_POST['link_sito_ufficiale'] ?? NULL;

// Controllo se l'istituto esiste già, usando gli statements
$stmt = $conn->prepare("SELECT * FROM luogo WHERE nome = ? AND città = ?");
$stmt->bind_param("ss", $nome, $citta);
$stmt->execute();
$result = $stmt->get_result();
if ($result->num_rows > 0) {
    echo "<script>alert('Errore: l\'istituto è già presente nel database.');</script>";
    header("refresh:0;url=../amministratoreIstituti.php");
    exit;
}

if ($dominioEmail != NULL) {

    // Controllo se il dominio email è già presente, usando gli statements
    $stmt = $conn->prepare("SELECT * FROM luogo WHERE dominio_email_istituto = ?");
    $stmt->bind_param("s", $dominioEmail);
    $stmt->execute();
    $result = $stmt->get_result();
    if ($result->num_rows > 0) {
        echo "<script>alert('Errore: il dominio email è già presente nel database.');</script>";
        header("refresh:0;url=../amministratoreIstituti.php");
        exit;
    }
}

// Aggiungo l'istituto, usando gli statements
$stmt = $conn->prepare("INSERT INTO luogo (nome, città, dominio_email_istituto, sito_ufficiale, tipo_luogo) VALUES (?, ?, ?, ?, ?)");
$stmt->bind_param("sssss", $nome, $citta, $dominioEmail, $linkSitoUfficiale, $tipoLuogo);
$stmt->execute();
$stmt->close();

// Comunico all'utente che l'istituto è stato aggiunto
echo "<script>alert('Istituto aggiunto con successo!');</script>";
// Rimando alla pagina precedente dopo 2 secondi.
header("refresh:0;url=../amministratoreIstituti.php");
exit;
?>