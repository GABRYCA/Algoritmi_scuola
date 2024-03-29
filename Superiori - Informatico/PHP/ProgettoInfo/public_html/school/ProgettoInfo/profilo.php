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

// Preparo la query per ottenere i dati dell'utente.
$stmt = $con->prepare('SELECT nome, cognome, data_nascita, email_personale, email_istituto, nome_ruolo, username, activation_code_istituto FROM utente WHERE id_utente = ?');
// Ottengo i dati per ID riutilizzando quello in sessione.
$stmt->bind_param('i', $_SESSION['id']);
$stmt->execute();
$stmt->bind_result($nome, $cognome, $data_nascita, $email_personale, $email_istituto, $nome_ruolo, $username, $activation_code_istituto);
$stmt->fetch();
$stmt->close();

// Cambio format data di nascita in Europeo/Italia.
$data_nascita = date("d/m/Y", strtotime($data_nascita));

$email_istituto_impostata = true;
$amministratore = false;

if ($nome_ruolo == "admin") {
    $amministratore = true;
}

if ($email_istituto == null) {
    $email_istituto_impostata = false;
    // Variabile qui è un testo che apre un modale di id #impostaEmailIstituto.
    $impostaTasto = "<button type='button' class='btn btn-success' data-bs-toggle='modal' data-bs-target='#aggiungiEmailIstituto'>Imposta email istituto</button>";
    $email_istituto = "$impostaTasto";
} else {
    // Controllo se activation_code_istituto è "activated".
    if ($activation_code_istituto == "activated") {
        $tastoModifica = "<p class='text-center'><button type='button' class='btn btn-outline-warning w-100 mt-2 mb-2' data-bs-toggle='modal' data-bs-target='#aggiungiEmailIstituto'>Modifica email istituto</button>";
        $email_istituto = $email_istituto;
    } else {
        // Variabile qui è un testo che apre un modale di id #impostaEmailIstituto.
        $impostaTasto = "<button type='button' class='btn btn-success' data-bs-toggle='modal' data-bs-target='#aggiungiEmailIstituto'>Imposta email istituto</button>";
        $email_istituto = "$impostaTasto";
    }
}

