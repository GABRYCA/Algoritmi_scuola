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

    // Apro il file files/accounts.txt e leggo il contenuto:
    // username password
    // Divisi da uno spazio, e li salvo in un vettore associativo.
    $file = fopen("files/accounts.txt", "r");
    $accounts = array();
    while (!feof($file)) {
        $line = fgets($file);
        // rtrim rimuove gli spazi vuoti alla fine della stringa.
        $line = rtrim($line);
        $line = explode(" ", $line);
        $accounts[$line[0]] = $line[1];
    }
    fclose($file);

    // Verifico se l'utente esiste già
    if (isset($accounts[$_POST['username']])){
        echo '<div class="row">
                <div class="col">
                    <div class="container">
                        <div class="row">
                            <div class="col-12">
                                <h3 class="text-center">Username già esistente!</h3>
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

            // Se l'utente non esiste già, allora lo aggiungo al file accounts.txt
            $file = fopen("files/accounts.txt", "a");
            fwrite($file, "\n" . $_POST['username'] . " " . $_POST['password']);
            fclose($file);

            // Reindicizzo alla pagina di login
            header("Location: login.php");
        } else {
            echo '<div class="row">
                    <div class="col">
                        <div class="container">
                            <div class="row">
                                <div class="col-12">
                                    <h3 class="text-center">Le password non coincidono!</h3>
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
        </div>
    </div>
    <hr>
    <div class="row">
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
</div>



</body>
</html>