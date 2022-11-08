<head>
    <title>Numero 4_form - G.C.</title>
</head>
<body>
<?php
if (isset($_POST['saluto'])) {
    // Imposto il cookie del saluto usando i dati del post
    setcookie('saluto', $_POST['saluto'], time() + 600);

    echo "<p>Il tuo messaggio di benvenuto è stato impostato a: " . $_POST['saluto'] . "</p>";
}

if ($_COOKIE['saluto'] != "") {
    echo "<p>Il tuo messaggio di benvenuto è: " . $_COOKIE['saluto'] . "</p>";
} else {
    echo "<p>Non hai impostato un messaggio di benvenuto personalizzato</p>";
}

// Stampo form per impostarlo
echo "<form action='$_SERVER[PHP_SELF]' method='post'>";
echo "<p>Saluto: <input type='text' name='saluto'></p>";
echo "<p><input type='submit' value='Invia'></p>";
echo "<p><input type='reset' value='Cancella'></p>";
echo "</form>";

echo "<p><a href='numero4.php'>Torna alla pagina numero4.php</a></p>";

?>
</body>
