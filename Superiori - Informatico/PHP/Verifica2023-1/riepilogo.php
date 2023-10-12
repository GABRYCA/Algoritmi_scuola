<?php
session_start();

// Controllo se esiste la sessione, se esiste rimando alla pagina squadre.php
if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit;
}

// Array con i nomi delle stazioni
$stazioni = array("Trento" => "Nord", "Milano" => "Nord", "Torino" => "Nord", "Firenze" => "Centro", "Bologna" => "Centro", "Roma" => "Centro", "Napoli" => "Sud", "Bari" => "Sud", "Messina" => "Sud");

$file = fopen("stazioni.txt", "r");

$dati = array();
while (!feof($file)){
    $line = fgets($file);
    $line = rtrim($line);
    if ($line != ""){
        $line = explode(" ", $line);
        $dati[] = array("$line[0]", "$line[1]", "$line[2]", "$line[3]");
    }
}

fclose($file);

?>
<html>
<head>
    <meta charset="UTF-8">
    <title>Verifica - Riepilogo - GCA</title>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet"
          integrity="sha384-0evHe/X+R7YkIZDRvuzKMRqM+OrBnVFBL6DOitfPri4tjfHxaWutUpFmBp4vmVor" crossorigin="anonymous">
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css"
          integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A=="
          crossorigin="anonymous" referrerpolicy="no-referrer"/>
    <script src="https://code.jquery.com/jquery-3.6.1.min.js"
            integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.js"
            integrity="sha512-zlWWyZq71UMApAjih4WkaRpikgY9Bz1oXIW5G0fED4vk14JjGlQ1UmkGM392jEULP8jbNMiwLWdM8Z87Hu88Fw=="
            crossorigin="anonymous" referrerpolicy="no-referrer"></script>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jquery-toast-plugin/1.3.2/jquery.toast.min.css"
          integrity="sha512-wJgJNTBBkLit7ymC6vvzM1EcSWeM9mmOu+1USHaRBbHkm6W9EgM0HY27+UtUaprntaYQJF75rc8gjxllKs5OIQ=="
          crossorigin="anonymous" referrerpolicy="no-referrer"/>
    <script src="https://code.jquery.com/ui/1.13.1/jquery-ui.min.js"
            integrity="sha256-eTyxS0rkjpLEo16uXTS0uVCS4815lc40K2iVpWDvdSY=" crossorigin="anonymous"></script>
</head>
<body class="font-monospace">

