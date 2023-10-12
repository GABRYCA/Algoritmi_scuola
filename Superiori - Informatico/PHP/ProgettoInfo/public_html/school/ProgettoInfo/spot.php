<?php
session_start();
include "../../../private/connessione.php";

if (!isset($_SESSION['loggedin'])) {
    header('Location: login.html');
    exit;
}

// Verifico se il GET id è settato.
if (!isset($_GET['id'])) {
    echo "<script>alert('Errore: non hai selezionato nessuno spot.');</script>";
    echo "<script>window.location.href = 'spots.php';</script>";
    exit;
}

// Verifico non sia empty.
if (empty($_GET['id'])) {
    echo "<script>alert('Errore: non hai selezionato nessuno spot.');</script>";
    echo "<script>window.location.href = 'spots.php';</script>";
    exit;
}

$con = connessione();

// Converto in variabile sicura (da unsafe GET).
$id_luogo = $con->real_escape_string($_GET['id']);
$id_utente = $_SESSION['id'];

// Verifico che id_luogo sia un intero.
if (!is_numeric($id_luogo)) {
    echo "<script>alert('Errore: ID non valido.');</script>";
    echo "<script>window.location.href = 'spots.php';</script>";
    exit;
}

// Verifico che l'utente appartenga al luogo.
$stmt = $con->prepare("SELECT * FROM appartenenza WHERE id_luogo = ? AND id_utente = ?");
$stmt->bind_param("ii", $id_luogo, $id_utente);
$stmt->execute();
$result = $stmt->get_result();
if ($result->num_rows == 0) {
    echo "<script>alert('Errore: non sei abilitato a visualizzare questo spot.');</script>";
    echo "<script>window.location.href = 'spots.php';</script>";
    exit;
}
$stmt->close();

// Ottengo il nome del luogo.
$stmt = $con->prepare("SELECT nome FROM luogo WHERE id_luogo = ?");
$stmt->bind_param("i", $id_luogo);
$stmt->execute();
$result = $stmt->get_result();
$row = $result->fetch_assoc();
$nome_luogo = $row['nome'];
$stmt->close();

// Ottengo i messaggi del luogo usando anche l'appartenenza.
$stmt = $con->prepare("SELECT * FROM messaggio WHERE luogo = ? ORDER BY data_invio DESC");
$stmt->bind_param("i", $id_luogo);
$stmt->execute();
$result = $stmt->get_result();
// Creo array associativo con testo, colore_bordo, data_invio, luogo, utente.
$messaggi = array();
while ($row = $result->fetch_assoc()) {
    // Ottengo il numero di valutazioni per ogni messaggio del luogo, inoltre creo un booleano per ogni messaggio che indica se l'utente ($id_utente) ha già votato o meno, e lo aggiungo alla row.

    // Ottengo il numero di valutazioni per ogni messaggio del luogo.
    $stmt2 = $con->prepare("SELECT COUNT(*) AS numero_valutazioni FROM valutazione WHERE id_messaggio = ?");
    $stmt2->bind_param("i", $row['id_messaggio']);
    $stmt2->execute();
    $result2 = $stmt2->get_result();
    $row2 = $result2->fetch_assoc();
    $row['numero_valutazioni'] = $row2['numero_valutazioni'];
    $stmt2->close();

    // Creo un booleano per ogni messaggio che indica se l'utente ($id_utente) ha già votato o meno, e lo aggiungo alla row.
    $stmt2 = $con->prepare("SELECT * FROM valutazione WHERE id_messaggio = ? AND id_utente = ?");
    $stmt2->bind_param("ii", $row['id_messaggio'], $id_utente);
    $stmt2->execute();
    $result2 = $stmt2->get_result();
    if ($result2->num_rows == 0) {
        $row['votato'] = "false";
    } else {
        $row['votato'] = "true";
    }
    $stmt2->close();

    $messaggi[] = $row;
}
$stmt->close();

