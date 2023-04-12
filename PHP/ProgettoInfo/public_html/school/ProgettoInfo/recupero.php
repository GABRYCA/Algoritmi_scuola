<?php
include "../../../private/connessione.php";
session_start();

// Se già loggato, reindirizzo alla home.
if (isset($_SESSION['loggedin'])) {
    header('Location: profilo.php');
    exit;
}

// Controllo che i dati siano settati.
if (!isset($_POST['email'])){
    // Errore.
    // Redirect alla pagina di recupero password.
    header('Location: recupero.html');
    exit('Inserire l\'email.');
}

if (empty($_POST['email'])){
    // Errore.
    exit('Inserire l\'email.');
}

// Controllo che l'email sia valida.
if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
    // Errore.
    exit('Email non valida.');
}

$con = connessione();

// Verifico che l'email_personale sia presente nel database.
if ($stmt = $con->prepare('SELECT id_utente, email_personale FROM utente WHERE email_personale = ?')) {
    $stmt->bind_param('s', $_POST['email']);
    $stmt->execute();
    $stmt->store_result();
    if ($stmt->num_rows > 0) {
        $stmt->bind_result($id_utente, $email_personale);
        $stmt->fetch();
        // Genero una password casuale.
        $password = bin2hex(random_bytes(8));
        // Hash password.
        $passwordHash = password_hash($password, PASSWORD_DEFAULT);
        // Aggiorno la password nel database.
        if ($stmt = $con->prepare('UPDATE utente SET password = ? WHERE id_utente = ?')) {
            $stmt->bind_param('si', $passwordHash, $id_utente);
            $stmt->execute();
            // Invio la nuova password all'utente.
            $to = $email_personale;
            $subject = 'Recupero password';
            $from = 'noreply@anonymousgca.eu';
            $message = 'La tua nuova password è: ' . $password . ' .<br>Per favore, cambia la password appena possibile dal tuo <a href="https://anonymousgca.eu/school/ProgettoInfo/profilo.php">profilo</a>';
            $headers = 'From: ' . $from . "\r\n" . 'Reply-To: ' . $from . "\r\n" . 'X-Mailer: PHP/' . phpversion() . "\r\n" . 'MIME-Version: 1.0' . "\r\n" . 'Content-Type: text/html; charset=UTF-8' . "\r\n";
            if (!mail($to, $subject, $message, $headers)){
                // Errore.
                exit('Errore durante l\'invio dell\'email.');
            }
            // Redirect alla pagina di login dopo 2 secondi.
            header('Refresh: 2; URL=login.html');
            exit('La istruzione sono state inviate all\'indirizzo email.');
        } else {
            // Errore.
            exit('Errore durante il recupero della password.');
        }
    } else {
        // Errore.
        exit('Email non presente nel database.');
    }
} else {
    // Errore.
    exit('Errore durante il recupero della password.');
}
?>
<head>
    <?php
    include "common/dipendenze-head.php";
    ?>
    <title>Recupero Password</title>
</head>
<body class="font-monospace bg-dark text-center text-light mt-5">
<?php
include "common/dipendenze-body.php";
?>
</body>