?>
<!DOCTYPE html>
<html lang="it" data-bs-theme="dark">
<head>
    <?php
    include 'common/dipendenze-head.php';
    ?>
    <title>Profilo di <?php echo $username?></title>
    <script type="text/javascript">

        function deleteAccountFunction() {
            if (confirm('Sicuro di voler cancellare l\'account? L\'operazione è irreversibile!')) {

                var password = document.getElementById('password').value;
                password = password.replace(/</g, "&lt;").replace(/>/g, "&gt;");

                if (password !== '' && password !== null) {
                    $.ajax({
                        url: 'cancella.php',
                        type: 'POST',
                        data: {
                            password: password
                        },
                        success: function (data) {
                            if (data === 'success') {
                                alert('Account cancellato con successo!');
                                window.location.href = 'registrazione.html';
                            } else if (data === 'wrongPassword') {
                                alert('Password errata! Riprova!');
                            } else if (data === 'empty') {
                                alert('Inserisci la password per cancellare l\'account!')
                            } else {
                                alert('Errore durante la cancellazione dell\'account!');
                            }
                        }
                    });
                } else {
                    alert('Inserisci la password per cancellare l\'account!');
                }
            }
        }

        function changePasswordFunction() {
            if (confirm('Sei sicuro di voler cambiare la tua password?')) {

                // Prendo input.
                var oldPassword = document.getElementById('oldPassword').value;
                var newPassword = document.getElementById('newPassword').value;
                var newPasswordConfirm = document.getElementById('newPasswordConfirm').value;

                // Mi proteggo da attacchi XSS verificando i dati.
                newPassword = newPassword.replace(/</g, "&lt;").replace(/>/g, "&gt;");
                oldPassword = oldPassword.replace(/</g, "&lt;").replace(/>/g, "&gt;");
                newPasswordConfirm = newPasswordConfirm.replace(/</g, "&lt;").replace(/>/g, "&gt;");

                // Controllo che il campo non sia vuoto o nullo.
                if (newPassword !== '' && newPassword !== null && oldPassword !== '' && oldPassword !== null && newPasswordConfirm !== '' && newPasswordConfirm !== null) {
                    $.ajax({
                        url: 'cambiaPassword.php',
                        type: 'POST',
                        data: {
                            oldPassword: oldPassword,
                            newPassword: newPassword,
                            newPasswordConfirm: newPasswordConfirm
                        },
                        success: function (data) {
                            if (data === 'success') {
                                alert('Password cambiata con successo!');
                                // Chiudo il modale.
                                $('#modificaPasswordModale').modal('hide');
                            } else if (data === 'short') {
                                alert('Password troppo corta! (min 6 caratteri)')
                            } else if (data === 'long') {
                                alert('Password troppo lunga! (max 20 caratteri)')
                            } else if (data === 'notMatch') {
                                alert('Le password non corrispondono!');
                            } else if (data === 'wrongPassword') {
                                alert('La vecchia password non è corretta!');
                            } else if (data === 'empty') {
                                alert('Uno o più campi sono vuoti!');
                            } else {
                                alert('Errore durante la modifica della password!');
                            }
                        }
                    });
                } else {
                    alert('Uno o più campi sono vuoti!');
                }
            }
        }

        function aggiungiEmailIstituto(){
            if (confirm('Sei sicuro di voler aggiungere questa email?')) {

                // Prendo input.
                var emailIstituto = document.getElementById('emailIstituto').value;

                // Mi proteggo da attacchi XSS verificando i dati.
                emailIstituto = emailIstituto.replace(/</g, "&lt;").replace(/>/g, "&gt;");

                // Controllo che il campo non sia vuoto o nullo.
                if (emailIstituto !== '' && emailIstituto !== null) {
                    $.ajax({
                        url: 'aggiungiEmailIstituto.php',
                        type: 'POST',
                        data: {
                            emailIstituto: emailIstituto
                        },
                        success: function (data) {
                            if (data === 'success') {
                                alert('Email aggiunta con successo!');
                                // Chiudo il modale.
                                alert('Controlla la tua email per confermare l\'email dell\'istituto!')
                                $('#aggiungiEmailIstitutoModale').modal('hide');
                            } else if (data === 'invalid') {
                                alert('Email non valida o istituto non trovato, se ritieni che la tua sia una email valida, per favore contattare l\'amministratore!')
                            } else if (data === 'empty') {
                                alert('Inserire l\'email!');
                            } else if (data === 'exists'){
                                alert('Email già presente su un account!');
                            } else {
                                alert('Errore durante l\'aggiunta dell\'email!');
                            }
                        }
                    });
                } else {
                    alert('Uno o più campi sono vuoti!');
                }
            }
        }
    </script>
</head>
<body class="font-monospace text-light bg-black">

<!-- Navbar -->
<div class="container-fluid bg-dark pb-3 pt-3 rounded-bottom border-bottom border-light">
    <nav class="navbar navbar-expand-lg navbar-dark">
        <div class="container">
            <a class="navbar-brand" href="profilo.php">AnonymousSpot</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
                <div class="navbar-nav">
                    <a class="nav-link active" aria-current="page" href="profilo.php">Profilo</a>
                    <a class="nav-link" href="spots.php">Visualizza</a>
                    <a class="nav-link" href="inviaMessaggio.php">Invia</a>
                    <a class="nav-link link-danger" href="logout.php">Logout</a>
                </div>
            </div>
        </div>
    </nav>
</div>

