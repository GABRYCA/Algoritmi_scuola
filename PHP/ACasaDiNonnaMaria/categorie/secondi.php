<?php
session_start();

// Vettore di antipasti associato con prezzo
$antipasti = array(
    "Pollo al limone" => 9.50,
    "Pollo alle mandorle" => 8.00,
    "Parmigiana di melanzane" => 6.00,
);

// Vettore associativo con i link alle immagini dei prodotti
$immagini = array(
    "Pollo al limone" => "https://www.giallozafferano.it/images/235-23580/Pollo-al-limone_360x300.jpg",
    "Pollo alle mandorle" => "https://www.giallozafferano.it/images/229-22993/Pollo-alle-mandorle_360x300.jpg",
    "Parmigiana di melanzane" => "https://www.giallozafferano.it/images/234-23446/Parmigiana-di-melanzane_360x300.jpg",
)

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
                    <?php
                    if (isset($_SESSION['carrello'])) {
                        // Creo l'immagine di un carrello con accanto il numero di prodotti contenuti in esso.
                        echo '<div class="col-1 text-center bg-success rounded-3 mb-1 elemento p-1">
                                <img src="../img/carrello.png" class="p-1" alt="Carrello" width="50" height="50" class="elemento" onclick="window.location.href=\'/ACasaDiNonnaMaria/carrello.php\'">
                                <span class="badge bg-danger" id="numeroProdotti">' . count($_SESSION['carrello']) . '</span>
                            </div>';
                    }
                    ?>
                </div>
            </div>
        </div>
    </div>
</div>

<hr>

<!-- Controllo se esiste la sessione, nel caso esista stampo un messaggio di benvenuto -->
<?php
if (isset($_SESSION['username'])) {

    if (isset($_POST['nome']) && isset($_POST['quantita'])) {
        // Aggiungo il prodotto al carrello, impostando la quantità ricevuta, il nome e il prezzo associato, la SESSION
        // potrebbe già esistere, se il prodotto è presente modifico la quantità e i dati, se non esiste lo aggiungo
        $_SESSION['carrello'][$_POST['nome']] = array(
            "quantita" => $_POST['quantita'],
            "prezzo" => $antipasti[$_POST['nome']]
        );

        $nome = $_POST['nome'];

        echo "<script>$.toast({
            heading: 'Prodotto aggiunto al carrello',
            text: 'Il prodotto \"$nome\" è stato aggiunto al carrello',
            showHideTransition: 'slide',
            icon: 'success',
            position: 'top-right',
            hideAfter: 3000,
            stack: 6
        })</script>";
    }

    ?>


    <div class='container mb-3'>
        <div class='row justify-content-center pt-1 rounded'>
            <div class='col-12'>
                <div class='container'>
                    <div class='row'>
                        <div class='col-12 text-center'>
                            <p class="h5">Scegli i prodotti da ordinare:</p>
                            <p class="h6">Impostare la quantità e premere "aggiungi al carrello".</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <hr>
        <div class="row">
            <div class="col-12 text-center">
                <a href="../prodotti.php" class="btn btn-dark mt-3 w-75"><p class="h2 pt-1">Torna ai prodotti.</p></a>
            </div>
        </div>
        <hr class="mt-4">
        <div class="row bg-dark bg-opacity-75 rounded-3 pt-4">
            <div class="col-12">
                <div class="container">
                    <div class="row">
                        <div class="col-12">
                            <h1 class="text-center">Secondi:</h1>
                        </div>
                    </div>
                    <div class="row justify-content-around">

                        <?php
                        // Stampo tutti gli antipasti
                        foreach ($antipasti as $nome => $prezzo) {
                            echo '
                                <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3">
                                    <p class="h3 text-center text-dark">' . $nome . '</p>
                                    <img src="' . $immagini[$nome] . '" class="img-fluid rounded-3" alt="' . $nome . '">
                                    <form action="' . $_SERVER['PHP_SELF'] . '" method="post">
                                        <input type="hidden" name="nome" value="' . $nome . '">
                                        <div class="row justify-content-center mt-2">
                                            <div class="col-12">
                                                <p class="h5 text-center text-dark">Prezzo: €' . $prezzo . '</p>
                                            </div>
                                        </div>
                                        <div class="row justify-content-center">
                                            <div class="col-12">
                                                <p class="h5 text-center text-dark">Quantità:</p>
                                            </div>
                                        </div>
                                        <div class="row justify-content-center">
                                            <div class="col-12">
                                                <input type="number" name="quantita" class="form-control text-center" min="1" max="10" value="1">
                                            </div>
                                        </div>
                                        <div class="row justify-content-center">
                                            <div class="col-12 text-center">
                                                <button type="submit" class="btn btn-dark mt-3">Aggiungi al carrello</button>
                                            </div>
                                        </div>
                                    </form>
                                </div>
                            ';
                        }
                        ?>
                    </div>
                </div>
            </div>
        </div>
    </div>


    <?php
} else {
    ?>
    <div class='container pt-1'>
        <div class='row justify-content-center bg-dark pt-1 rounded-3'>
            <div class='col-12'>
                <div class='container'>
                    <div class='row'>
                        <div class='col-12'>
                            <h3 class='text-center'>Non sei loggato, <a class='link-secondary' href='../login.php'>clicca qui</a> per tornare alla pagina di login.</h3>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <?php
}
?>
</body>
</html>