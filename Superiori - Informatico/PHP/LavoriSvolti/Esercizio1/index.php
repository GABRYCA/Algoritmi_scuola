<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Esercizio 1</title>
</head>
<body>
<?php
echo '<h1>Ciao e benvenuto sul nostro sito!</h1>';

//----------------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------



// Primo esercizio: dato un numero, stamparne il quadrato.
$numero = 5;
echo '<p>Il quadrato di ' . $numero . ' è ' . $numero * $numero . '</p>';


//----------------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------


// Secondo esercizio: Date le coordinate di due punti (x1,y1) (x2,y2) calcolarne la distanza.
$x1 = 1;
$y1 = 1;
$x2 = 2;
$y2 = 2;

$distanza = round(sqrt(pow($x2 - $x1, 2) + pow($y2 - $y1, 2)), 2);
echo '<p>La distanza tra i due punti (' . $x1 . ';' . $y1 . ') (' . $x2 . ';' . $y2 . ') è ' . $distanza . '</p>';


//----------------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------------------


// Terzo esercizio.
// Un'equazione di secondo grado, fare attenzione se A è zero perchè non di secondo grado.
$a = 1;
$b = 2;
$c = 0;
$risultato1 = 0;
$risultato2 = 0;

if ($a == 0){

    // Se l'equazione è di primo grado.
    $risultato1 = -$c / $b;

} else {


    // Se l'equazione è di secondo grado.
    // Calcolo del delta.
    $delta = pow($b, 2) - (4 * $a * $c);

    // Calcolo finale con la formula in base al valore del delta.
    if ($delta > 0) {
        $risultato1 = (-$b + sqrt($delta)) / (2 * $a); // Primo risultato
        $risultato2 = (-$b - sqrt($delta)) / (2 * $a); // Secondo risultato
    } else if ($delta == 0) {
        $risultato1 = -$b / (2 * $a); // Unico risultato
    } else {
        $risultato1 = 'Impossibile calcolare'; // Impossibile calcolare
    }
}

echo '<p>Il risultato dell\'equazione ' . $a . 'x^2 + ' . $b . 'x + ' . $c . ' è ' . $risultato1 . ' e ' . $risultato2 . '</p>';
?>
</body>
</html>