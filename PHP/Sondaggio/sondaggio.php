<html>
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
    <title>Sondaggio - G.C.</title>
</head>
<body class="bg-dark text-light font-monospace">

<?php
session_start();

// Verifico se esiste la sessione, nel caso non esista rimando alla pagina di login
if (!isset($_SESSION['username'])) {

    // Avviso che sarà rimandato alla pagina di login
    echo "<h3 class='text-center'>Non sei loggato!<br>Stai per essere reindirizzato alla home entro 3 secondi...</h3>";

    header("refresh: 3; url=index.html");
    return;
} else {
    ?>

    <!-- Sondaggio con domande vero o falso su un argomento che saranno poi salvate quando saranno inviate tramite post -->
    <div class="container">
        <div class="row">
            <div class="col-12">
                <h1 class="text-center mt-3 mb-3">Sondaggio</h1>
            </div>
            <hr>
            <div class="col mb-3">
                <h2 class="text-center">Domande:</h2>
            </div>
        </div>
        <div class="row text-center">
            <div class="col-12">
                <form action="risposte.php" method="post">
                    <div class="row mb-3">
                        <div class="col text-end">
                            <label for="domanda1" class="form-label fw-bold">1. La terra è piatta?</label>
                        </div>
                        <div class="col text-start">
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="domanda1" id="domanda1" value="true">
                                <label class="form-check-label" for="domanda1">Vero</label>
                            </div>
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="domanda1" id="domanda1" value="false">
                                <label class="form-check-label" for="domanda1">Falso</label>
                            </div>
                        </div>
                    </div>
                    <div class="row mb-3">
                        <div class="col text-end">
                            <label for="domanda2" class="form-label fw-bold">2. Il sole è una stella?</label>
                        </div>
                        <div class="col text-start">
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="domanda2" id="domanda2" value="true">
                                <label class="form-check-label" for="domanda2">Vero</label>
                            </div>
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="domanda2" id="domanda2"
                                       value="false">
                                <label class="form-check-label" for="domanda2">Falso</label>
                            </div>
                        </div>
                    </div>
                    <div class="row mb-3">
                        <div class="col text-end">
                            <label for="domanda3" class="form-label fw-bold">3. Il sole è più grande della terra?</label>
                        </div>
                        <div class="col text-start">
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="domanda3" id="domanda3" value="true">
                                <label class="form-check-label" for="domanda3">Vero</label>
                            </div>
                            <div class="form-check form-check-inline">
                                <input class="form-check-input" type="radio" name="domanda3" id="domanda3"
                                       value="false">
                                <label class="form-check-label" for="domanda3">Falso</label>
                            </div>
                        </div>
                    </div>
                    <!-- Submit -->
                    <div class="row">
                        <div class="col-12">
                            <button type="submit" class="btn btn-primary">Invia</button>
                        </div>
                    </div>
                </form>
            </div>
        </div>
    </div>


    <?php
}
?>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-pprn3073KE6tl6bjs2QrFaJGz5/SUsLqktiwsUTF55Jfv3qYSDhgCecCxMW52nD2"
        crossorigin="anonymous"></script>
<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>
</body>
</html>
