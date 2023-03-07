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
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
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

<div class="container mt-3 mb-3">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Invio messaggio spot:</p>
        </div>
    </div>
</div>

<hr>

<div class="container mb-3">
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
                <div class="mb-3">
                    <label for="messaggio" class="form-label">Messaggio:</label>
                    <textarea class="form-control" name="messaggio" id="messaggio" rows="3"></textarea>
                </div>

                <!-- Colore bordo -->
                <div class="row">
                    <div class="col">
                        <div class="mb-3">
                            <label for="colore_bordo" class="form-label">Colore bordo:</label>
                            <input type="color" class="form-control form-control-color bg-dark border border-dark" id="color" value="#000000" title="Personalizza colore bordo">
                        </div>
                    </div>
                </div>

                <div class="row">
                    <div class="col text-center">
                        <button type="submit" class="btn btn-primary">Invia</button>
                    </div>
                </div>
            </form>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>