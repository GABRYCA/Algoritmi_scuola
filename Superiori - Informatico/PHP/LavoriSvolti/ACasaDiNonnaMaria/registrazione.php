<?php
session_start();
if (isset($_SESSION['username'])){
    header("Location: prodotti.php");
}
?>
<html>
<head>
    <meta charset="UTF-8">
    <title>La casa di nonna Maria</title>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.js"
            integrity="sha512-zlWWyZq71UMApAjih4WkaRpikgY9Bz1oXIW5G0fED4vk14JjGlQ1UmkGM392jEULP8jbNMiwLWdM8Z87Hu88Fw=="
            crossorigin="anonymous" referrerpolicy="no-referrer"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.css"
          integrity="sha512-wJgJNTBBkLit7ymC6vvzM1EcSWeM9mmOu+1USHaRBbHkm6W9EgM0HY27+UtUaprntaYQJF75rc8gjxllKs5OIQ=="
          crossorigin="anonymous" referrerpolicy="no-referrer"/>
    <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
            integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
</head>
<body class="bg-dark bg-opacity-75 text-light font-monospace">
<div class="container-fluid">
    <div class="row justify-content-center bg-dark pt-1 rounded-bottom">
        <!-- Titolo A casa di Nonna Maria -->
        <div class="col-12">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <h1 class="text-center">A casa di Nonna Maria</h1>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<hr>

<?php
if (isset($_POST['username']) && isset($_POST['password']) && isset($_POST['password2'])) {

    // Verifico se esiste files/accounts.txt, se non esiste lo creo.
    if (!file_exists('files/accounts.txt')) {
        $file = fopen('files/accounts.txt', 'w');
        fclose($file);
    }

    $accounts = array();

    if (filesize('files/accounts.txt') > 0) {
        // Apro il file files/accounts.txt e leggo il contenuto:
        // username password
        // Divisi da uno spazio, e li salvo in un vettore associativo.
        $file = fopen("files/accounts.txt", "r");
        while (!feof($file)) {
            $line = fgets($file);
            // rtrim rimuove gli spazi vuoti alla fine della stringa.
            $line = rtrim($line);
            $line = explode(":", $line);
            $accounts[$line[0]] = $line[1];
        }
        fclose($file);
    }

    // Verifico se l'utente esiste già
    if (isset($accounts[$_POST['username']])){
        echo '<div class="row">
                <div class="col">
                    <div class="container">
                        <div class="row">
                            <div class="col-12">
                                <h3 class="text-center text-decoration-underline text-danger">Username già esistente!</h3>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <hr>';
    } else {

        // Controllo se le password sono uguali
        if ($_POST['password'] == $_POST['password2']) {
            $username = $_POST['username'];
            $password = $_POST['password'];

            // Controllo se il file è vuoto, nel caso lo sia allora aggiungo l'utente senza andare a capo.
            $file = fopen("files/accounts.txt", "r");
            if (filesize("files/accounts.txt") == 0) {
                $file = fopen("files/accounts.txt", "a");
                fwrite($file, $username . ":" . $password);
                fclose($file);
            } else {
                // Se il file non è vuoto, allora aggiungo l'utente andando a capo.
                $file = fopen("files/accounts.txt", "a");
                fwrite($file, "\n" . $username . ":" . $password);
                fclose($file);
            }

            // Comunico che l'account è stato creato con successo.
            echo '<div class="row">
                    <div class="col">
                        <div class="container">
                            <div class="row">
                                <div class="col-12">
                                    <h3 class="text-center text-decoration-underline text-warning">Account creato con successo! Stai per essere reindirizzato alla pagina di login...</h3>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <hr>';

            // Dopo alcuni secondi reindirizzo alla pagina di login.
            header("refresh:5;url=login.php");
        } else {
            echo '<div class="row">
                    <div class="col">
                        <div class="container">
                            <div class="row">
                                <div class="col-12">
                                    <h3 class="text-center text-danger text-decoration-underline">Le password non coincidono!</h3>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <hr>';
        }
    }
}
?>

<div class="container">
    <div class="row">
        <div class="col-12">
            <h2 class="text-center">Registrazione:</h2>
            <p class="h6 text-center">Inserire i dati richiesti...</p>
        </div>
    </div>
    <hr>
    <div class="row bg-black bg-opacity-50 rounded-3 pt-2 shadow" data-aos="zoom-in">
        <div class="col">
            <!-- Form che chiede username e password per registrarsi. -->
            <form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
                <div class="mb-3">
                    <label for="username" class="form-label">Username:</label>
                    <input type="text" class="form-control" id="username" name="username" required>
                </div>
                <div class="mb-3">
                    <label for="password" class="form-label">Password:</label>
                    <input type="password" class="form-control" id="password" name="password" required>
                </div>
                <div class="mb-3">
                    <label for="password2" class="form-label">Conferma password:</label>
                    <input type="password" class="form-control" id="password2" name="password2" required>
                </div>
                <button type="submit" class="btn btn-primary">Registrati</button>
            </form>
        </div>
    </div>

    <hr class="mt-3 mb-3">

    <div class="row justify-content-start mb-5">
        <div class="col">
            <!-- Tasto torna indietro alla homepage.html -->
            <a href="homepage.html" class="btn btn-primary w-100 mt-2 shadow">Torna alla homepage</a>
        </div>
    </div>

</div>


<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>