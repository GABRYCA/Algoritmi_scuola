<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
            integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer">
    <title>Query</title>
</head>
<body class="font-monospace">

    <h1 class="text-center mt-3">Inserire dati:</h1>

    <div class="container">
    <form action="fatturato.php" method="post">
        <div class="form-group">
            <label for="minimo">Minimo:</label>
            <input type="number" class="form-control" id="minimo" name="minimo">
        </div>
        <div class="form-group">
            <label for="massimo">Massimo:</label>
            <input type="number" class="form-control" id="massimo" name="massimo">
        </div>
        <input class="btn btn-primary mt-1 w-100" type="submit" value="Invia">
    </form>
    </div>

    <!-- I risultati saranno stampati qui -->

    <?php

    $DATABASE_HOST = '129.152.17.38';
    $DATABASE_USER = 'authenticator';
    $DATABASE_PASS = 'AuthenticatorPasswordStronk666!';
    $DATABASE_NAME = 'authdatabase';

    $con = mysqli_connect($DATABASE_HOST, $DATABASE_USER, $DATABASE_PASS, $DATABASE_NAME);

    if (mysqli_connect_errno()) {
        die ('Connessione fallita: ' . mysqli_connect_error());
    }

    if (isset($_POST['minimo']) && isset($_POST['massimo'])) {

        if (empty($_POST['minimo']) || empty($_POST['massimo'])) {
            die ('Inserisci un valore');
        }

        $minimo = $_POST['minimo'];
        $massimo = $_POST['massimo'];
        $query = "SELECT * FROM es1 WHERE fatturato BETWEEN ? AND ?";
        $stmt = $con->prepare($query);
        $stmt->bind_param('ii', $minimo, $massimo);
        $stmt->execute();
        $result = $stmt->get_result();

        if (mysqli_num_rows($result) == 0) {
            echo "<h3 class='text-center text-danger'>Nessun risultato</h3>";
        } else {

            echo "<hr><h3 class='text-center'>Risultati tra $minimo - $massimo:</h3><hr><br>";

            while ($row = mysqli_fetch_assoc($result)) {
                $nome = $row['nome'];
                $cognome = $row['cognome'];
                $fatturato = $row['fatturato'];
                $regione = $row['regione'];
                $provincia = $row['provincia'];
                $provvigione = $row['provvigione'];
                echo "<p class='h5 text-center'>Nome: $nome, Cognome: $cognome, Fatturato: $fatturato, Regione: $regione, Provincia: $provincia, Provvigione: $provvigione</h5><br>";
            }
        }
    } else {
        echo "<h3 class='text-center text-danger'>Inserisci un valore</h3>";
    }

    $con->close();
    ?>

    <hr>

<!-- Aumenta provvigione (pulsante per un'altra pagina) -->
<h4 class="text-center mt-4">Aumenta Provvigione a chi ha più di 1000 euro di fatturato (di nuovo):<h4>
    <div class="container">
        <form action="aumenta.php" method="post">
            <input class="btn btn-success mt-1 w-100" type="submit" value="Invia">
        </form>
    </div>
</body>
</html>
