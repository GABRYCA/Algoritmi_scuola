<?php
include "../../../private/connessione.php";
session_start();

// Check if user is already logged in, if yes then redirect him to profile page.
if (isset($_SESSION['loggedin'])) {
    header('Location: profilo.php');
    exit;
}

$con = connessione();

// Verifico se i dati sono stati inseriti.
if (!isset($_POST['username'], $_POST['password'])) {
    // Errore, non tutti i campi sono stati compilati.
    exit('Devi compilare tutti i campi necessari!');
}

// Controllo se username e password sono vuoti.
if (empty($_POST['username']) || empty($_POST['password'])) {
    // Errore, non tutti i campi sono stati compilati.
    exit('Devi compilare tutti i campi necessari!');
}

// Ottengo dati account con username specificato.
if ($stmt = $con->prepare('SELECT id_utente, password, activation_code FROM utente WHERE username = ?')) {
    // Parametri.
    $stmt->bind_param('s', $_POST['username']);
    $stmt->execute();
    // Salvo risultato.
    $stmt->store_result();

    if ($stmt->num_rows > 0) {
        $stmt->bind_result($id, $password, $activation_code);
        $stmt->fetch();

        // Account trovato, controllo password.
        // Uso l'hash della password inserita e la confronto con quella nel database.
        if (password_verify($_POST['password'], $password)) {

            // Successo, controllo se l'account è attivato.
            if (!$activation_code == 'activated') {
                // Account non attivato.
                exit('Il tuo account non è stato attivato, per favore controlla le tue email (e anche lo spam)!');
            }

            // Creo una nuova sessione.
            session_regenerate_id();
            $_SESSION['loggedin'] = TRUE; // Variabile per riconoscere se l'utente è loggato.
            $_SESSION['name'] = $_POST['username']; // Variabile per riconoscere il nome dell'utente.
            $_SESSION['id'] = $id; // Variabile per riconoscere l'id dell'utente nel database (utente.id_utente).

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
    <style>
        .lds-ellipsis {
            display: inline-block;
            position: relative;
            width: 80px;
            height: 80px;
        }
        .lds-ellipsis div {
            position: absolute;
            top: 33px;
            width: 13px;
            height: 13px;
            border-radius: 50%;
            background: #fff;
            animation-timing-function: cubic-bezier(0, 1, 1, 0);
        }
        .lds-ellipsis div:nth-child(1) {
            left: 8px;
            animation: lds-ellipsis1 0.6s infinite;
        }
        .lds-ellipsis div:nth-child(2) {
            left: 8px;
            animation: lds-ellipsis2 0.6s infinite;
        }
        .lds-ellipsis div:nth-child(3) {
            left: 32px;
            animation: lds-ellipsis2 0.6s infinite;
        }
        .lds-ellipsis div:nth-child(4) {
            left: 56px;
            animation: lds-ellipsis3 0.6s infinite;
        }
        @keyframes lds-ellipsis1 {
            0% {
                transform: scale(0);
            }
            100% {
                transform: scale(1);
            }
        }
        @keyframes lds-ellipsis3 {
            0% {
                transform: scale(1);
            }
            100% {
                transform: scale(0);
            }
        }
        @keyframes lds-ellipsis2 {
            0% {
                transform: translate(0, 0);
            }
            100% {
                transform: translate(24px, 0);
            }
        }
    </style>
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