<?php
include 'connessione.php';
session_start();

if (!isset($_SESSION['loggedin'])) {
    header('Location: login.html');
    exit;
}

// Ottengo le appartenenze dell'utente per i luoghi.
$id_utente = $_SESSION['id'];
$luoghi = array();
$con = connessione();
$stmt = $con->prepare("SELECT a.id_luogo,l.nome FROM appartenenza AS a JOIN luogo l on a.id_luogo = l.id_luogo WHERE id_utente = ?");
$stmt->bind_param("i", $id_utente);
$stmt->execute();
$result = $stmt->get_result();
// Creo array associativo id_luogo => nome.
while ($row = $result->fetch_assoc()) {
    $luoghi[$row['id_luogo']] = $row['nome'];
}
$stmt->close();

// Se non c'è almeno un luogo nel vettore luoghi, lo comunico all'utente.
if (count($luoghi) == 0) {
    echo "<script>alert('Non sei abilitato a inviare messaggi in nessun luogo. Aggiungi la tua email d\'istituto nel profilo.');</script>";
    echo "<script>window.location.href = 'profilo.php';</script>";
    exit;
}

if (!isset($_POST['luogo']) || !isset($_POST['messaggio']) || !isset($_POST['colore'])) {
    echo "<script>alert('Errore: non hai compilato tutti i campi.');</script>";
    echo "<script>window.location.href = 'inviaMessaggio.php';</script>";
    exit;
}

// Controllo non siano empty.
if (empty($_POST['luogo']) || empty($_POST['messaggio']) || empty($_POST['colore'])) {
    echo "<script>alert('Errore: non hai compilato tutti i campi.');</script>";
    echo "<script>window.location.href = 'inviaMessaggio.php';</script>";
    exit;
}

// Converto in variabile sicura (da unsafe POST).
$luogo = $con->real_escape_string($_POST['luogo']);
$messaggio = $con->real_escape_string($_POST['messaggio']);
$colore = $con->real_escape_string($_POST['colore']);

// Verifico che il colore sia con un formato valido #RRGGBB.
if (!preg_match("/^#[a-f0-9]{6}$/i", $colore)) {
    echo "<script>alert('Errore: il colore non è valido.');</script>";
    echo "<script>window.location.href = 'inviaMessaggio.php';</script>";
    exit;
}

// Controllo che il luogo sia tra quelli dell'utente.
if (!array_key_exists($luogo, $luoghi)) {
    echo "<script>alert('Errore: non sei abilitato a inviare messaggi in questo luogo.');</script>";
    echo "<script>window.location.href = 'inviaMessaggio.php';</script>";
    exit;
}

// Valido il messaggio.
if (strlen($messaggio) > 1000) {
    echo "<script>alert('Errore: il messaggio è troppo lungo (1000 caratteri).');</script>";
    echo "<script>window.location.href = 'inviaMessaggio.php';</script>";
    exit;
}

// Inserisco il messaggio nel database.
$stmt = $con->prepare("INSERT INTO messaggio (testo, colore_bordo, luogo, utente) VALUES (?, ?, ?, ?)");
// Rimuovo dal colore il primo carattere #.
$colore = substr($colore, 1);
$stmt->bind_param("ssii", $messaggio, $colore, $luogo, $id_utente);

if ($stmt->execute()) {
    echo "<script>alert('Messaggio inviato correttamente.');</script>";
    echo "<script>window.location.href = 'inviaMessaggio.php';</script>";
    exit;
} else {
    echo "<script>alert('Errore: non è stato possibile inviare il messaggio.');</script>";
    echo "<script>window.location.href = 'inviaMessaggio.php';</script>";
    exit;
}

?>