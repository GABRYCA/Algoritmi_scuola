<head>
    <title>Numero 2 - G.C.</title>
</head>
<body>
<?php
// Realizzare una pagina PHP che mostri il numero di volte che la pagina è stata visitata
// nell'ultimi 10 minuti.

// Se il cookie non esiste, lo creo
if (!isset($_COOKIE['numero_visite'])) {
    // Imposto il cookie con il valore 1
    setcookie('numero_visite', 1, time() + 600);
    // Invio il messaggio di benvenuto
    echo '<p>Benvenuto nel nostro sito! Questa è la tua prima volta!</p>';
} else {
    // Se il cookie esiste, lo leggo
    $numero_visite = $_COOKIE['numero_visite'];
    // Imposto il cookie con il valore incrementato di 1
    setcookie('numero_visite', $numero_visite + 1, time() + 600);
    // Invio un messaggio di benvenuto
    echo '<p>Benvenuto di nuovo nel nostro sito!</p>';
    echo "<p>Questo è il tuo " . $numero_visite . "° accesso negli ultimi 10 minuti</p>";
}
?>
</body>