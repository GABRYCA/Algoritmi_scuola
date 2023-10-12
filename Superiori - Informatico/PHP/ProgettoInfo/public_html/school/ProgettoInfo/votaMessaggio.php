<?php
session_start();
include "../../../private/connessione.php";

if (!isset($_SESSION['loggedin'])) {
    header("refresh:2;url=spots.php");
    header('Location: login.html');
    exit;
}

if (!isset($_POST['id_messaggio'])) {
    header("refresh:2;url=spots.php");
    exit('Mancano dati! (id_messaggio)');
}

if (empty($_POST['votato'])) {
    header("refresh:2;url=spots.php");
    exit('Mancano dati! (votato)');
}

$conn = connessione();

// Verifico che l'utente in sessione faccia parte del luogo di id_messaggio, in caso contrario comunico l'errore e fermo tutto.
if ($dati = $conn->execute_query("SELECT luogo FROM messaggio WHERE id_messaggio = ?", [$_POST['id_messaggio']])) {
    $result = mysqli_fetch_row($dati);
    $luogo_origine = $result[0];

    // Ottengo i luoghi di appartenenza dell'utente.
    if ($dati = $conn->execute_query("SELECT * FROM appartenenza WHERE id_utente = ? AND id_luogo = ?", [$_SESSION['id'], $luogo_origine])) {
        $result = mysqli_fetch_row($dati);
    } else {
        exit('Non appartieni al luogo del messaggio!');
    }

    // Verifico che result non sia vuoto, in caso contrario comunico l'errore e fermo tutto.
    if (empty($result)) { // Controllo in più.
        exit('Non appartieni al luogo del messaggio!');
    }

    // Usando votato, faccio la query per aggiungere o rimuovere il voto in valutazioni.
    if ($_POST['votato'] == "false"){
        $conn->execute_query("INSERT INTO valutazione (id_utente, id_messaggio) VALUES (?,?)", [$_SESSION['id'], $_POST['id_messaggio']]);
        echo "Voto aggiunto con successo!";
    } else if ($_POST['votato'] == "true") {
        $conn->execute_query("DELETE FROM valutazione WHERE id_utente = ? AND id_messaggio = ?", [$_SESSION['id'], $_POST['id_messaggio']]);
        echo "Voto rimosso con successo!";
    } else {
        exit('Errore interno!');
    }

    // Rimando alla pagina precedente da cui veniva l'utente dopo 2 secondi, comunicando che l'operazione è avvenuta con successo.
    header("refresh:2;url=spot.php?id=" . $luogo_origine);
} else {
    exit('Errore interno!');
}
?>
<head>
    <?php
    include "common/dipendenze-head.php";
    ?>
    <title>Attivazione</title>
</head>
<body class="font-monospace bg-dark text-center text-light mt-5">
<div class="row justify-content-center text-center">
    <div class="col">
        <div class="lds-ellipsis"><div></div><div></div><div></div><div></div></div>
    </div>
</div>
<?php
include "common/dipendenze-body.php";
?>
</body>