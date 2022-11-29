<?php
session_start();

// Se ho ricevuto un POST per rimuoere un prodotto dal carrello, lo rimuovo se esiste un SESSION username e un SESSION carrello.
if (isset($_POST['rimuoviProdotto']) && isset($_SESSION['username']) && isset($_SESSION['carrello'])) {
    // Controllo se il prodotto esiste nel carrello.
    if (array_key_exists($_POST['nome'], $_SESSION['carrello'])) {
        $nome = $_POST['nome'];
        // Rimuovo il prodotto dal carrello.
        unset($_SESSION['carrello'][$_POST['nome']]);
    }
}

if (isset($_POST['logout'])){
    session_destroy();
    header("Location: homepage.html");
}

if (isset($_POST['reset'])){
    // Rimuovo tutti i prodotti dal carrello.
    $_SESSION['carrello'] = array();
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
    <style>
        .elemento {
            transition-duration: 0.2s;
        }

        .elemento:hover {
            transform: scale(1.1);
            cursor: pointer;
        }
    </style>
</head>
<body class="bg-dark bg-opacity-75 text-light font-monospace">
<div class="container-fluid">
    <div class="row justify-content-center bg-dark pt-1 rounded-bottom">
        <!-- Titolo A casa di Nonna Maria -->
        <div class="col-12">
            <div class="container">
                <div class="row">
                    <div class="col-11">
                        <h1 class="text-center">A casa di Nonna Maria</h1>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<hr>

<?php
if (isset($_SESSION['username'])) {
?>

    <div class="container">
        <div class="row">
            <div class="col-12">
                <h1 class="text-center pt-1">Carrello:</h1>
            </div>
        </div>
        <hr>
        <div class="row mb-3">
            <div class="col-12 text-center">
                <a href="prodotti.php" class="btn btn-dark mt-3 w-75"><p class="h2 pt-1">Torna ai prodotti.</p></a>
            </div>
        </div>
        <div class="row justify-content-center">
            <div class="col-12">
                <table class="table table-dark table-striped table-hover">
                    <thead>
                    <tr>
                        <th scope="col">Nome</th>
                        <th scope="col">Prezzo</th>
                        <th scope="col">Quantità</th>
                        <th scope="col">Prezzo totale</th>
                        <th scope="col">Rimuovi</th>
                    </tr>
                    </thead>
                    <tbody class="align-middle">
                    <?php
                    $totale = 0;
                    foreach ($_SESSION['carrello'] as $nome => $valori) {
                        $prezzoTotale = $valori['quantita'] * $valori['prezzo'];
                        $totale += $prezzoTotale;
                        echo '<tr>
                                <td>' . $nome . '</td>
                                <td>€' . $valori['prezzo'] . '</td>
                                <td>' . $valori['quantita'] . '</td>
                                <td>€' . $prezzoTotale . '</td>
                                <td>
                                <!-- Form per rimuovere un prodotto dal carrello. -->
                                <!-- Il form invia il nome del prodotto da rimuovere tramite POST. -->
                                
                                <form action="carrello.php" method="post">
                                    <input type="hidden" name="rimuoviProdotto" value="true">
                                    <input type="hidden" name="nome" value="' . $nome . '">
                                    <input type="hidden" name="rimuovi" value="true">
                                    <button type="submit" class="btn btn-danger mt-3">Rimuovi</button>
                                </form>
                                </td>
                            </tr>';
                    }
                    // Stampo l'ultima riga con il totale
                    echo '<tr>
                            <td colspan="3" class="text-end">Totale:</td>
                            <td>€' . $totale . '</td>
                            <td></td>
                        </tr>';
                    ?>
                    </tbody>
                </table>
            </div>
        </div>
        <div class="row">
            <!-- Tasto logout che distrugge la sessione, e tasto reset che rimuove tutti gli elementi dal carrello della sessione. -->
            <div class="col-6 text-center">
                <form action="carrello.php" method="post">
                    <input type="hidden" name="logout" value="true">
                    <button type="submit" class="btn btn-danger w-75">Logout</button>
                </form>
            </div>
            <div class="col-6 text-center">
                <form action="carrello.php" method="post">
                    <input type="hidden" name="reset" value="true">
                    <button type="submit" class="btn btn-danger w-75">Reset</button>
                </form>
            </div>
        </div>
    </div>

<?php } else { ?>

<div class='container pt-1'>
    <div class='row justify-content-center bg-dark pt-1 rounded-3'>
        <div class='col-12'>
            <div class='container'>
                <div class='row'>
                    <div class='col-12'>
                        <h3 class='text-center'>Non sei loggato, <a class='link-secondary' href='login.php'>clicca qui</a> per tornare alla pagina di login.</h3>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<?php } ?>

</body>
</html>
