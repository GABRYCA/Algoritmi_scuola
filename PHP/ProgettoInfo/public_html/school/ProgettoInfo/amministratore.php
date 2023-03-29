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
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/ui/1.13.2/jquery-ui.min.js" integrity="sha256-lSjKY0/srUM9BE3dPm+c4fBo1dky2v27Gdjm2uoZaL0=" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer">
    <link rel="icon" type="image/x-icon" href="/favicon.webp">
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
                    <a class="nav-link" aria-current="page" href="profilo.php">Profilo</a>
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


<!-- Footer -->
<div class="container-fluid border-top border-light mt-5">
    <footer class="bg-dark text-center text-white">
        <div class="container p-4">
            <section class="mb-4">
                <a class="btn btn-outline-light btn-floating m-1" href="https://discord.gg/RSp2CSuMny" target="_blank" role="button"><i class="fab fa-discord"></i></a>
                <a class="btn btn-outline-light btn-floating m-1" href="https://www.instagram.com/anonymousgca/" target="_blank" role="button"><i class="fab fa-instagram"></i></a>
                <a class="btn btn-outline-light btn-floating m-1" href="https://open.spotify.com/user/khwbetpa2z3tjr9mdqxoum0rb" target="_blank" role="button"><i class="fab fa-spotify"></i></a>
                <a class="btn btn-outline-light btn-floating m-1" href="https://github.com/GABRYCA/Algoritmi_scuola/tree/master/PHP/ProgettoInfo" target="_blank" role="button"><i class="fab fa-github"></i></a>
            </section>
            <section class="mb-3">
                <p>
                    Il sito è stato creato da G.C. (AnonymousGCA) studente di informatica presso IIS Lorenzo Cobianchi.
                    Copyright &copy; 2023 by AnonymousGCA. All rights reserved.
                </p>
            </section>
        </div>
    </footer>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>