// Cambia lo stile della data in formato italiano.
function cambiaData($data) {
    // Formato data da ritornare d/m/Y H:i.
    return date("d/m/Y H:i", strtotime($data));
}
?>
<!DOCTYPE html>
<html lang="it" data-bs-theme="dark">
<head>
    <?php
    include 'common/dipendenze-head.php';
    ?>
    <title>Spot del <?php echo $nome_luogo;?></title>
    <style>

        .card {
            transition: 0.3s;
        }

        .card:hover {
            cursor: pointer;
            transform: scale(1.05);
        }
    </style>
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
            <p class="h1 text-center">Spot del <?php echo $nome_luogo;?>:</p>
        </div>
    </div>
</div>

<hr>

<!-- Design alternativo messaggi con solamente testo e footer con la data di invio -->
<div class="container rounded-3 pt-3">
    <div class="row border-end border-start bg-black bg-opacity-10 p-4 pb-5 rounded-3 shadow-sm">
        <div class="col">
            <?php if (!empty($messaggi)) {
                $contatore = 0;
                ?>
                <?php foreach ($messaggi as $messaggio) { ?>
                        <div class="row justify-content-center text-center" data-aos="zoom-in" style="color: <?php echo '#' . $messaggio['colore_bordo']; ?>;">
                            <div class="col-10 col-xl-5">
                                <div class="card mt-3 border border-2" style="border-color: <?php echo "#" . $messaggio['colore_bordo'];?> !important;">
                                    <div class="card-body">
                                        <p class="card-text fs-5 border-start border-dark border-opacity-25 border-3 px-3">
                                            <?php echo $messaggio['testo']; ?>
                                        </p>
                                    </div>
                                    <div class="card-footer text-muted fs-6">
                                        <div class="row">
                                            <div class="col-2">
                                                <div class="row flex-nowrap">
                                                    <!-- Possibilità di votare il messaggio (premere un cuore) e accanto il numero di voti -->
                                                    <div class="col px-0">
                                                        <form action="votaMessaggio.php" method="post">
                                                            <input type="hidden" name="id_messaggio" value="<?php echo $messaggio['id_messaggio']; ?>">
                                                            <input type="hidden" name="votato" value="<?php echo $messaggio['votato']; ?>">
                                                            <button type="submit" class="btn btn-sm btn-outline-danger">
                                                                <?php
                                                                if ($messaggio['votato'] == "true") {
                                                                    echo '<i class="fas fa-heart"></i>';
                                                                } else {
                                                                    echo '<i class="far fa-heart"></i>';
                                                                }
                                                                ?>
                                                            </button>
                                                        </form>
                                                    </div>
                                                    <div class="col px-1 mt-1">
                                                        <p class="card-text text-start opacity-75"><?php echo $messaggio['numero_valutazioni']; ?></p>
                                                    </div>
                                                </div>
                                            </div>
                                            <div class="col-4">
                                                <?php
                                                if ($contatore == 0){
                                                    echo '<p class="card-text text-start text-danger fw-bold opacity-75">Nuovo!</p>';
                                                }
                                                ?>
                                            </div>
                                            <div class="col-5">
                                                <p class="card-text text-end opacity-25"><?php echo cambiaData($messaggio['data_invio']); ?></p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                <?php
                $contatore++;
                } ?>
            <?php } else { ?>
                <div class="card border-danger mb-3">
                    <div class="card-header bg-danger">
                        <p class="h5 text-center">Nessun messaggio inviato</p>
                    </div>
                    <div class="card-body text-danger">
                        <p class="card-text">Non è stato ancora inviato nessun messaggio in questo spot.</p>
                    </div>
                </div>
            <?php } ?>
        </div>
    </div>
    <!-- Row per inviare un messaggio -->
    <div class="row bg-black mt-5 bg-opacity-10 rounded-5 p-4 border border-light-subtle shadow-lg">
        <div class="col">
            <!-- Pulsante che apre inviaMessaggio.php -->
            <a href="inviaMessaggio.php" class="btn btn-outline-primary btn-lg btn-block w-100">Invia un messaggio</a>
        </div>
    </div>
</div>

<?php
include 'common/footer.php';
include 'common/dipendenze-body.php';
?>
</body>
</html>