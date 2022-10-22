<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Postback2</title>
</head>
<body>
<!-- Con la tecnica del postback, creare un form html dove si richieda all'utente i seguenti dati:
- Nome Cognome
- Stato civile (Coniugato o libero)
- Argomenti di interesse (Tecnologia, motori, viaggi)
- Dove si è venuti a conoscenza del sito.

La pagina PHP deve mostrare i dati raccolti.
-->
<?php
if ($_POST == true){
    foreach ($_POST as $key => $value){
        echo $key . " : " . $value . "<br>";
    }
    } else {
?>

<form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
    <input type="text" name="nome" placeholder="Nome">
    <input type="text" name="cognome" placeholder="Cognome">
    <br>
    <br>
    <input type="radio" name="stato" value="Coniugato">Coniugato
    <input type="radio" name="stato" value="Libero">Libero
    <br>
    <br>
    <input type="checkbox" name="argomenti-1" value="Tecnologia">Tecnologia
    <input type="checkbox" name="argomenti-2" value="Motori">Motori
    <input type="checkbox" name="argomenti-3" value="Viaggi">Viaggi
    <br><br>
    <input type="text" name="conoscenza" placeholder="Dove si è venuti a conoscenza del sito">
    <br>
    <br>
    <input type="submit" value="Invia">
</form>


<?php
}
?>
</body>
</html>