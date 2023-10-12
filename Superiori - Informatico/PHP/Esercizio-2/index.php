<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Esercizio 2 di G.C.</title>
</head>
<body>
<?php
echo "<br><br> Scrivere una funzione che implementa la somma tra due numeri e la assegna ad una variabile <br><br>";

function somma($a, $b){
    return $a + $b;
}

$num1 = 5;
$num2 = 10;

echo "La somma tra " . $num1 . " e " . $num2 . " è: " . somma(5, 6);

echo "<br><br><hr><br><br>";

echo "Crea una funzione che riceva tre parametri, due numeri e la relativa operazione da effettuare
(+,-,*,/). Se il terzo parametro ha un valore diverso restituisce un messaggio di errore, altrimenti ritorna il risultato,
lavorare con il costrutto switch <br><br>";

function calcolo($a, $b, $operazione){
    switch ($operazione){
        case "+":
            return $a + $b;
        case "-":
            return $a - $b;
        case "*":
            return $a * $b;
        case "/":
            return $a / $b;
        default:
            return "Errore";
    }
}

$num1 = 5;
$num2 = 10;
$operazione = "+";

// Stampo il risultato
echo "Il risultato di " . $num1 . " " . $operazione . " " . $num2 . " è: " . calcolo($num1, $num2, $operazione);


echo "<br><br><hr><br><br>";

echo "Dato un numero N, scrivi una funzione ricorsiva che calcoli la somma di tutti i valori da 1 a N.";

function sommaRicorsiva($n){
    if ($n == 1){
        return 1;
    } else {
        return $n + sommaRicorsiva($n - 1);
    }
}

$num = 10;
echo "La somma di tutti i numeri da 1 a " . $num . " è: " . sommaRicorsiva($num);


echo "<br><br><hr><br><br>";

echo "(COMPITO) Crea una funzione che calcoli il minimo comune multiplo secondo l'argoritmo di Euclide.
Suggerimento: implementare la funzione massimo comune divisore e poi quella per il minimo comune multiplo.";

echo "<br><br>";

function mcd($a, $b){
    if ($b == 0){
        return $a;
    } else {
        return mcd($b, $a % $b);
    }
}

function mcm($a, $b){
    return ($a * $b) / mcd($a, $b);
}

$num1 = 10;
$num2 = 20;

echo "Il minimo comune multiplo tra " . $num1 . " e " . $num2 . " è: " . mcm($num1, $num2);

?>
</body>
</html>