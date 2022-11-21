<?php
// Inserite due date da un form, stabilire:
// - La validità di esse.
// - Se la prima precede la seconda o viceversa.
// - Il numero di giorni trascorsi tra le due date.
// Per l'inserimento separare i tre campi (giorni, mese e anno)

session_start();

if (isset($_POST['submit'])) {
    $giorno1 = $_POST['giorno'];
    $mese1 = $_POST['mese'];
    $anno1 = $_POST['anno'];
    $giorno2 = $_POST['giorno2'];
    $mese2 = $_POST['mese2'];
    $anno2 = $_POST['anno2'];

    // Uso checkdate per verificare la validità delle date
    if (!checkdate($mese1, $giorno1, $anno1) || !checkdate($mese2, $giorno2, $anno2)) {
        // Se le date non sono valide, stampo un messaggio di errore
        echo "Le date inserite non sono valide";
    } else {

        // Uso mktime per creare le date
        $data1 = mktime(0, 0, 0, $mese1, $giorno1, $anno1);
        $data2 = mktime(0, 0, 0, $mese2, $giorno2, $anno2);
        // Controllo se le date sono valide
        if ($data1 && $data2) {
            // Controllo se la prima data è precedente alla seconda
            if ($data1 < $data2) {
                $diff = $data2 - $data1;
                $diff = $diff / 86400;
                echo "La prima data precede la seconda di $diff giorni";
            } else {
                $diff = $data1 - $data2;
                $diff = $diff / 86400;
                echo "La seconda data precede la prima di $diff giorni";
            }
        } else {
            echo "Le date inserite non sono valide";
        }
    }
} else {
    echo "Inserisci le date!";
}

// Conto numero visite in una sessione
if (!isset($_SESSION['visite'])) {
    $_SESSION['visite'] = 1;
} else {
    $_SESSION['visite']++;
}

echo "<br>Numero visite: " . $_SESSION['visite'];


?>
<html lang="it">
<head>
<title>PHP Test</title>
</head>
<body>
<form action="es1.php" method="post">
    <h3>Data 1:</h3>
    <p>Giorno: <input type="text" name="giorno" size="2" maxlength="2" required /></p>
    <p>Mese: <input type="text" name="mese" size="2" maxlength="2" required /></p>
    <p>Anno: <input type="text" name="anno" size="4" maxlength="4" required /></p>
    <h3>Data 2:</h3>
    <p>Giorno: <input type="text" name="giorno2" size="2" maxlength="2" required /></p>
    <p>Mese: <input type="text" name="mese2" size="2" maxlength="2" required /></p>
    <p>Anno: <input type="text" name="anno2" size="4" maxlength="4" required /></p>
    <p><input type="submit" name="submit" value="Invia" /></p>
</form>
<h1 style="text-align: center">Esercizio di G.C. 5BITI</h1>
</body>
</html>
