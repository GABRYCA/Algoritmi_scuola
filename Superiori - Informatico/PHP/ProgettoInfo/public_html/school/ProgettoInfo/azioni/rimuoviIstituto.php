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

// Prendo dal get l'id dell'istituto da rimuovere
$id = $_GET['id'];

// Controllo se l'istituto esiste già, usando gli statements
$stmt = $conn->prepare("SELECT * FROM luogo WHERE id_luogo = ?");
$stmt->bind_param("i", $id);
$stmt->execute();
$result = $stmt->get_result();
if ($result->num_rows == 0) {
    echo "<script>alert('Errore: luogo/Istituto non è presente nel database.');</script>";
    header("refresh:0;url=../amministratoreIstituti.php");
    exit;
}

// Rimuovo l'istituto, usando gli statements
$stmt = $conn->prepare("DELETE FROM luogo WHERE id_luogo = ?");
$stmt->bind_param("i", $id);
$stmt->execute();
$stmt->close();

// Comunico all'utente che il luogo è stato rimosso
echo "<script>alert('Luogo/Istituto rimosso con successo!');</script>";
// Rimando alla pagina precedente dopo 2 secondi.
header("refresh:0;url=../amministratoreIstituti.php");
?>