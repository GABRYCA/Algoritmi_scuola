<?php
include "../../../private/connessione.php";
session_start();

// Controllo se l'utente è loggato.
if (!isset($_SESSION['loggedin'])) {
    header('Location: login.html');
    exit;
}

// Controllo se password è settata.
if (!isset($_POST['password'])) {
    // Manca qualcosa, errore.
    exit('empty');
}

// Controllo se password è vuota.
if (empty($_POST['password'])) {
    // Manca qualcosa, errore.
    exit('empty');
}

$con = connessione();

// Verifico che la password sia corretta.
if ($stmt = $con->prepare('SELECT password FROM utente WHERE id_utente = ?')) {
    $stmt->bind_param('i', $_SESSION['id']);
    $stmt->execute();
    $stmt->store_result();
    if ($stmt->num_rows > 0) {
        $stmt->bind_result($password);
        $stmt->fetch();
        if (password_verify($_POST['password'], $password)) {
            // Password corretta, procedo.
            if ($stmt = $con->prepare('DELETE FROM utente WHERE id_utente = ?')) {
                $stmt->bind_param('i', $_SESSION['id']);
                $stmt->execute();
                // Eliminazione avvenuta con successo.
                exit('success');
            } else {
                // Errore.
                exit('error');
            }
        } else {
            // Password errata, errore.
            exit('wrongPassword');
        }
    } else {
        // Errore.
        exit('error');
    }
    $stmt->close();
} else {
    // Errore.
    exit('error');
}
?>
<head>
    <?php
    include "common/dipendenze-head.php";
    ?>
    <title>Cancella Account</title>
</head>
<body class="font-monospace bg-dark text-center text-light mt-5">
<?php
include "common/dipendenze-body.php";
?>
</body>