<div class="container mt-3 mb-5">
    <div class="row">
        <div class="col">
            <p class="h2 text-center">Riepilogo dati:</p>
        </div>
    </div>
    <hr>
    <div class="row">
        <div class="col">
            <a href="stazioni.php" class="btn btn-outline-primary w-100">Inserisci dati</a>
        </div>
    </div>
    <hr>
    <div class="row border border-dark rounded-5 mb-3 p-3">
        <div class="col">
            <p class="h2 text-center">Dati inseriti:</p>
            <hr>
            <?php

            foreach ($dati as $dato){

                // Ottengo la stringa con la data dal timestamp dato[1]
                $data = date("d/m/Y H:i:s", $dato[1]);

                echo "<p class='h5'>Stazione: <b>$dato[0]</b></p>
                      <p class='h5'>Data: $data</p>
                      <p class='h5'>Massima: $dato[2] °C</p>
                      <p class='h5'>Minima: $dato[3] °C</p><br>";
            }
            ?>
        </div>
    </div>
    <div class="row border border-dark rounded-5 p-3">
        <div class="col">
            <p class="h2 text-center">Per stazione:</p>
            <hr>
            <?php


            // Inizializzo Array dei dati-riepilogo.
            $stazioniFatte = array();
            $sommaZonaMinime = array("Nord" => 0, "Centro" => 0, "Sud" => 0);
            $countZonaMinime = array("Nord" => 0, "Centro" => 0, "Sud" => 0);
            $sommaZonaMassime = array("Nord" => 0, "Centro" => 0, "Sud" => 0);
            $countZonaMassime = array("Nord" => 0, "Centro" => 0, "Sud" => 0);
            foreach ($dati as $dato){

                // Verifico se in stazioniFatte è contenuto dato[0]
                for ($i = 0; $i < count($stazioniFatte); $i++){
                    if ($stazioniFatte[$i] == $dato[0]) {
                        // Salto il dato
                        continue 2;
                    }
                }

                // Sommo i valori (evito di fare altri cicli)
                $sommaZonaMassime[$stazioni[$dato[0]]] += $dato[2];
                $sommaZonaMinime[$stazioni[$dato[0]]] += $dato[3];
                $countZonaMassime[$stazioni[$dato[0]]]++;
                $countZonaMinime[$stazioni[$dato[0]]]++;

                // Dati temporanei per ottenere minimi giornalieri, settimanali e massimi.
                $max = 0;
                $minGiorno = 0;
                $minSettimana = 0;
                $countGiorno = 0;
                $countSettimana = 0;
                foreach ($dati as $dato2){
                    if ($dato[0] == $dato2[0]){
                        if ($dato2[2] > $max){
                            $max = $dato2[2];
                        }
                        if ($dato2[1] > time() - 86400){
                            $minGiorno += $dato2[3];
                            $countGiorno++;
                        }
                        if ($dato2[1] > time() - 604800){
                            $minSettimana += $dato2[3];
                            $countSettimana++;
                        }
                    }
                }
                $mediaGiorno = $minGiorno / $countGiorno;
                $mediaSettimana = $minSettimana / $countSettimana;

                $stazioniFatte[] = $dato[0];

                echo '<div class="row">
                        <div class="col">
                            <p class="h3 text-center mb-3">Stazione <b>' . $dato[0]. '</b>:</p>
                            <div class="row">
                                <div class="col">
                                    <p class="h5">Media minima giornaliera: ' . $mediaGiorno . ' °C</p>
                                    <p class="h5">Media minima settimanale: ' . $mediaSettimana . ' °C</p>
                                </div>
                                <div class="col border-start border-primary">
                                    <p class="h5">Massima più alta: ' . $max . ' °C</p>
                                </div>
                             </div>
                        </div>
                      </div><hr class="text-primary">';

                //echo "<p class='h5 text-center'>Stazione: $dato[0] - Temperatura massima: $max °C - Temperatura media minima: Giorno ($mediaGiorno °C) Settimana ($mediaSettimana °C).</p>";
            }

            $mediaMassimaZona = array("Nord" => 0, "Centro" => 0, "Sud" => 0);
            $mediaMinimaZona = array("Nord" => 0, "Centro" => 0, "Sud" => 0);

            foreach ($countZonaMinime as $zona => $conta){
                if ($conta != 0){
                    $mediaMinimaZona[$zona] = $sommaZonaMinime[$zona] /= $conta;
                } else {
                    $mediaMinimaZona[$zona] = $sommaZonaMinime[$zona] = 0;
                }
            }

            foreach ($countZonaMassime as $zona => $conta){
                if ($conta != 0){
                    $mediaMassimaZona[$zona] = $sommaZonaMassime[$zona] /= $conta;
                } else {
                    $mediaMassimaZona[$zona] = $sommaZonaMassime[$zona] = 0;
                }
            }

            ?>
        </div>
    </div>
    <hr>
    <div class="row border border-warning rounded-5 p-3">
        <div class="col text-center">
            <p class="h3">Per ogni zona: (0 potrebbe significare che non ci siano dati)</p>
            <hr>
            <?php
            echo "<p class='h3 fw-bold'>Nord:</p>";
            echo "<p>Temperatura media massima: " . round($mediaMassimaZona["Nord"], 1) . " °C</p>";
            echo "<p>Temperatura media minima: " . round($mediaMinimaZona["Nord"], 1) . " °C</p><br>";
            echo "<p class='h3 fw-bold'>Centro:</p>";
            echo "<p>Temperatura media massima: " . round($mediaMassimaZona["Centro"], 1) . " °C</p>";
            echo "<p>Temperatura media minima: " . round($mediaMinimaZona["Centro"], 1) . " °C</p><br>";
            echo "<p class='h3 fw-bold'>Sud:</p>";
            echo "<p>Temperatura media massima: " . round($mediaMassimaZona["Sud"], 1) . " °C</p>";
            echo "<p>Temperatura media minima: " . round($mediaMinimaZona["Sud"], 1) . " °C</p>";
            ?>
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
