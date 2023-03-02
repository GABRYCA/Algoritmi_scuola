<?php
include "connessione.php";
session_start();

// Controllo se l'utente è già loggato.
if (isset($_SESSION['loggedin'])) {
    header('Location: profilo.php');
    exit;
}

// Controllo se username, nome, cognome, nascita, email_personale, email_istituto, password, confirm_password sono settati.
if (!isset($_POST['username'], $_POST['nome'], $_POST['cognome'], $_POST['nascita'], $_POST['email_personale'], $_POST['password'], $_POST['confirm_password'])) {
    // Manca qualcosa, errore.
    header("refresh:2;url=registrazione.html");
    exit('Inserire tutti i dati!');
}

// Controllo se username, nome, cognome, nascita, email_personale, email_istituto, password, confirm_password sono vuoti.
if (empty($_POST['username']) || empty($_POST['nome']) || empty($_POST['cognome']) || empty($_POST['nascita']) || empty($_POST['email_personale']) || empty($_POST['password']) || empty($_POST['confirm_password'])) {
    // Manca qualcosa, errore.
    header("refresh:2;url=registrazione.html");
    exit('Inserire tutti i dati!');
}

// Valido username, nome e cognome.
if (!preg_match('/^[a-zA-Z0-9]+$/', $_POST['username']) || !preg_match('/^[a-zA-Z]+$/', $_POST['nome']) || !preg_match('/^[a-zA-Z]+$/', $_POST['cognome'])) {
    // Username, nome o cognome non validi.
    header("refresh:2;url=registrazione.html");
    exit('Username, nome o cognome non validi!');
}

// Valido le email.
if (!filter_var($_POST['email_personale'], FILTER_VALIDATE_EMAIL)) {
    // Email personale non valida.
    header("refresh:2;url=registrazione.html");
    exit('Email personale non valida!');
}

$settato_email_istituto = false;

// Verifico se è stato settato email_istituto e se non è vuoto, nel caso ci sia la valido.
if (isset($_POST['email_istituto']) && !empty($_POST['email_istituto'])) {
    if (!filter_var($_POST['email_istituto'], FILTER_VALIDATE_EMAIL)) {
        // Email istituto non valida.
        header("refresh:2;url=registrazione.html");
        exit('Email istituto non valida!');
    }
    $settato_email_istituto = true;
}

// Valido la password.
if (strlen($_POST['password']) > 20 || strlen($_POST['password']) < 6) {
    // Password non valida.
    header("refresh:2;url=registrazione.html");
    exit('Password non valida!');
}

// Controllo se le password coincidono.
if ($_POST['password'] !== $_POST['confirm_password']) {
    // Le password non coincidono.
    header("refresh:2;url=registrazione.html");
    exit('Le password non coincidono!');
}

$con = connessione();

// Controllo se esiste l'account dall'username o email.
if ($stmt = $con->prepare('SELECT id_utente FROM utente WHERE username = ? OR email_personale = ?')) {
    $stmt->bind_param('ss', $_POST['username'], $_POST['email_personale']);
    $stmt->execute();
    $stmt->store_result();
    if ($stmt->num_rows > 0){
        // L'utente esiste, errore.
        echo 'Username o email già esistenti! Stai per essere reindirizzato alla pagina di registrazione.';
        // Rimando alla pagina di registrazione.
        header("refresh:2;url=registrazione.html");
    } else {
        // Aggiungi nuovo utente.
        if ($stmt = $con->prepare('INSERT INTO utente (username, nome, cognome, data_nascita, email_personale, email_istituto, password, activation_code, activation_code_istituto) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)')) {
            // Hash password.
            $password = password_hash($_POST['password'], PASSWORD_DEFAULT);
            $email_istituto = $settato_email_istituto ? $_POST['email_istituto'] : null;

            // ID Di verifica temporanei unici.
            $uniqid = uniqid();
            $uniqidIstituto = null;
            if ($email_istituto != null){
                $uniqidIstituto = uniqid();
            }

            // Invio al database del comando con i dati specificati.
            $stmt->bind_param('sssssssss', $_POST['username'], $_POST['nome'], $_POST['cognome'], $_POST['nascita'], $_POST['email_personale'], $email_istituto, $password, $uniqid, $uniqidIstituto);
            $stmt->execute();

            // Invio email di verifica.
            $from = 'noreply@anonymousgca.eu';
            $subject = 'Attivazione dell\'account di ' . $_POST['username'] . '.';
            $headers = 'From: ' . $from . "\r\n" . 'Reply-To: ' . $from . "\r\n" . 'X-Mailer: PHP/' . phpversion() . "\r\n" . 'MIME-Version: 1.0' . "\r\n" . 'Content-Type: text/html; charset=UTF-8' . "\r\n";
            $activate_link = 'https://anonymousgca.eu/school/ProgettoInfo/activate.php?email=' . $_POST['email_personale'] . '&code=' . $uniqid;
            $message = '<p>Per favore usa il seguente link per attivare il tuo account e verificare l\'email: <a href="' . $activate_link . '">' . $activate_link . '</a></p>';
            if(!mail($_POST['email_personale'], $subject, $message, $headers)){
                echo 'Errore nell\'invio della mail di verifica! Per favore contattare l\'amministratore!';
            }

            // Invio email di verifica alla mail dell'istituto se specificato.
            if ($email_istituto != null){
                $subject = 'Verifica email dell\'istituto dell\'account di ' . $_POST['username'] . '.';
                $activate_link = 'https://anonymousgca.eu/school/ProgettoInfo/activate.php?emailIstituto=' . $email_istituto . '&code=' . $uniqidIstituto;
                $message = '<p>Per favore usa il seguente link per verificare la tua email dell\'istituto: <a href="' . $activate_link . '">' . $activate_link . '</a></p>';
                if (!mail($email_istituto, $subject, $message, $headers)){
                    echo 'Errore nell\'invio della mail di verifica all\'email dell\'istituto! Per favore contattare l\'amministratore!';
                }
            }

            // Fine, messaggio di successo.
            echo 'Per favore controlla le tue email per attivare il tuo account (controlla anche lo spam)!';
            // Mando alla pagina di login.
            header("refresh:2;url=login.html");
        } else {
            // Errore di query.
            echo 'Errore interno!';
            // Mando alla pagina di registrazione.
            header("refresh:2;url=registrazione.html");
        }
    }
    $stmt->close();
} else {
    // Errore di query.
    echo 'Errore interno!';
    header("refresh:2;url=registrazione.html");
}

$con->close();
?>