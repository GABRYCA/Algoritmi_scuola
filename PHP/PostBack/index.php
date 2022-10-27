<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Postback 1</title>
</head>
<body>
<?php
    if ($_POST == true && $_POST['nome'] != "" && $_POST['mail'] != "") {
        echo $_POST["nome"] . " " . $_POST["mail"];
    } else {
?>
<br>
<form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
    <input type="text" name="nome" placeholder="Nome">
    <br>
    <br>
    <input type="email" name="mail" placeholder="Mail">
    <br>
    <br>
    <input type="submit" value="Invia">
</form>
<?php
    }
    ?>
</body>
</html>