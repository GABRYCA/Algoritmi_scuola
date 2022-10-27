<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>G.C. Ristorante</title>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.js"
            integrity="sha512-zlWWyZq71UMApAjih4WkaRpikgY9Bz1oXIW5G0fED4vk14JjGlQ1UmkGM392jEULP8jbNMiwLWdM8Z87Hu88Fw=="
            crossorigin="anonymous" referrerpolicy="no-referrer"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.css"
          integrity="sha512-wJgJNTBBkLit7ymC6vvzM1EcSWeM9mmOu+1USHaRBbHkm6W9EgM0HY27+UtUaprntaYQJF75rc8gjxllKs5OIQ=="
          crossorigin="anonymous" referrerpolicy="no-referrer"/>
</head>
<body class="bg-dark text-light text-center">

<!-- Form con dati in ingresso, la pagine deve ricevere i dati indicati
e stamparli a video ben incolonnati secondo la tecnica postback -->

<?php

if ($_POST == true){

    // Stampo i dati ricevuti ben incolonnati
    $username = $_POST['username'];
    $password = $_POST['password'];
    $password2 = $_POST['password2'];
    $accetta = $_POST['accetta'];

    if ($accetta == 'on'){
        $accetta = 'Accettato';
    } else {
        $accetta = 'Non accettato';
    }

    if ($password == $password2){
        // Stampo i dati
        echo "<h1>Benvenuto: $username</h1>";
        echo "<h2>La tua password è: $password</h2>";
        echo "<h2>Accetta: $accetta</h2>";
    } else {
        // Stampo i dati e comunico che le password non sono uguali.
        echo "<h1>Password non uguali $username</h1>";
        echo "<h2>La tua password1 è: $password</h2>";
        echo "<h2>La tua password2 è: $password2</h2>";
        echo "<h2>Accetta: $accetta</h2>";
    }

} else {

?>

    <div class="container">
        <div class="row">
            <div class="col">
                <p class="h4">Condizioni di abbonamento</p>
                <br>
                <p class="h5">Per aderire al servizio devi inserire un nome utente, una password ed accettare le condizioni:</p>
            </div>
        </div>
        <div class="row">
            <div class="col">
                <form method="post" action="<?php echo $_SERVER['PHP_SELF']?>">
                    <!-- Username, Password, Ripeti Password -->
                    <div class="row">
                        <div class="col">
                            <label for="username" class="form-label">Username</label>
                            <input type="text" class="form-control" id="username" name="username" required>
                        </div>
                    </div>
                    <br>
                    <div class="row">
                        <div class="col">
                            <label for="password" class="form-label">Password</label>
                            <input type="password" class="form-control" id="password" name="password" required>
                        </div>
                    </div>
                    <br>
                    <div class="row">
                        <div class="col">
                            <label for="password2" class="form-label">Ripeti Password</label>
                            <input type="password" class="form-control" id="password2" name="password2" required>
                        </div>
                    </div>
                    <div class="row">
                        <!-- Textbox con le condizioni, non scrivibile dall'utente, e checkbox sotto per accettare required -->
                        <div class="col">
                            <br>
                            <label for="condizioni" class="form-label">Condizioni</label>
                            <textarea class="form-control" id="condizioni" name="condizioni" rows="3" readonly>Condizioni di abbonamento al servizio tal di tari
                            </textarea>
                        </div>
                    </div>
                    <div class="row mt-5">
                        <!-- Checkbox per accettare le condizioni -->
                        <div class="col-6">
                            <p class="h5">Accetta le condizioni:</p>
                        </div>
                        <div class="col-6">
                            <input class="form-check" type="checkbox" id="accetta" name="accetta" required>
                        </div>
                    </div>
                    <hr class="text-light">
                    <div class="row mt-4">
                        <!-- Button per inviare i dati -->
                        <div class="col">
                            <button type="submit" class="btn btn-primary">Invia</button>
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