<?php
session_start();
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
                                <img src="img/carrello.png" class="p-1" alt="Carrello" width="50" height="50" class="elemento" onclick="window.location.href=\'carrello.php\'">
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
    ?>


<div class='container mb-3'>
    <div class='row justify-content-center pt-1 rounded'>
        <div class='col-12'>
            <div class='container'>
                <div class='row'>
                    <div class='col-12 text-center'>
                        <h1 class='h1'>Benvenuto <?php echo $_SESSION['username'] ?>!</h1>
                        <p class="h5">Scegli i prodotti da ordinare:</p>
                        <p class="h6">Clicca per aprire la categoria.</p>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <hr>
    <div class="row bg-dark bg-opacity-75 rounded-3 pt-4">
        <div class="col-12">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <h1 class="text-center">Prodotti:</h1>
                    </div>
                </div>
                <div class="row justify-content-around">
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/antipasti.php" target="_self" class="text-decoration-none">
                        <p class="h3 text-center text-dark">Antipasti:</p>
                        <img src="https://www.giallozafferano.it/images/236-23676/Guacamole_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/primi.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Primi:</p>
                            <img src="https://www.giallozafferano.it/images/245-24560/Spaghetti-all-Amatriciana_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/secondi.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Secondi:</p>
                            <img src="https://www.giallozafferano.it/images/235-23580/Pollo-al-limone_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/contorni.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Contorni:</p>
                            <img src="https://www.giallozafferano.it/images/242-24202/Patate-al-forno_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/dessert.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Dessert:</p>
                            <img src="https://www.giallozafferano.it/images/222-22203/Dolce-presto-fatto_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/formaggi.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Formaggi:</p>
                            <img src="https://www.giallozafferano.it/images/speciali/3025/crostii-avocado-uova-strapazzate-e-asiago-BLOG-1147.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/bevande.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Bevande:</p>
                            <img src="https://www.giallozafferano.it/images/218-21853/Spritz_360x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/caffe.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Caffè:</p>
                            <img src="https://www.giallozafferano.it/images/229-22950/Crema-al-caffe_450x300.jpg" class="img-fluid rounded-3" alt="Cibi">
                        </a>
                    </div>
                    <div class="col-3 m-3 bg-light bg-opacity-75 rounded-3 pb-3 pt-2 shadow border border-dark border-3 elemento">
                        <a href="categorie/amari.php" target="_self" class="text-decoration-none">
                            <p class="h3 text-center text-dark">Amari:</p>
                            <img src="https://blog.giallozafferano.it/incucinadaeva/wp-content/uploads/2019/08/Amaro-alla-rucola.png" class="img-fluid rounded-3" alt="Cibi">
                        </a>
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
                        <h3 class='text-center'>Non sei loggato, <a class='link-secondary' href='login.php'>clicca qui</a> per tornare alla pagina di login.</h3>
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