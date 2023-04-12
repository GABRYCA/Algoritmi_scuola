<?php
session_start();
include "../../../private/connessione.php";


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
    <?php
    include 'common/dipendenze-head.php';
    ?>
    <title>Invia uno spot</title>
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

<div class="container mb-3 border border-light-subtle bg-black bg-opacity-25 rounded-4 pt-2 pb-3 mt-5 shadow-sm">
    <div class="row">
        <p class="h3 text-center pt-3 pb-3">Inserisci i dati del messaggio</p>
        <hr>
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
                        <button type="submit" class="btn btn-success w-100">Invia</button>
                    </div>
                </div>
            </form>
        </div>
    </div>
</div>

<?php
include 'common/footer.php';
include 'common/dipendenze-body.php';
?>
</body>
</html>