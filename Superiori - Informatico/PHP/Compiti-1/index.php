<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Compiti di G.C.</title>
</head>
<body>
<?php


    echo "<br><br> Esercizio 1 <br><br>";

    // Visualizza i primi 100 numeri interi.
    for ($i = 1; $i <= 100; $i++) {
        echo $i . " ";
    }

    echo "<br><br><br><hr><br><br><br>";

    echo "Esercizio 2 <br><br>";

    // Visualizza una tabella di 20 righe e 20 colonne di colore blu con bordo=3 e
    // all’interno un numero che aumenta di 3 ogni volta, partendo da 0.
    echo "<table border='3' style='border-color: black;'>";
    $num = 0;
    for ($i = 0; $i < 20; $i++) {
        echo "<tr>";
        for ($j = 0; $j < 20; $j++) {
            echo "<td style='background-color: blue; color: white'>" . $num . "</td>";
            $num += 3;
        }
        echo "</tr>";
    }
    echo "</table>";



    echo "<br><br><br><hr><br><br><br>";

    echo "Esercizio 3 <br><br>";


    // Calcola e stampa a video quanti secondi sono trascorsi tra due date inserite.
    $data1 = new DateTime("2019-01-01 00:00:00");
    $data2 = new DateTime("2019-01-02 00:00:00");
    // Calcolo numero secondi trascorsi tra le due date:
    $intervallo = $diff = $data2->getTimestamp() - $data1->getTimestamp();
    // Stampo prima e seconda data:
    echo "Data 1: " . $data1->format('Y-m-d H:i:s') . "<br>";
    echo "Data 2: " . $data2->format('Y-m-d H:i:s') . "<br>";
    echo "Secondi trascorsi tra le due date: " . $intervallo . " secondi<br><br>";
    ?>
</body>
</html>