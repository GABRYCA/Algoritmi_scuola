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

$conn = connessione();
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
    <title>Area Amministratore - Istituti</title>
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

<!-- Contenuto -->
<div class="container-fluid mt-3">
    <div class="row">
        <div class="col">
            <p class="h1 text-center">Gestisci istituti/Luoghi:</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <!-- Torna all'area amministratori -->
            <a href="amministratore.php" class="btn btn-outline-warning w-100">Torna indietro</a>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <p class="h2 text-center mb-3">Aggiungi istituto:</p>
            <!-- Form per aggiungere un istituto/luogo, che chiede nome, città, dominio email (opzionale), link sito ufficiale opzionale, tipo_luogo da una select con opzioni Istituto o Luogo -->
            <form action="azioni/aggiungiIstituto.php" method="post">
                <div class="row">
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="text" class="form-control" id="nome" name="nome" placeholder="Nome" required>
                            <label for="nome">Nome</label>
                        </div>
                    </div>
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="text" class="form-control" id="citta" name="citta" placeholder="Città" required>
                            <label for="citta">Città</label>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="text" class="form-control" id="email" name="dominio_email_istituto" placeholder="Dominio Email (es. edu.cobianchi.it)" required>
                            <label for="email">Dominio Email</label>
                        </div>
                    </div>
                    <div class="col">
                        <div class="form-floating mb-3">
                            <input type="url" class="form-control" id="sito" name="sito" placeholder="Sito">
                            <label for="sito">Sito</label>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <div class="form-floating mb-3">
                            <select class="form-select" id="tipo_luogo" name="tipo_luogo" aria-label="Floating label select example" required>
                                <option value="Istituto">Istituto</option>
                                <option value="Luogo">Luogo</option>
                            </select>
                            <label for="tipo_luogo">Tipo luogo</label>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col">
                        <button type="submit" class="btn btn-primary w-100">Aggiungi</button>
                    </div>
                </div>
            </form>
        </div>
    </div>
    <hr>
    <!-- Tabella con gli istituti/luoghi e pulsante per rimuoverli -->
    <div class="row mt-5">
        <div class="col">
            <p class="h2 text-center mb-3">Rimuovi istituto:</p>
            <table class="table table-dark table-striped table-hover border-top">
                <thead>
                <tr>
                    <th scope="col">Nome</th>
                    <th scope="col">Città</th>
                    <th scope="col">Dominio Email</th>
                    <th scope="col">Sito</th>
                    <th scope="col">Tipo luogo</th>
                    <th scope="col">Rimuovi</th>
                </tr>
                </thead>
                <tbody>
                <?php
                //Query per prendere tutti gli istituti/luoghi
                $query = "SELECT * FROM luogo";
                $result = mysqli_query($conn, $query);
                //Ciclo per stampare i dati in una tabella
                while ($row = mysqli_fetch_assoc($result)) {
                    echo "<tr>";
                    echo "<td>" . $row['nome'] . "</td>";
                    echo "<td>" . $row['città'] . "</td>";
                    echo "<td>" . $row['dominio_email_istituto'] . "</td>";
                    echo "<td>" . $row['sito_ufficiale'] . "</td>";
                    echo "<td>" . $row['tipo_luogo'] . "</td>";
                    echo "<td><a href='azioni/rimuoviIstituto.php?id=" . $row['id_luogo'] . "' class='btn btn-danger'>Rimuovi</a></td>";
                    echo "</tr>";
                }
                ?>
                </tbody>
            </table>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
