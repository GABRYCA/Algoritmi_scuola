<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Esercizio 4 Formativa di GC.</title>
</head>
<body>
<!-- Costruire una pagina web che, in modo casuale, mostra un messaggio pubblicitario
rappresentato da un'immagine oppure da una scritta casuale visualizzando parti diverse di codice HTML
in base ad una certa condizione. -->

<form>
    <input type="submit" value="Refresh">
</form>
<br>

<?php
    $random = rand(0,1);
    if ($random == 0) {
        $random = rand(0,4);

        switch ($random){
            case 0:
                echo "<img src='https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_272x92dp.png' alt='Google Logo'>";
                break;
            case 1:
                echo "<img src='https://i.pinimg.com/474x/1d/5a/2d/1d5a2d159ec764335392d0b0d0878eb8--germano-funny-stuff.jpg' alt='GERMANOOOOOOOOOOOOOOOOOOOOOOOOO'>";
                break;
            case 2:
                echo "<img src='https://i.pinimg.com/originals/e2/27/d1/e227d1d7340c9a68b4cdbe07107ca6c5.jpg' alt='Shrek e le cipolle'>";
                break;
            case 3:
                echo "<img src='https://www.brand-news.it/wp-content/uploads/2018/10/spot-nutella.jpg' alt='Nutella'>";
                break;
            case 4:
                echo "<img src='https://media.tenor.com/ghohHsISwasAAAAd/dark-meme.gif' alt='Trollge'>";
                break;
        }
    } else {

        $random = rand(0,4);

        switch ($random){
            case 0:
                echo "<h1>Google</h1>";
                break;
            case 1:
                echo "<h1>GERMANOOOOOOOOOOOOOOOOOOOOOOOOO</h1>";
                break;
            case 2:
                echo "<h1>Shrek e le cipolle</h1>";
                break;
            case 3:
                echo "<h1>Nutella</h1>";
                break;
            case 4:
                echo "<h1>Trollge</h1>";
                break;
        }
    }
?>
</body>
</html>