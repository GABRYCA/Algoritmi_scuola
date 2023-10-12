<?php
/*
Costruire una pagina web la quale, dopo aver richiesto nome, cognome e sesso di un utente,
richiami una seconda pagina in cui viene visualizzato un messaggio di saluto per l’utente
inserito, un menù a tendina con vari sport e un pulsante che richiama una terza pagina, dove
viene visualizzato il nome, il cognome dell’utente e lo sport preferito (con un’immagine che lo
rappresenta).
 */
session_start();

// Controllo se l'utente ha già fatto il login.
if (isset($_SESSION["utente"])) {
    // Se l'utente ha già fatto il login, lo saluto.
    echo "<h1>Benvenuto " . $_SESSION["utente"] . "!</h1>";

    // Mostro immagine.
    echo "<br><img src='img/" . $_SESSION["utente"] . ".jpg' alt='Immagine di " . $_SESSION["utente"] . "' />";

    // Tasto logout.
    echo "<br><br><form action='es2.html' method='post'><input type='submit' name='logout' value='Logout'></form>";

    // Se l'utente ha premuto il tasto logout, distruggo la sessione.
    if (isset($_POST["logout"])) {
        session_destroy();
        header("Location: es2.html");
    }
} else {
    // Se l'utente non ha ancora fatto il login, controllo se ha inviato i dati.
    if (isset($_POST["nome"]) && isset($_POST["cognome"]) && isset($_POST["sesso"])) {
        // Se l'utente ha inviato i dati, salvo l'utente in sessione.
        $_SESSION["utente"] = $_POST["nome"];
        // Salvo il nome in sessione.
        $_SESSION["nome"] = $_POST["nome"];
        // Salvo il cognome in sessione.
        $_SESSION["cognome"] = $_POST["cognome"];
        // Salvo il sesso in sessione.
        $_SESSION["sesso"] = $_POST["sesso"];
        // Saluto l'utente.
        echo "<h1>Benvenuto " . $_SESSION["utente"] . "!</h1>";

        // Menù a tendina con sports.
        echo "<br><br><form action='es2-3.php' method='post'>
            <select name='sport'>
                <option value='calcio'>Calcio</option>
                <option value='basket'>Basket</option>
                <option value='tennis'>Tennis</option>
                <option value='rugby'>Rugby</option>
                <option value='pallavolo'>Pallavolo</option>
                <option value='nuoto'>Nuoto</option>
                <option value='atletica'>Atletica</option>
                <option value='ginnastica'>Ginnastica</option>
                <option value='pallamano'>Pallamano</option>
                <option value='volley'>Volley</option>
            </select>
            <input type='submit' value='Invia'>
        </form>";

        // Tasto logout.
        echo "<br><br><form action='es2.html' method='post'><input type='submit' name='logout' value='Logout'></form>";

        // Se l'utente ha premuto il tasto logout, distruggo la sessione.
        if (isset($_POST["logout"])) {
            session_destroy();
            header("Location: es2.html");
        }
    } else {
        // Se l'utente non ha ancora fatto il login, lo invito a farlo.
        echo "Devi prima effettuare il login.";
        echo "<br><a href='es2.html'>Torna alla pagina di login</a>";
    }
}
?>