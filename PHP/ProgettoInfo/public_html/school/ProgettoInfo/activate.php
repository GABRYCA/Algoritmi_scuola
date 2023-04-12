<?php
include "../../../private/connessione.php";

$con = connessione();

// Check if email and code are set and then exists in the database.
if (isset($_GET['email'], $_GET['code'])) {
    if ($stmt = $con->prepare('SELECT * FROM utente WHERE email_personale = ? AND activation_code = ?')) {
        $stmt->bind_param('ss', $_GET['email'], $_GET['code']);
        $stmt->execute();

        // Save result.
        $stmt->store_result();
        if ($stmt->num_rows > 0) {

            // Account exists, activate it.
            if ($stmt = $con->prepare('UPDATE utente SET activation_code = ? WHERE email_personale = ? AND activation_code = ?')) {
                // Set activation code to 'activated'.
                $newcode = 'activated';
                $stmt->bind_param('sss', $newcode, $_GET['email'], $_GET['code']);
                $stmt->execute();
                echo 'Account attivato con successo, ora puoi <a href="login.html">loggarti</a>!';
            }
        } else {
            echo 'Attivazione già avvenuta oppure email non trovata! Stai per essere reindirizzato alla pagina di login...';
            // Rimando alla pagina di login dopo 2 secondi.
            header("refresh:2;url=login.html");
        }
    }
} else if (isset($_GET['emailIstituto'], $_GET['code'])){
    if ($stmt = $con->prepare('SELECT * FROM utente WHERE email_istituto = ? AND activation_code_istituto = ?')) {
        $stmt->bind_param('ss', $_GET['emailIstituto'], $_GET['code']);
        $stmt->execute();

        // Save result.
        $stmt->store_result();
        if ($stmt->num_rows > 0) {

            // Account exists, activate it.
            if ($stmt = $con->prepare('UPDATE utente SET activation_code_istituto = ? WHERE email_istituto = ? AND activation_code_istituto = ?')) {
                // Set activation code to 'activated'.
                $newcode = 'activated';
                $stmt->bind_param('sss', $newcode, $_GET['emailIstituto'], $_GET['code']);
                $stmt->execute();
                echo 'Email verificata con successo, ora l\'email dell\'istituto inserita è associata al tuo account!';
                // Rimando alla pagina di login dopo 2 secondi.
                header("refresh:2;url=login.html");
            }
        } else {
            echo 'Verifica già avvenuta oppure email non trovata! Stai per essere reindirizzato alla pagina di login...';
            header("refresh:2;url=login.html");
        }
    }
}
?>
<head>
    <?php
    include "common/dipendenze-head.php";
    ?>
    <title>Attivazione</title>
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