<div class="container mb-3">

    <div class="row bg-dark border-start border-end border-top mt-4 mb-4 pt-2 rounded-4">
        <div class="col">
            <p class="h1 text-center">Profilo:</p>
        </div>
    </div>

    <hr>

    <div class="row border border-light border-opacity-25 rounded-4 p-3 bg-dark shadow-lg mt-4">
        <div class="col">
            <div class="row">
                <div class="col">
                    <p class="h3 text-center">Informazioni personali:</p>
                    <hr>
                    <p class="h5">Username: <?php echo $username; ?></p>
                    <p class="h5">Nome: <?php echo $nome; ?></p>
                    <p class="h5">Cognome: <?php echo $cognome; ?></p>
                    <p class="h5">Data di nascita: <?php echo $data_nascita; ?></p>
                    <p class="h5">Ruolo: <?php echo $nome_ruolo; ?></p>
                    <p class="h5">Email personale: <?php echo $email_personale; ?></p>
                    <p class="h5">Email istituzionale: <?php echo $email_istituto; ?></p>
                </div>
                <hr class="mt-2">
                <?php if ($activation_code_istituto == "activated"){?>
                    <div class="row">
                        <div class="col">
                            <?php echo $tastoModifica;?>
                        </div>
                    </div>
                    <hr>
                <?php } ?>
                <div class="row">
                    <div class="col">
                        <a href="logout.php" class="btn btn-danger mt-2 mb-2 w-100">Logout</a>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <hr class="mt-4 mb-4">

    <!-- Zona funzioni (come invio messaggio) -->
    <div class="row bg-warning bg-opacity-10 border border-warning border-opacity-50 shadow-lg rounded-4 p-4">
        <div class="col">
            <p class="h3 text-center">Scorciatoie:</p>
            <hr>
            <?php
            // Se amministratore, creo un pulsante per aprire amministratore.php.
            if ($amministratore){
            ?>
            <div class="row">
                <div class="col">
                    <a href="amministratore.php" class="btn btn-outline-warning mt-2 mb-2 w-100">Amministrazione</a>
                </div>
            </div>
            <?php
            }
            ?>
            <?php

            // Verifico se in appartenenza l'utente fa parte di almeno un luogo.
            $query = "SELECT * FROM appartenenza WHERE id_utente = ?";
            $id = $_SESSION['id'];
            $stmt = $con->prepare($query);
            $stmt->bind_param('i', $id);
            $stmt->execute();

            // Se almeno un luogo è stato trovato, mostro il bottone per inviare messaggi.
            if ($stmt->get_result()->num_rows > 0){
                $stmt->close();
            ?>
            <div class="row">
                <div class="col">
                    <a href="inviaMessaggio.php" class="btn btn-outline-warning mt-2 mb-2 w-100">Invia messaggio spot</a>
                </div>
            </div>
            <?php
            } else {
                $stmt->close();
                // Non appartiene a nessun luogo, lo comunico.
                echo '<div class="row"><div class="col"><p class="h5 text-center text-danger">Non appartieni a nessun luogo, non puoi inviare messaggi.</p></div></div>';
            }
            ?>
        </div>
    </div>

    <hr class="mt-4 mb-4">

    <div class="row border border-danger bg-danger border-opacity-50 bg-opacity-10 shadow-lg rounded-4 p-4">
        <div class="col">
            <div class="row">
                <div class="col">
                    <p class="h3 text-center">Danger Zone:</p>
                </div>
            </div>

            <hr>

            <!-- Change password button -->
            <div class="row mt-3">
                <div class="col">
                    <button type="button" class="btn btn-primary w-100" data-bs-toggle="modal" data-bs-target="#modificaPasswordModale">Modifica password</button>
                </div>
            </div>

            <hr>

            <!-- Pulsante che apre il modale bootstrap per cancellare l'account. -->
            <button type="button" class="btn btn-danger w-100" data-bs-toggle="modal" data-bs-target="#cancellaAccountModale">Cancella account</button>

        </div>
    </div>





    <!-- --------------------- -->
    <!-- AREA MODALI BOOTSTRAP -->
    <!-- --------------------- -->

    <!-- Modale cancellazione account -->
    <div class="modal fade text-light bg-danger bg-opacity-75" id="cancellaAccountModale" tabindex="-1" aria-labelledby="cancellaAccountModale" aria-hidden="true">
        <div class="modal-dialog modal-dialog-centered">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title fs-5">Conferma cancellazione account:</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
                </div>
                <div class="modal-body">
                    <label for="password" class="form-label">Inserisci la tua password per confermare:</label>
                    <input type="password" class="form-control" id="password" placeholder="Password">
                </div>
                <div class="modal-footer text-center">
                    <div class="row w-100 justify-content-center">
                        <div class="col">
                            <button type="button" class="btn btn-primary w-100" data-bs-dismiss="modal">Annulla</button>
                        </div>
                        <div class="col">
                            <!-- Pulsante che chiama la funzione di cancellazione account -->
                            <button type="button" class="btn btn-danger w-100" onclick="deleteAccountFunction()">Conferma</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <!-- Modale modifica password -->
    <div class="modal fade text-light bg-dark bg-opacity-10" id="modificaPasswordModale" tabindex="-1" aria-labelledby="modificaPasswordModale" aria-hidden="true">
        <div class="modal-dialog modal-dialog-centered">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title fs-5">Conferma modifica password:</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
                </div>
                <div class="modal-body">
                    <!-- Chiedo la nuova password -->
                    <div class="row">
                        <div class="col">
                            <label for="oldPassword" class="form-label">Vecchia password:</label>
                            <input type="password" class="form-control" id="oldPassword" placeholder="Inserisci la vecchia password">
                            <hr>
                            <label for="newPassword" class="form-label">Nuova password:</label>
                            <input type="password" class="form-control" id="newPassword" placeholder="Inserisci la nuova password">
                            <label for="newPasswordConfirm" class="form-label mt-2">Conferma nuova password:</label>
                            <input type="password" class="form-control" id="newPasswordConfirm" placeholder="Conferma la nuova password">
                        </div>
                    </div>
                </div>
                <div class="modal-footer text-center">
                    <div class="row w-100 justify-content-center">
                        <div class="col">
                            <button type="button" class="btn btn-primary w-100" data-bs-dismiss="modal">Annulla</button>
                        </div>
                        <div class="col">
                            <!-- Pulsante che chiama la funzione di cancellazione account -->
                            <button type="button" class="btn btn-danger w-100" onclick="changePasswordFunction()">Conferma</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <!-- Modale aggiungi email d'istituto id impostaEmailIstitutoModale -->
    <div class="modal fade text-light bg-dark bg-opacity-10" id="aggiungiEmailIstituto" tabindex="-1" aria-labelledby="aggiungiEmailIstituto" aria-hidden="true">
        <div class="modal-dialog modal-dialog-centered">
            <div class="modal-content">
                <div class="modal-header">
                    <h1 class="modal-title fs-5">Inserisci email dell'istituto:</h1>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Annulla"></button>
                </div>
                <div class="modal-body">
                    <div class="row">
                        <div class="col">
                            <label for="emailIstituto" class="form-label">Email istituto (es. nome.cognome@edu.cobianchi.it):</label>
                            <input type="email" class="form-control" id="emailIstituto" placeholder="Inserisci l'email dell'istituto">
                        </div>
                    </div>
                </div>
                <div class="modal-footer text-center">
                    <div class="row w-100 justify-content-center">
                        <div class="col">
                            <button type="button" class="btn btn-primary w-100" data-bs-dismiss="modal">Annulla</button>
                        </div>
                        <div class="col">
                            <!-- Pulsante che chiama la funzione di cancellazione account -->
                            <button type="button" class="btn btn-danger w-100" onclick="aggiungiEmailIstituto()">Conferma</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>


</div>

<?php
    include 'common/footer.php';
    include 'common/dipendenze-body.php';
?>
</body>
</html>