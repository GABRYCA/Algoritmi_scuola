<?php
/*
Creare un vettore utente dove salvare il nome e la password di 4 utenti. Si richiede di creare
un’autenticazione “stupida” da parte di un utente.
Se l’utente viene riconosciuto deve essere presentato un messaggio di benvenuto con
un’immagine e il nome dell’utente.
Se l’utente non è riconosciuto deve presentare un messaggio dove si segnala l’insuccesso ed
un link per tornare alla pagina login.
Usare le sessioni.
 */

session_start();

// Creo un array associativo con i dati degli utenti con nome e password.
$utenti = array(
    "Mario" => "1234",
    "Luigi" => "5678",
    "Pippo" => "9876",
    "Pluto" => "4321"
);

// Controllo se l'utente ha già fatto il login.
if (isset($_SESSION["utente"])) {
    // Se l'utente ha già fatto il login, lo saluto.
    echo "<h1>Benvenuto " . $_SESSION["utente"] . "!</h1>";

    // Mostro immagine.
    echo "<br><img src='img/" . $_SESSION["utente"] . ".jpg' alt='Immagine di " . $_SESSION["utente"] . "' />";

    // Tasto logout.
    echo "<br><br><form action='es1.php' method='post'><input type='submit' name='logout' value='Logout'></form>";

    // Se l'utente ha premuto il tasto logout, distruggo la sessione.
    if (isset($_POST["logout"])) {
        session_destroy();
        header("Location: es1.php");
    }
} else {
    // Se l'utente non ha ancora fatto il login, controllo se ha inviato i dati.
    if (isset($_POST["nome"]) && isset($_POST["password"])) {
        // Se l'utente ha inviato i dati, controllo se sono corretti.
        if (isset($utenti[$_POST["nome"]]) && $utenti[$_POST["nome"]] == $_POST["password"]) {
            // Se i dati sono corretti, salvo l'utente in sessione.
            $_SESSION["utente"] = $_POST["nome"];
            // Saluto l'utente.
            echo "<h1>Benvenuto " . $_SESSION["utente"] . "!</h1>";

            // Mostro immagine.
            echo "<br><img src='img/" . $_SESSION["utente"] . ".jpg' alt='Immagine di " . $_SESSION["utente"] . "' />";

            // Tasto logout.
            echo "<br><br><form action='es1.php' method='post'><input type='submit' name='logout' value='Logout'></form>";

            // Se l'utente ha premuto il tasto logout, distruggo la sessione.
            if (isset($_POST["logout"])) {
                session_destroy();
                header("Location: es1.php");
            }
        } else {
            // Se i dati non sono corretti, segnalo l'errore.
            echo "Nome utente o password errati.";

            // Mostro il link per tornare alla pagina di login.
            echo "<br><a href='es1.php'>Torna alla pagina di login</a>";
        }
    } else {
        // Se l'utente non ha ancora fatto il login e non ha inviato i dati, mostro il form.
        ?>
        <form action="es1.php" method="post">
            Nome utente: <input type="text" name="nome"><br>
            Password: <input type="password" name="password"><br>
            <input type="submit" value="Login">
        </form>
        <?php
    }
}

?>
<html>
<head>
<title>Esercizio 1 di G.C.</title>
</head>
<body>
</body>
</html>
