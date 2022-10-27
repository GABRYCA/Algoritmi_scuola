<?php
// In post ho num1 e num2 e il tipo di operazione "operazione".
// In base all'operazione devo fare il calcolo e stampare il risultato.

$num1 = $_POST['num1'];
$num2 = $_POST['num2'];
$operazione = $_POST['operazione'];
$risultato = 0;

// In base all'operazione devo fare il calcolo e stampare il risultato.
switch ($operazione) {
    case 'somma':
        $risultato = $num1 + $num2;
        break;
    case 'sottrazione':
        $risultato = $num1 - $num2;
        break;
    case 'moltiplicazione':
        $risultato = $num1 * $num2;
        break;
    case 'divisione':
        $risultato = $num1 / $num2;
        break;
    case "potenza":
        $risultato = pow($num1, $num2);
        break;
}

// Il risultato dell'operazione nome è risultato.
echo "Il risultato dell'operazione " . $operazione . " è: " . $risultato;
?>