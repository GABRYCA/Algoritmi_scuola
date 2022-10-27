<?php
// Prendo il dato dal POST e poi rappresento il numero in lettere e in una immagine
$numero = $_POST['numero'];

switch ($numero){
    case 1:
        echo "<h1 style='text-align: center'>uno</h1>";
        echo "<img src='https://padova.scuoledieffe.it/site/uploads/2019/06/1024px-NYCS-bull-trans-1.svg_.png' alt='uno' />";
        break;
    case 2:
        echo "<h1 style='text-align: center'>due</h1>";
        echo "<img src='https://upload.wikimedia.org/wikipedia/commons/thumb/6/61/NYCS-bull-trans-2.svg/2048px-NYCS-bull-trans-2.svg.png' alt='due' />";
        break;
    case 3:
        echo "<h1 style='text-align: center'>tre</h1>";
        echo "<img src='https://upload.wikimedia.org/wikipedia/commons/thumb/2/25/NYCS-bull-trans-3.svg/1200px-NYCS-bull-trans-3.svg.png' alt='tre' />";
        break;
    case 4:
        echo "<h1 style='text-align: center'>quattro</h1>";
        echo "<img src='https://upload.wikimedia.org/wikipedia/commons/thumb/b/ba/NYCS-bull-trans-4-red.svg/2048px-NYCS-bull-trans-4-red.svg.png' alt='quattro' />";
        break;
    case 5:
        echo "<h1 style='text-align: center'>cinque</h1>";
        echo "<img src='https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Logo_5_Channel.svg/1200px-Logo_5_Channel.svg.png' alt='cinque' />";
        break;

    default:
        echo "Non hai inserito un numero da 1 a 5!";
        break;
}

?>