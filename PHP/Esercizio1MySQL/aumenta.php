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
    <title>Provvigione</title>
</head>
<body class="font-monospace">
<div class="container">
    <?php

    $DATABASE_HOST = '129.152.17.38';
    $DATABASE_USER = 'authenticator';
    $DATABASE_PASS = 'AuthenticatorPasswordStronk666!';
    $DATABASE_NAME = 'authdatabase';

    $con = mysqli_connect($DATABASE_HOST, $DATABASE_USER, $DATABASE_PASS, $DATABASE_NAME);

    if (mysqli_connect_errno()) {
        die ('Connessione fallita: ' . mysqli_connect_error());
    }

    // Aumento con un UPDATE la provvigione a coloro che sono nella regione Lombardia e hanno fatturato più di 1000 euro
    $query = "UPDATE es1 SET provvigione = provvigione + 2 WHERE regione = 'Lombardia' AND fatturato > 1000";
    $stmt = $con->prepare($query);
    $stmt->execute();

    // Stampo i risultati
    $query = "SELECT * FROM es1 WHERE regione = 'Lombardia' AND fatturato > 1000";
    $stmt = $con->prepare($query);
    $stmt->execute();
    $result = $stmt->get_result();

    echo "<h3 class='mt-3 text-center'>Risultati:</h3><h6 class='text-center'>(Lombardia e con più di 1000 euro di fatturato che sono stati incrementati):</h6><hr>";

    while ($row = mysqli_fetch_assoc($result)) {
        $nome = $row['nome'];
        $cognome = $row['cognome'];
        $fatturato = $row['fatturato'];
        $regione = $row['regione'];
        $provincia = $row['provincia'];
        $provvigione = $row['provvigione'];
        echo "Nome: $nome, Cognome: $cognome, Fatturato: $fatturato, Regione: $regione, Provincia: $provincia, Provvigione: $provvigione <br>";
    }

    ?>
</div>

<div class="container text-center">
    <hr>
    <a href="fatturato.php" class="btn btn-outline-primary">Torna a fatturato.php</a>
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
