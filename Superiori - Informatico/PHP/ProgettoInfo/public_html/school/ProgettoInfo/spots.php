<?php
session_start();
include "../../../private/connessione.php";

if (!isset($_SESSION['loggedin'])) {
    header('Location: login.html');
    exit;
}

// Ottengo le appartenenze dell'utente per i luoghi e creo un array id_luogo => nome.
$id_utente = $_SESSION['id'];
$luoghi = array();
$con = connessione();
$stmt = $con->prepare("SELECT a.id_luogo,l.nome FROM appartenenza AS a JOIN luogo l on a.id_luogo = l.id_luogo WHERE id_utente = ?");
$stmt->bind_param("i", $id_utente);
$stmt->execute();
$result = $stmt->get_result();
while ($row = $result->fetch_assoc()) {
    $luoghi[$row['id_luogo']] = $row['nome'];
}
$stmt->close();
?>
<!DOCTYPE html>
<html lang="it" data-bs-theme="dark">
<head>
    <?php
    include 'common/dipendenze-head.php';
    ?>
    <title>Spots</title>
</head>
<body class="font-monospace text-light bg-dark">

<!-- Navbar -->
<div class="container-fluid bg-dark pb-3 pt-3 mb-4 rounded-bottom border-bottom border-light">
    <nav class="navbar navbar-expand-lg navbar-dark">
        <div class="container">
            <a class="navbar-brand" href="profilo.php">AnonymousSpot</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
                <div class="navbar-nav">
                    <a class="nav-link" href="profilo.php">Profilo</a>
                    <a class="nav-link active" href="spots.php">Visualizza</a>
                    <a class="nav-link" href="inviaMessaggio.php">Invia</a>
                    <a class="nav-link link-danger" href="logout.php">Logout</a>
                </div>
            </div>
        </div>
    </nav>
</div>

<div class="container mb-3">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Spots:</p>
        </div>
    </div>
</div>

<hr>

<div class="container">
    <!-- Lista di luoghi cliccabili che aprono la pagina corrispondente -->
    <div class="row justify-content-center text-center">
        <?php
        foreach ($luoghi as $id => $nome) {
            echo "<div class='col-12 col-md-6 col-lg-4 col-xl-3 mt-3'>
                    <a href='spot.php?id=$id' class='btn btn-outline-info btn-lg btn-block'>$nome</a>
                  </div>";
        }
        ?>
    </div>
</div>

<?php
include 'common/footer.php';
include 'common/dipendenze-body.php';
?>
</body>
</html>