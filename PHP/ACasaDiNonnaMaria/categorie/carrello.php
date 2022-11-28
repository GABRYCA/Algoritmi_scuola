<?php
// Aggiunge un prodotto al carrello e modifica la quantità di un prodotto già presente nel carrello.
// Utilizza il vettore prodotti salvato nelle session per i prezzi e correttezza dei dati.
// Il vettore prodotti nella session ha i prodotti divisi per categoria.
// Il post dei form invia anche la categoria del prodotto oltre al nome

session_start();

// Controllo se esiste già la sessione e il login con un username
if (isset($_SESSION['username'])) {
    // Controllo se esiste già il carrello nella sessione
    if (isset($_SESSION['carrello'])) {
        // Se esiste già il carrello nella sessione, allora controllo se è stato inviato un form
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            // Se è stato inviato un form, allora controllo se è stato inviato un prodotto
            if (isset($_POST['prodotto'])) {
                // Se è stato inviato un prodotto, allora controllo se è stato inviato anche la categoria
                if (isset($_POST['categoria'])) {
                    // Se è stato inviato anche la categoria, allora controllo se il prodotto è presente nel carrello
                    if (isset($_SESSION['carrello'][$_POST['categoria']][$_POST['prodotto']])) {
                        // Se il prodotto è presente nel carrello, allora controllo se è stato inviato anche la quantità
                        if (isset($_POST['quantita'])) {
                            // Se è stato inviato anche la quantità, allora controllo se la quantità è un numero
                            if (is_numeric($_POST['quantita'])) {
                                // Se la quantità è un numero, allora controllo se la quantità è maggiore di 0
                                if ($_POST['quantita'] > 0) {
                                    // Se la quantità è maggiore di 0, allora controllo se la quantità è minore o uguale a 10
                                    if ($_POST['quantita'] <= 10) {
                                        // Se la quantità è minore o uguale a 10, allora aggiorno la quantità del prodotto nel carrello
                                        $_SESSION['carrello'][$_POST['categoria']][$_POST['prodotto']] = $_POST['quantita'];
                                        echo "<div class='alert alert-success' role='alert'>Prodotto modificato nel carrello!</div>";
                                    } else {
                                        // Se la quantità è maggiore di 10, allora stampo un messaggio di errore
                                        echo "<div class='alert alert-danger' role='alert'>La quantità deve essere minore o uguale a 10!</div>";
                                    }
                                } else {
                                    // Se la quantità è minore o uguale a 0,
                                    // allora controllo se il prodotto è presente nel carrello e lo rimuovo
                                    if (isset($_SESSION['carrello'][$_POST['categoria']][$_POST['prodotto']])) {
                                        unset($_SESSION['carrello'][$_POST['categoria']][$_POST['prodotto']]);
                                    }
                                }
                            } else {
                                // Se la quantità non è un numero, allora stampo un messaggio di errore
                                echo "<div class='alert alert-danger' role='alert'>La quantità deve essere un numero!</div>";
                            }
                        } else {
                            // Se non è stato inviato la quantità, allora stampo un messaggio di errore
                            echo "<div class='alert alert-danger' role='alert'>La quantità non è stata inviata!</div>";
                        }
                    } else {
                        // Se il prodotto non è presente nel carrello, allora controllo se è stato inviato anche la quantità
                        if (isset($_POST['quantita'])) {
                            // Se è stato inviato anche la quantità, allora controllo se la quantità è un numero
                            if (is_numeric($_POST['quantita'])) {
                                // Se la quantità è un numero, allora controllo se la quantità è maggiore di 0
                                if ($_POST['quantita'] > 0) {
                                    // Se la quantità è maggiore di 0, allora controllo se la quantità è minore o uguale a 10
                                    if ($_POST['quantita'] <= 10) {
                                        // Se la quantità è minore o uguale a 10, allora aggiungo il prodotto al carrello
                                        $_SESSION['carrello'][$_POST['categoria']][$_POST['prodotto']] = $_POST['quantita'];
                                        // Invio un messaggio di successo e avviso che si sta per tornare indietro alla pagina precedente.
                                        echo "<div class='alert alert-success' role='alert'>Prodotto aggiunto al carrello!</div>";
                                    } else {
                                        // Se la quantità è maggiore di 10, allora stampo un messaggio di errore
                                        echo "<div class='alert alert-danger' role='alert'>La quantità deve essere minore o uguale a 10!</div>";
                                    }
                                } else {
                                    // Se la quantità è minore o uguale a 0, allora stampo un messaggio di errore
                                    echo "<div class='alert alert-danger' role='alert'>La quantità deve essere maggiore di 0!</div>";
                                }
                            } else {
                                // Se la quantità non è un numero, allora stampo un messaggio di errore
                                echo "<div class='alert alert-danger' role='alert'>La quantità deve essere un numero!</div>";
                            }
                        } else {
                            // Se non è stato inviato la quantità, allora stampo un messaggio di errore
                            echo "<div class='alert alert-danger' role='alert'>La quantità non è stata inviata!</div>";
                        }
                    }
                } else {
                    // Se non è stata inviata la categoria, allora stampo un messaggio di errore
                    echo "<div class='alert alert-danger' role='alert'>La categoria non è stata inviata!</div>";
                }
            } else {
                // Se non è stato inviato il prodotto, allora stampo un messaggio di errore
                echo "<div class='alert alert-danger' role='alert'>Il prodotto non è stato inviato!</div>";
            }
        }
    }
}

// Dopo alcuni secondi rimando l'utente indietro alla pagina precedente
header("Refresh: 3; url=" . $_SERVER['HTTP_REFERER']);

?>
