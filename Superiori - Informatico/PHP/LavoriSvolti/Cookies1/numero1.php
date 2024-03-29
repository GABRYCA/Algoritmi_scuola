<head>
    <title>Numero 1 - G.C.</title>
</head>
<body>
<?php
// Realizzare una pagina PHP che ci dice la data e l'ora dell'ultimo accesso del visitatore corrente al nostro sito usando i cookies.

// Se il cookie non esiste, lo creo
if (!isset($_COOKIE['ultimo_accesso'])) {
    // Imposto il cookie con la data e l'ora corrente
    setcookie('ultimo_accesso', date('d/m/Y H:i:s'), time() + 3600);
    // Invio il messaggio di benvenuto
    echo '<p>Benvenuto nel nostro sito! Questa è la tua prima volta!</p>';
} else {
    // Se il cookie esiste, lo leggo
    $ultimo_accesso = $_COOKIE['ultimo_accesso'];
    // Imposto il cookie con la data e l'ora corrente aggiornandolo
    setcookie('ultimo_accesso', date('d/m/Y H:i:s'), time() + 3600);
    // Invio un messaggio di benvenuto
    echo '<p>Benvenuto di nuovo nel nostro sito!</p>';
    echo "<p>L'ultimo accesso risale al $ultimo_accesso</p>";
}

?>
</body>
