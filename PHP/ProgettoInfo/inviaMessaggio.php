<?php
session_start();
include "connessione.php";


if (!isset($_SESSION['loggedin'])) {
    header('Location: login.html');
    exit;
}

// Ottengo le appartenenze dell'utente per i luoghi.
$id_utente = $_SESSION['id'];
$luoghi = array();
$con = connessione();
$stmt = $con->prepare("SELECT a.id_luogo,l.nome FROM appartenenza AS a JOIN luogo l on a.id_luogo = l.id_luogo WHERE id_utente = ?");
$stmt->bind_param("i", $id_utente);
$stmt->execute();
$result = $stmt->get_result();
// Creo array associativo id_luogo => nome.
while ($row = $result->fetch_assoc()) {
    $luoghi[$row['id_luogo']] = $row['nome'];
}
$stmt->close();

// Se non c'è almeno un luogo nel vettore luoghi, lo comunico all'utente.
if (count($luoghi) == 0) {
    echo "<script>alert('Non sei abilitato a inviare messaggi in nessun luogo. Aggiungi la tua email d\'istituto nel profilo.');</script>";
    echo "<script>window.location.href = 'profilo.php';</script>";
    exit;
}

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
    <title>Invia uno spot</title>
</head>
<body class="font-monospace text-light bg-dark">

<!-- Navbar con Profilo, Spots e Logout -->
<div class="container-fluid bg-black bg-opacity-10 mb-4 pb-3 mt-3 border-bottom border-light">
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="profilo.php">AnonymousSpot</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
                <div class="navbar-nav">
                    <a class="nav-link" aria-current="page" href="profilo.php">Profilo</a>
                    <a class="nav-link" href="spots.php">Visualizza</a>
                    <a class="nav-link active" href="inviaMessaggio.php">Invia</a>
                    <a class="nav-link link-danger" href="logout.php">Logout</a>
                </div>
            </div>
        </div>
    </nav>
</div>

<div class="container mb-3">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Invio messaggio spot:</p>
        </div>
    </div>
</div>

<hr>

<div class="container mb-3 border border-light bg-light bg-opacity-10 rounded-3 pt-2 pb-3 mt-5">
    <div class="row">
        <div class="col">
            <!-- Form per inviare il messaggio.
            Ha i seguenti campi:
            - Luogo: selezione del luogo in cui inviare il messaggio.
            - Messaggio: testo del messaggio.
            - colore_bordo (id colore html formato: #000000).
            -->
            <form action="elaboraMessaggio.php" method="post">

                <!-- Selezione luogo -->
                <div class="mb-3">
                    <label for="luogo" class="form-label">Luogo:</label>
                    <select class="form-select" name="luogo" id="luogo">
                        <?php
                        foreach ($luoghi as $id_luogo => $nome) {
                            echo "<option value='$id_luogo'>$nome</option>";
                        }
                        ?>
                    </select>
                </div>

                <!-- Testo messaggio -->
                <div class="mb-1">
                    <label for="messaggio" class="form-label">Messaggio:</label>
                    <textarea class="form-control" name="messaggio" id="messaggio" rows="3" placeholder="Scrivere il testo spot"></textarea>
                </div>

                <hr>

                <!-- Colore bordo -->
                <div class="row text-center">
                    <div class="col">
                        <label for="colore_bordo" class="form-label">Colore Personalizzato:</label>
                        <input type="color" class="form-control form-control-color bg-black bg-opacity-25 border border-light border-opacity-25 w-100" id="color" name="colore" value="#3399ff" title="Personalizza colore bordo">
                    </div>
                </div>

                <hr>

                <div class="row">
                    <div class="col text-center">
                        <button type="submit" class="btn btn-primary w-100">Invia</button>
                    </div>
                </div>
            </form>
        </div>
    </div>
</div>

<!-- TODO Rifare il form con ajax e modificare elaboraMessaggio.php per esso. -->

<!-- Footer -->
<div class="container-fluid border-top border-light mt-5">
    <footer class="bg-dark text-center text-white">
        <!-- Grid container -->
        <div class="container p-4">
            <!-- Section: Social media -->
            <section class="mb-4">
                <!-- Discord -->
                <a class="btn btn-outline-light btn-floating m-1" href="https://discord.gg/RSp2CSuMny" target="_blank" role="button"><i class="fab fa-discord"></i></a>

                <!-- Instagram -->
                <a class="btn btn-outline-light btn-floating m-1" href="https://www.instagram.com/anonymousgca/" target="_blank" role="button"><i class="fab fa-instagram"></i></a>

                <!-- Spotify -->
                <a class="btn btn-outline-light btn-floating m-1" href="https://open.spotify.com/user/khwbetpa2z3tjr9mdqxoum0rb" target="_blank" role="button"><i class="fab fa-spotify"></i></a>

                <!-- Github -->
                <a class="btn btn-outline-light btn-floating m-1" href="https://github.com/GABRYCA/Algoritmi_scuola/tree/master/PHP/ProgettoInfo" target="_blank" role="button"><i class="fab fa-github"></i></a>
            </section>

            <!-- Section: Text -->
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