<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>G.C. Ristorante</title>
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
</head>
<body class="bg-dark">
<!-- Creare un form che mostri i piatti ordinabili in un ipotetico ristorante online;
il modulo contiene gli antipasti, i primi, i secondi, i contorni e le bevande.

A seconda della scelta effettuata, deve mostrare il prezzo complessivo usando la tecnica postback per leggere
i campi del form.
-->
<?php
if ($_POST == true){
    // Array con i piatti e i loro prezzi associati, name corrisponde a quelli negli input dei form
    $menu = [
            "guacamole" => 5.00,
        "hummus" => 4.50,
        "focaccia" => 6.50,
        "carbonara" => 8.00,
        "risottozucca" => 8.50,
        "amatriciana" => 13.50,
        "polpettesugo" => 9.50,
        "pollolimone" => 10.50,
        "spezzatinomanzo" => 12.50,
        "patateforno" => 4.00,
        "purepatate" => 4.50,
        "tempura" => 8.50,
        "limoncello" => 6.00,
        "spritz" => 4.90,
        "mojito" => 7.50,
            ];

    // Stampo i singoli prodotti ordinati in un "toast".
    echo "<script>
        $.toast({
            heading: 'Ordine:',
            text: '";
    foreach ($_POST as $key => $value){
        if (array_key_exists($key, $menu)){
            if ($value > 0){
                echo "$key: € $menu[$key] x $value<br>";
            }
        }
    }
    echo "',
            position: 'top-right',
            loaderBg: '#ff6849',
            icon: 'success',
            hideAfter: 10000,
            stack: 6
        });
        </script>";

    // Verifico se i nomi dei post sono presenti nell'array
    $totale = 0;
    foreach ($_POST as $key => $value){
        if (array_key_exists($key, $menu)){
            if ($value > 0){
                $totale += $value * $menu[$key];
            }
        }
    }

    // Stampo il totale.
    echo "<script>
        $.toast({
            heading: 'Ordine effettuato con successo! <br><br>Totale ordine:',
            text: '€ $totale',
            position: 'top-right',
            loaderBg: '#ff6849',
            icon: 'success',
            hideAfter: 10000,
            stack: 6
        });
        </script>";

} //else {
?>
<div class="container">
    <div class="row bg-light bg-opacity-25 rounded-bottom mb-3">
        <div class="col">
            <p class="h1 text-center text-light">Ristorante d'esempio</p>
        </div>
    </div>
    <hr class="text-light">
    <form action="<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
        <div class="row">
            <p class="text-light text-center h3 mb-1">Antipasti</p>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Guacamole</p>
                <img src="https://www.giallozafferano.it/images/236-23676/Guacamole_360x300.jpg" alt="Guacamole" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €5.00</p>
                <input type="number" name="guacamole" id="guacamole" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Hummus</p>
                <img src="https://www.giallozafferano.it/images/243-24308/Hummus_360x300.jpg" alt="Hummus" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €4.50</p>
                <input type="number" name="hummus" id="hummus" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Focaccia</p>
                <img src="https://www.giallozafferano.it/images/224-22468/Focaccia-fugassa-alla-genovese_360x300.jpg" alt="Focaccia" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €6.50</p>
                <input type="number" name="focaccia" id="focaccia" class="form-control" min="0" max="10" value="0">
            </div>
        </div>
        <hr class="text-light mt-5">
        <div class="row">
            <p class="text-light text-center h3 mb-3">Primi</p>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Spaghetti alla Carbonara</p>
                <img src="https://www.giallozafferano.it/images/244-24489/Spaghetti-alla-Carbonara_360x300.jpg" alt="Guacamole" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €8.00</p>
                <input type="number" name="carbonara" id="carbonara" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Risotto alla zucca</p>
                <img src="https://www.giallozafferano.it/images/0-44/Risotto-alla-zucca_360x300.jpg" alt="Risotto alla Zucca" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €8.50</p>
                <input type="number" name="risottozucca" id="risottozucca" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Spaghetti all'Amatriciana</p>
                <img src="https://www.giallozafferano.it/images/245-24560/Spaghetti-all-Amatriciana_360x300.jpg" alt="Amatriciana" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €13.50</p>
                <input type="number" name="amatriciana" id="amatriciana" class="form-control" min="0" max="10" value="0">
            </div>
        </div>
        <hr class="text-light mt-5">
        <div class="row">
            <p class="text-light text-center h3">Secondi</p>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Polpette al sugo</p>
                <img src="https://www.giallozafferano.it/images/241-24154/Polpette-al-sugo_360x300.jpg" alt="Polpette al sugo" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €9.50</p>
                <input type="number" name="polpettesugo" id="polpettesugo" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Pollo al limone</p>
                <img src="https://www.giallozafferano.it/images/235-23580/Pollo-al-limone_360x300.jpg" alt="Pollo al limone" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €10.50</p>
                <input type="number" name="pollolimone" id="pollolimone" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Spezzatino di manzo</p>
                <img src="https://www.giallozafferano.it/images/182-18210/Spezzatino-di-manzo_360x300.jpg" alt="Spezzatino di manzo" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €12.50</p>
                <input type="number" name="spezzatinomanzo" id="spezzatinomanzo" class="form-control" min="0" max="10" value="0">
            </div>
        </div>
        <hr class="text-light mt-5">
        <div class="row">
            <p class="text-light text-center h3">Contorni</p>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Patate al forno</p>
                <img src="https://www.giallozafferano.it/images/242-24202/Patate-al-forno_360x300.jpg" alt="Patate al forno" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €4.00</p>
                <input type="number" name="patateforno" id="patateforno" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Purè di patate</p>
                <img src="https://www.giallozafferano.it/images/241-24127/Pure-di-patate_360x300.jpg" alt="Purè di patate" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €4.50</p>
                <input type="number" name="purepatate" id="purepatate" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">tempura</p>
                <img src="https://www.giallozafferano.it/images/208-20845/Tempura_360x300.jpg" alt="Tempura" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €8.50</p>
                <input type="number" name="tempura" id="tempura" class="form-control" min="0" max="10" value="0">
            </div>
        </div>
        <hr class="text-light mt-5">
        <div class="row">
            <p class="text-light text-center h3">Bevande</p>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Limoncello</p>
                <img src="https://www.giallozafferano.it/images/171-17147/Limoncello_360x300.jpg" alt="Limoncello" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €6.00</p>
                <input type="number" name="limoncello" id="limoncello" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Spritz</p>
                <img src="https://www.giallozafferano.it/images/218-21853/Spritz_360x300.jpg" alt="Spritz" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €4.90</p>
                <input type="number" name="spritz" id="spritz" class="form-control" min="0" max="10" value="0">
            </div>
            <div class="col bg-black bg-opacity-25 text-center rounded-3 p-3 m-2">
                <p class="text-light h3">Mojito</p>
                <img src="https://www.giallozafferano.it/images/5-570/Mojito_360x300.jpg" alt="Mojito" class="img-fluid rounded-3">
                <p class="h4 text-light pt-3">Prezzo: €7.50</p>
                <input type="number" name="mojito" id="mojito" class="form-control" min="0" max="10" value="0">
            </div>
        </div>
        <hr class="text-light mt-5">
        <!-- Pulsante per inviare l'ordine e php calcolerà il prezzo finale -->
        <div class="row pt-5 pb-5 mb-3 bg-black bg-opacity-25 rounded-3">
            <div class="col text-center">
                <input type="submit" value="Invia ordine" class="btn btn-success w-75 pb-3 pt-3">
            </div>
        </div>
    </form>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>

<?php
//}
?>
</body>
</html>