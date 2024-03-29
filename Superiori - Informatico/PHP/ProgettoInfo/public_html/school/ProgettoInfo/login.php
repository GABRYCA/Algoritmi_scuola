<?php
include "../../../private/connessione.php";
session_start();

// Check if user is already logged in, if yes then redirect him to profile page.
if (isset($_SESSION['loggedin'])) {
    header('Location: profilo.php');
    return;
}

$con = connessione();

// Verifico se i dati sono stati inseriti.
if (!isset($_POST['username'], $_POST['password'])) {
    // Errore, non tutti i campi sono stati compilati.
    echo('Devi compilare tutti i campi necessari!');
    header("refresh:2;url=login.html");
    return;
}

// Controllo se username e password sono vuoti.
if (empty($_POST['username']) || empty($_POST['password'])) {
    // Errore, non tutti i campi sono stati compilati.
    echo('Devi compilare tutti i campi necessari!');
    header("refresh:2;url=login.html");
    return;
}

// Ottengo dati account con username specificato.
if ($stmt = $con->execute_query("SELECT id_utente, password, activation_code, email_personale FROM utente WHERE username = ?", [$_POST['username']])) {


    if ($stmt->num_rows > 0) {

        $dati = $stmt->fetch_row();
        $id = $dati[0];
        $password = $dati[1];
        $activation_code = $dati[2];
        $email_personale = $dati[3];

        // Account trovato, controllo password.
        // Uso l'hash della password inserita e la confronto con quella nel database.
        if (password_verify($_POST['password'], $password)) {

            // Successo, controllo se l'account è attivato.
            if (!$activation_code == 'activated') {
                // Account non attivato.
                echo('Il tuo account non è stato attivato, per favore controlla le tue email (e anche lo spam)!');
                header("refresh:2;url=login.html");
                return;
            }

            // Creo una nuova sessione.
            session_regenerate_id();
            $_SESSION['loggedin'] = TRUE; // Variabile per riconoscere se l'utente è loggato.
            $_SESSION['name'] = $_POST['username']; // Variabile per riconoscere il nome dell'utente.
            $_SESSION['id'] = $id; // Variabile per riconoscere l'id dell'utente nel database (utente.id_utente).

            // Loggo l'ip dell'utente se non è già presente in ip_utente.
            $ip = $_SERVER['REMOTE_ADDR'];
            if (!filter_var($ip, FILTER_VALIDATE_IP)) exit("L'ip non è valido (Sei in IPv6?, wow)!");

            $stmt = $con->execute_query("SELECT * FROM ip_utente WHERE ip = ? AND id_utente = ?", [$ip, $id]);
            if ($stmt->num_rows == 0) {
                // Aggiunge all'utente con id $id l'ip $ip.
                $stmt = $con->execute_query("INSERT INTO ip_utente (id_utente, ip) VALUES (?, ?)", [$id, $ip]);

                // Invia email comunicando che è stato eseguito l'accesso con un nuovo ip, nel caso in cui fallisca l'invio dell'email, non si blocca l'accesso e non mostra l'errore.
                $to = $email_personale;
                $subject = "Nuovo accesso";
                // Comunico nuovo accesso e avviso di cambiare la password se non era lui.
                $message = "Ciao " . $_SESSION['name'] . ",\r \r e' stato eseguito un nuovo accesso con il tuo account da un nuovo ip: " . $ip . "\r \r Se non sei stato tu, ti consigliamo di cambiare IMMEDIATAMENTE la password accedendo al tuo profilo e utilizzare 'Modifica Password' nella danger zone rossa.";
                // Da noreply@anonymousgca.eu
                $headers = "From: noreply@anonymousgca.eu";
                // Suppress warning
                @mail($to, $subject, $message, $headers);
            }

            echo 'Ciao ' . $_SESSION['name'] . ', ti sei loggato con successo! Per favore attendi un paio di secondi...';
            // Rimando alla pagina principale dopo 2 secondi.
            header("refresh:2;url=profilo.php");
        } else {
            // Password errata.
            echo 'Password e/o username errati! Stai per tornare alla pagina di login...';
            // Rimando alla pagina di login dopo 2 secondi.
            header("refresh:2;url=login.html");
        }
    } else {
        // Username errato.
        echo 'Password e/o username errati! Stai per tornare alla pagina di login...';
        // Rimando alla pagina di login dopo 2 secondi.
        header("refresh:2;url=login.html");
    }
    $stmt->close();
}
?>
<head>
    <?php
    include "common/dipendenze-head.php";
    ?>
    <title>Accesso</title>
</head>
<body class="font-monospace bg-dark text-center text-light mt-5">
<div class="row justify-content-center text-center">
    <div class="col">
        <div class="lds-ellipsis"><div></div><div></div><div></div><div></div></div>
    </div>
</div>
<?php
include "common/dipendenze-body.php";
?>
</body>