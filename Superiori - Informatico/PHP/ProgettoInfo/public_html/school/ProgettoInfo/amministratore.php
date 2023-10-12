<?php
include "../../../private/connessione.php";
session_start();

if (!isset($_SESSION['loggedin'])) {
    // Messaggio d'errore.
    echo 'Non sei loggato! Devi loggarti per accedere a questa pagina!';
    // Redirect alla pagina di login dopo 2 secondi.
    header("refresh:2;url=login.html");
    exit;
}

$con = connessione();

?>
<!DOCTYPE html>
<html lang="it" data-bs-theme="dark">
<head>
    <?php
    include 'common/dipendenze-head.php';
    ?>
    <title>Area amministratore</title>
</head>
<body class="font-monospace bg-dark text-light">

<!-- Navbar -->
<div class="container-fluid bg-dark pb-3 pt-3 rounded-bottom border-bottom border-light">
    <nav class="navbar navbar-expand-lg navbar-dark">
        <div class="container">
            <a class="navbar-brand" href="profilo.php">AnonymousSpot</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
                <div class="navbar-nav">
                    <a class="nav-link" href="profilo.php">Profilo</a>
                    <a class="nav-link" href="spots.php">Visualizza</a>
                    <a class="nav-link" href="inviaMessaggio.php">Invia</a>
                    <a class="nav-link link-danger" href="logout.php">Logout</a>
                </div>
            </div>
        </div>
    </nav>
</div>

<div class="container-fluid mt-3">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Area amministratore</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <a class="btn btn-light w-100" href="amministratoreIstituti.php">Gestisci Luoghi/Istituti</a>
        </div>
    </div>
    <hr>
    <!-- L'amministratore può vedere i messaggi degli spot e cancellarli -->
    <div class="row">
        <div class="col">
            <p class="h3 text-center">Messaggi degli spot</p>
            <div class="row mt-4">
                <div class="col">
                    <!-- Creo row e col per ogni messaggio, le colonne sono id_messaggio, testo, colore_bordo, data_invio, luogo e utente e una con il pulsante per cancellare il messaggio -->
                    <div class="row border-bottom">
                        <div class="col">
                            <p class="h5">ID messaggio</p>
                        </div>
                        <div class="col">
                            <p class="h5">Testo</p>
                        </div>
                        <div class="col">
                            <p class="h5">Colore bordo</p>
                        </div>
                        <div class="col">
                            <p class="h5">Data invio</p>
                        </div>
                        <div class="col">
                            <p class="h5">Luogo</p>
                        </div>
                        <div class="col">
                            <p class="h5">Utente</p>
                        </div>
                        <div class="col">
                            <p class="h5">Cancella</p>
                        </div>
                    </div>
                    <?php
                    // Prendo tutti i messaggi
                    $query = "SELECT * FROM messaggio";
                    $result = mysqli_query($con, $query);
                    while ($row = mysqli_fetch_array($result)) {

                        // Con l'ID Utente prendo il nome dalla tabella utente.
                        $query2 = "SELECT username FROM utente WHERE id_utente = " . $row['utente'];
                        $result2 = mysqli_query($con, $query2);
                        $row2 = mysqli_fetch_array($result2);
                        // Si preferivo così
                        $row['utente'] = $row2['username'];

                        // Con l'ID Luogo prendo il nome dalla tabella luogo.
                        $query3 = "SELECT nome FROM luogo WHERE id_luogo = " . $row['luogo'];
                        $result3 = mysqli_query($con, $query3);
                        $row3 = mysqli_fetch_array($result3);
                        // Simile a prima
                        $row['luogo'] = $row3['nome'];

                        // Per ogni messaggio creo una row e una col per ogni campo
                        echo "<div class='row pt-4 pb-1 border-bottom'>";
                        echo "<div class='col'>";
                        echo "<p>" . $row['id_messaggio'] . "</p>";
                        echo "</div>";
                        echo "<div class='col'>";
                        echo "<p>" . $row['testo'] . "</p>";
                        echo "</div>";
                        echo "<div class='col'>";
                        echo "<div class='row'>";
                        echo "<div class='col'>";
                        // Stampo il colore del bordo id e anche accanto un quadratino con lo stesso colore
                        echo "<p>" . $row['colore_bordo'] . "</p>";
                        echo "</div>";
                        echo "<div class='col'>";
                        $row['colore_bordo'] = "#" . $row['colore_bordo'];
                        echo "<div style='width: 50px; height: 50px; background-color: " . $row['colore_bordo'] . "'></div>";
                        echo "</div>";
                        echo "</div>";
                        echo "</div>";
                        echo "<div class='col'>";
                        echo "<p>" . $row['data_invio'] . "</p>";
                        echo "</div>";
                        echo "<div class='col'>";
                        echo "<p>" . $row['luogo'] . "</p>";
                        echo "</div>";
                        echo "<div class='col'>";
                        echo "<p>" . $row['utente'] . "</p>";
                        echo "</div>";
                        echo "<div class='col'>";
                        echo "<form action='cancellaMessaggio.php' method='post'>";
                        echo "<input type='hidden' name='id_messaggio' value='" . $row['id_messaggio'] . "'>";
                        echo "<button type='submit' class='btn btn-danger'>Cancella</button>";
                        echo "</form>";
                        echo "</div>";
                        echo "</div>";
                    }
                    ?>
                </div>
            </div>
        </div>
    </div>
</div>

<?php
include 'common/footer.php';
include 'common/dipendenze-body.php'
?>
</body>
</html>