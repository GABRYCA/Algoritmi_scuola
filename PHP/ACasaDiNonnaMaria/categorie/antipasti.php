<?php
session_start();

// Vettore di antipasti associato con prezzo
$antipasti = array(
    "Focaccia alla genovese" => 10.00,
    "Guacamole" => 8.00,
    "Arancini di riso" => 6.00,
);

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
                    <div class="col-12">
                        <h1 class="text-center">A casa di Nonna Maria</h1>
                    </div>
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
        // Aggiungo il prodotto al carrello, ma prima controllo se esiste già
        $_SESSION['carrello'][$_POST['nome']] = $_POST['quantita'];

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
                            <h1 class="text-center">Antipasti:</h1>
                        </div>
                    </div>
                    <div class="row justify-content-around">

                        <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3">
                            <p class="h3 text-center text-dark">Focaccia alla genovese:</p>
                            <img src="https://www.giallozafferano.it/images/224-22468/Focaccia-fugassa-alla-genovese_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                            <!-- Form per aggiungere il prodotto al carrello e modificarne la quantità -->
                            <form action="antipasti.php" method="post">
                                <input type="hidden" name="nome" value="Focaccia alla genovese">
                                <div class="row justify-content-center mt-2">
                                    <div class="col-12">
                                        <p class="h5 text-center text-dark">Prezzo: €<?php echo $antipasti['Focaccia alla genovese']?></p>
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12">
                                        <p class="h5 text-center text-dark">Quantità:</p>
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12">
                                        <input type="number" name="quantita" class="form-control" value="1" min="0" max="10">
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12 text-center">
                                        <button type="submit" class="btn btn-dark mt-3">Aggiungi al carrello</button>
                                    </div>
                                </div>
                            </form>
                        </div>

                        <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3">
                            <p class="h3 text-center text-dark">Guacamole:</p>
                            <img src="https://www.giallozafferano.it/images/236-23676/Guacamole_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                            <!-- Form per aggiungere il prodotto al carrello e modificarne la quantità -->
                            <form action="antipasti.php" method="post">
                                <input type="hidden" name="nome" value="Focaccia alla genovese">
                                <div class="row justify-content-center mt-2">
                                    <div class="col-12">
                                        <p class="h5 text-center text-dark">Prezzo: €<?php echo $antipasti['Guacamole']?></p>
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12">
                                        <p class="h5 text-center text-dark">Quantità:</p>
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12">
                                        <input type="number" name="quantita" class="form-control" value="1" min="0" max="10">
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12 text-center">
                                        <button type="submit" class="btn btn-dark mt-3">Aggiungi al carrello</button>
                                    </div>
                                </div>
                            </form>
                        </div>

                        <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3">
                            <p class="h3 text-center text-dark">Arancini di riso:</p>
                            <img src="https://www.giallozafferano.it/images/2-247/Arancini-di-riso_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                            <!-- Form per aggiungere il prodotto al carrello e modificarne la quantità -->
                            <form action="antipasti.php" method="post">
                                <input type="hidden" name="nome" value="Focaccia alla genovese">
                                <div class="row justify-content-center mt-2">
                                    <div class="col-12">
                                        <p class="h5 text-center text-dark">Prezzo: €<?php echo $antipasti['Arancini di riso']?></p>
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12">
                                        <p class="h5 text-center text-dark">Quantità:</p>
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12">
                                        <input type="number" name="quantita" class="form-control" value="1" min="0" max="10">
                                    </div>
                                </div>
                                <div class="row justify-content-center">
                                    <div class="col-12 text-center">
                                        <button type="submit" class="btn btn-dark mt-3">Aggiungi al carrello</button>
                                    </div>
                                </div>
                            </form>
                        </div>

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
    <?php
    }
    ?>
</body>
</html>