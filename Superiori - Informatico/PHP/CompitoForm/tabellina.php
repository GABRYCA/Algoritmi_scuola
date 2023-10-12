<?php
// Ottengo tramite post un numero e ci faccio la tabella pitagorica.
$num = $_POST['numero'];
$range = 10;

// Stampo la tabella pitagorica di num.
for ($i = 1; $i <= $range; $i++) {
    echo $num . " * " . $i . " = " . $num * $i . "<br>";
}
?>