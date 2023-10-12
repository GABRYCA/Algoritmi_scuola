<?php
// Prendo i dati dal form: numero1, numero2 e poi stampo il risultati della somma.
$numero1 = $_POST['numero1'];
$numero2 = $_POST['numero2'];
$risultato = $numero1 + $numero2;
echo "<h1>Il risultato della somma è: " . $risultato . "</h1>";
?>