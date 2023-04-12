<?php
include "../../../private/connessione.php";
session_start();

if (!isset($_SESSION['loggedin'])) {
    // Messaggio d'errore.
    echo 'Non sei loggato! Devi loggarti per accedere a questa pagina!';
    // Redirect alla pagina di login dopo 2 secondi.
    header("refresh:2;url=login.html");
    exit;
}

// Connessione al database.
$con = connessione();

// Prendo dal POST l'id del messaggio da cancellare.
$id_messaggio = $_POST['id_messaggio'];

// Prendo l'ID dell'utente e verifico che sia un admin, se non lo è verifico se è il proprietario del messaggio.
$id_utente = $_SESSION['id'];
$stmt = $con->prepare("SELECT nome_ruolo FROM utente WHERE id_utente = ?");
$stmt->bind_param("i", $id_utente);
$stmt->execute();
$result = $stmt->get_result();
$row = $result->fetch_assoc();
$nome_ruolo = $row['nome_ruolo'];
$stmt->close();

$autorizzato = false;
if ($nome_ruolo = "admin"){
    $autorizzato = true;
}

if (!$autorizzato){
    // Verifico allora se l'utente è il proprietario del messaggio.
    $stmt = $con->prepare("SELECT utente FROM messaggio WHERE id_messaggio = ?");
    $stmt->bind_param("i", $id_messaggio);
    $stmt->execute();
    $result = $stmt->get_result();
    $row = $result->fetch_assoc();
    $id_utente_messaggio = $row['utente'];
    $stmt->close();

    if ($id_utente_messaggio == $id_utente){
        $autorizzato = true;
    }
}

if (!$autorizzato){
    // Messaggio d'errore.
    echo 'Non sei autorizzato a cancellare questo messaggio!';
    // Redirect alla pagina precedente dopo con $_SERVER['HTTP_REFERER']
    header("refresh:2;url=" . $_SERVER['HTTP_REFERER']);
    exit;
}

// Cancello il messaggio.
$stmt = $con->prepare("DELETE FROM messaggio WHERE id_messaggio = ?");
$stmt->bind_param("i", $id_messaggio);
$stmt->execute();
$stmt->close();

// Messaggio di successo.
echo 'Messaggio cancellato con successo!';
// Redirect alla pagina precedente dopo con $_SERVER['HTTP_REFERER']
header("refresh:2;url=" . $_SERVER['HTTP_REFERER']);
exit;
?>
<head>
    <?php
    include "common/dipendenze-head.php";
    ?>
    <title>Cancella messaggio</title>
</head>
<body class="font-monospace bg-dark text-center text-light mt-5">
<?php
include "common/dipendenze-body.php";
?>
</body>