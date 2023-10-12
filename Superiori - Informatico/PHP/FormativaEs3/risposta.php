<?php
// Prendo i dati del post di cognome, nome, indirizzo, città, telefono.
$cognome = $_POST['cognome'];
$nome = $_POST['nome'];
$indirizzo = $_POST['indirizzo'];
$citta = $_POST['citta'];
$telefono = $_POST['telefono'];

// Stampo i dati in una tabella.
echo "<table border=1>";
echo "<tr><td>Cognome</td><td>$cognome</td></tr>";
echo "<tr><td>Nome</td><td>$nome</td></tr>";
echo "<tr><td>Indirizzo</td><td>$indirizzo</td></tr>";
echo "<tr><td>Città</td><td>$citta</td></tr>";
echo "<tr><td>Telefono</td><td>$telefono</td></tr>";
echo "</table>";

?>
