<head>
    <title>Numero 4 - G.C.</title>
    <!--
    Si vuole creare un cookie che saluti un visitatore frequente di una pagina web.
    Tipicamente, il contenuto di tale cookie sarà un saluto personalizzato relativo all’utente
    connesso.
    -->
</head>
<body>
<?php
// Se il cookie non esiste, lo creo
if (!isset($_COOKIE['saluto'])) {
    // Invio il messaggio di benvenuto
    echo '<p>Benvenuto nel nostro sito! Questa è la tua prima volta!</p>';
    // Opzione per impostare il messaggio di benvenuto personalizzato tramite pagina form
    echo "<p>Per impostare il tuo messaggio di benvenuto personalizzato, <a href='numero4_form.php'>clicca qui</a></p>";
} else {
    // Se il cookie esiste, lo leggo
    $saluto = $_COOKIE['saluto'];
    // Imposto il cookie.
    setcookie('saluto', $saluto, time() + 600);
    // Invio un messaggio di benvenuto
    echo '<p>Benvenuto di nuovo nel nostro sito!</p>';
    echo "<p>$saluto</p>";
    // Opzione per modificare o cancellare il messaggio di benvenuto tramite pagina form
    echo "<p>Per modificare o cancellare il tuo messaggio di benvenuto personalizzato, <a href='numero4_form.php'>clicca qui</a></p>";
}
?>
</body>