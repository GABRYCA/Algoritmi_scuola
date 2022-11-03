<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Esercizio 5 di G.C.</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
</head>
<body class="bg-dark text-light text-center">
<br>
<?php

if ($_POST == true && $_POST['numero'] != null){

    $max = $_POST['numero'];
    $min = 0;
    $nNum = 20;

    // Genero un vettore con 20 numeri casuali tra min e max
    $vettore = array();
    for ($i = 0; $i < $nNum; $i++){
        $vettore[$i] = rand($min, $max);
    }

    // Faccio la somma dei numeri in posizione pari e il prodotto dei numeri dispari
    // Contenuti nel vettore
    $somma = 0;
    $prodotto = 1;
    for ($i = 0; $i < $nNum; $i++){
        if ($i % 2 == 0){
            $somma += $vettore[$i];
        }
        // Controllo se il numero è disparo, se lo è lo sommo
        if ($vettore[$i] % 2 != 0){
            $prodotto *= $vettore[$i];
        }
    }

    // Stampo il vettore
    echo "<p class='h4'>Vettore: ";
    for ($i = 0; $i < $nNum; $i++){
        echo $vettore[$i] . " ";
    }
    echo "</p>";

    // Stampo la somma e il prodotto
    echo "<p class='h4'>Somma: " . $somma . "</p>";
    echo "<p class='h4'>Prodotto: " . $prodotto . "</p>";
} else {
?>

    <!-- Form che chiede all'utente di inserire un numero -->
    <form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
        <label for="numero">Inserisci un numero</label>
        <input type="number" class="form-text" name="numero" min="0" id="numero">
        <br>
        <br>
        <input type="submit" class="btn btn-primary" value="Invia">
    </form>

<?php
}
?>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
</body>
</html>