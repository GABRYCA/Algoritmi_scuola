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
$stmt = $con->prepare("SELECT testo, colore_bordo, data_invio, luogo, utente FROM messaggio WHERE luogo = ? ORDER BY data_invio DESC");
$stmt->bind_param("i", $id_luogo);
$stmt->execute();
$result = $stmt->get_result();
// Creo array associativo con testo, colore_bordo, data_invio, luogo, utente.
$messaggi = array();
while ($row = $result->fetch_assoc()) {
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
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
            integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer">
    <link rel="icon" type="image/x-icon" href="/favicon.webp">
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
    <div class="row">
        <div class="col">
            <?php if (!empty($messaggi)) {
                $contatore = 0;
                ?>
                <?php foreach ($messaggi as $messaggio) { ?>
                        <div class="row justify-content-center text-center" data-aos="zoom-in" style="color: <?php echo '#' . $messaggio['colore_bordo']; ?>;">
                            <div class="col-10 col-xl-3">
                                <div class="card mt-3 border border-2" style="border-color: <?php echo "#" . $messaggio['colore_bordo'];?> !important;">
                                    <div class="card-body">
                                        <p class="card-text fs-5 border-start border-dark border-opacity-25 border-3 px-3">
                                            <?php echo $messaggio['testo']; ?>
                                        </p>
                                    </div>
                                    <div class="card-footer text-muted fs-6">
                                        <div class="row">
                                            <div class="col">
                                                <?php
                                                if ($contatore == 0){
                                                    echo '<p class="card-text text-start text-danger fw-bold opacity-75">Nuovo!</p>';
                                                }
                                                ?>
                                            </div>
                                            <div class="col">
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