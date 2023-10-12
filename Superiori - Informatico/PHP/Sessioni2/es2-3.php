<?php
/*
 dove
viene visualizzato il nome, il cognome dell’utente e lo sport preferito (con un’immagine che lo
rappresenta).
 */

session_start();

// Controllo se l'utente ha già fatto il login.
if (isset($_SESSION["utente"])) {

    $_SESSION["sport"] = $_POST["sport"];
    // Visualizzo nome, cognome e immagine sport.
    echo "<h1>Benvenuto " . $_SESSION["utente"] . "!</h1>";
    echo "<br><img src='img/sport/" . $_SESSION["sport"] . ".jpg' alt='Immagine di " . $_SESSION["sport"] . "' />";
    echo "<br><br>Nome: " . $_SESSION["nome"];
    echo "<br>Cognome: " . $_SESSION["cognome"];

    echo "<br>Sport: " . $_SESSION["sport"];


    // Tasto logout.
    echo "<br><br><form action='es2.html' method='post'><input type='submit' name='logout' value='Logout'></form>";

    // Se l'utente ha premuto il tasto logout, distruggo la sessione.
    if (isset($_POST["logout"])) {
        session_destroy();
        header("Location: es2.html");
    }
} else {
    // Se l'utente non ha ancora fatto il login, lo rimando alla pagina es2.html.
    header("Location: es2.html");
}
?>