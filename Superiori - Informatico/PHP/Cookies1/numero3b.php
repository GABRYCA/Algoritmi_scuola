<head>
    <title>Numero 3b - G.C.</title>
</head>
<body>
<?php

if (isset($_POST['nome']) && isset($_POST['cognome'])){
    // Imposto il cookie del nome e cognome usando i dati del post
    setcookie('nome', $_POST['nome'], time() + 3600);
    setcookie('cognome', $_POST['cognome'], time() + 3600);

    // Stampo il nome e cognome
    echo "<p>Ciao " . $_POST['nome'] . " " . $_POST['cognome'] . "</p>";
}

// Prendo i dati del form del post select di regione e provincia, stampandoli a video
if (isset($_POST['regione']) && isset($_POST['provincia'])){
    echo "<p>La regione selezionata è: " . $_POST['regione'] . "</p>";
    echo "<p>La provincia selezionata è: " . $_POST['provincia'] . "</p>";
}

?>

<!-- Tasto per andare alla pagina numero3.php -->
<p><a href="numero3.php">Torna alla pagina numero3.php</a></p>
</body>