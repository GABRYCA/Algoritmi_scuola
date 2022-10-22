<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <title>Esercizio 3 di G.C.</title>
</head>
<body>
<?php
// Scrivere uno script php che stampi su righe di 16 elementi i caratteri ASCII dal 33 al 127

echo "<p>Esercizio 1</p><br><br><br>";

// Inizializzo la variabile che conterrà il carattere ASCII
$char = 33;

// Inizializzo la variabile che conterrà il numero di caratteri stampati
$counter = 0;

// Ciclo che stampa i caratteri ASCII dal 33 al 127
while ($char <= 127) {
    // Stampo il carattere ASCII
    echo $char . "=" . chr($char) . " ";
    // Incremento il contatore dei caratteri stampati
    $counter++;
    // Se il contatore dei caratteri stampati è uguale a 16
    if ($counter == 16) {
        // A capo
        echo "<br>";
        // Resetto il contatore dei caratteri stampati
        $counter = 0;
    }
    // Incremento il carattere ASCII
    $char++;
}


echo "<br><br><br><hr><br><br><br><p>Esercizio 2</p><br><br><br>";

// Scrivere un programma che carichi un vettore con 10 elementi randomici tra 1 e 40 e svolgi le seguenti funzionalità:
// - Stampa del vettore.
// - Stampa del vettore ordinato in ordine cresente.
// - Stampa del vettore rimescolato.
// - Stampa del vettore ordinato in senso decrescente.
// - Stampa della posizione del valore 5, se esiste.

// Inizializzo il vettore con 10 elementi randomici tra 1 e 40.
$vector = array();
for ($i = 0; $i < 10; $i++) {
    $vector[$i] = rand(1, 40);
}

// Stampo il vettore
echo "Vettore: ";
for ($i = 0; $i < 10; $i++) {
    echo $vector[$i] . " ";
}

// Ordino il vettore in ordine crescente
sort($vector);
echo "<br>Vettore ordinato in ordine crescente: ";
for ($i =0; $i < 10; $i++) {
    echo $vector[$i] . " ";
}

// Rimescolo il vettore
shuffle($vector);
echo "<br>Vettore rimescolato: ";
for ($i = 0; $i < 10; $i++) {
    echo $vector[$i] . " ";
}

// Ordino il vettore in ordine decrescente
rsort($vector);
echo "<br>Vettore ordinato in ordine decrescente: ";
for ($i = 0; $i < 10; $i++) {
    echo $vector[$i] . " ";
}

// Cerco la posizione del valore 5
$position = array_search(5, $vector);
if ($position !== false) {
    echo "<br>Posizione del valore 5: " . $position;
} else {
    echo "<br>Il valore 5 non è presente nel vettore.";
}

echo "<br><br><br><hr><br><br><br><p>Esercizio 3</p><br><br><br>";

// Dopo aver generato randomicamente un array numeri di 20 numeri interi, mostra a schermo:
// - Il massimo
// - Il minimo
// - La media aritmetica
// - Il numero dei pari
// - Il numero dei dispari

// Inizializzo il vettore con 20 elementi randomici tra 1 e 100.
$vector = array();
for ($i = 0; $i < 20; $i++) {
    $vector[$i] = rand(1, 100);
}

// Il massimo
echo "Massimo: " . max($vector) . "<br>";

// Il minimo
echo "Minimo: " . min($vector) . "<br>";

// La media aritmetica
$sum = 0;
for ($i = 0; $i < count($vector); $i++) {
    $sum += $vector[$i];
}
$media = $sum / count($vector);
echo "Media aritmetica: " . $media . "<br>";

// Il numero dei pari
$pari = 0;
for ($i = 0; $i < count($vector); $i++) {
    if ($vector[$i] % 2 == 0) {
        $pari++;
    }
}
echo "Numero dei pari: " . $pari . "<br>";

// Il numero dei dispari
$dispari = count($vector) - $pari;
echo "Numero dei dispari: " . $dispari . "<br>";


echo "<br><br><br><hr><br><br><br><p>Esercizio 4</p><br><br><br>";

// Creare un array associativo contenente 10 stati europei con la rispettiva capitale
// Creare una funzione che passato il vettore ed una città, restituisce, se esiste, la nazione in cui è situata.
// Creare una funzione che passato il vettore ed una nazione, restituisca, se esiste, la sua capitale.
// Testare le funzioni con dei valori a tua scelta.
// Creare una funzione che stampi tutti gli elementi dell'array.

// Creo l'array associativo
$europeanStates = array(
    "Italia" => "Roma",
    "Francia" => "Parigi",
    "Germania" => "Berlino",
    "Spagna" => "Madrid",
    "Portogallo" => "Lisbona",
    "Inghilterra" => "Londra",
    "Svizzera" => "Berna",
    "Austria" => "Vienna",
    "Svezia" => "Stoccolma",
    "Norvegia" => "Oslo"
);

// Funzione che passato il vettore ed una città, restituisce, se esiste, la nazione in cui è situata.
function getPaese($vector, $city) {
    $country = array_search($city, $vector);
    if ($country !== false) {
        return $country;
    } else {
        return "La città non è presente nell'array.";
    }
}

// Funzione che passato il vettore ed una nazione, restituisca, se esiste, la sua capitale.
function getCapitale($vector, $country) {
    if (array_key_exists($country, $vector)) {
        return $vector[$country];
    } else {
        return "La nazione non è presente nell'array.";
    }
}

// Funzione che stampi tutti gli elementi dell'array.
function stampaArray($vector) {
    foreach ($vector as $key => $value) {
        echo $key . " - " . $value . "<br>";
    }
}

// Testo le funzioni
$citta = "Roma";
$nazionaleCapitale = "Inghilterra";
echo "In che nazione si trova " . $citta . "? " . getPaese($europeanStates, $citta) . "<br>";
echo "Qual'è la capitale di " . $nazionaleCapitale . "? " . getCapitale($europeanStates, $nazionaleCapitale) . "<br>";
echo "Stampo l'array:<br>";
stampaArray($europeanStates);

echo "<br><br><br><hr><br><br><br><p>Compiti:</p><br><br><br>";
echo "Creare un array associativo provincia-sigla della tua regione e creare una funzione che passato una provincia, se esiste
stampi la sigla corrispondente.";

//Creo l'array associativo
$privincePiemonte = array(
    "Torino" => "TO",
    "Vercelli" => "VC",
    "Novara" => "NO",
    "Cuneo" => "CN",
    "Asti" => "AT",
    "Alessandria" => "AL",
    "Biella" => "BI",
    "Verbano-Cusio-Ossola" => "VB",
    "Piemonte" => "PI"
);

//Funzione che passato una provincia, se esiste stampi la sigla corrispondente.
function getSigla($vector, $provincia) {
    if (array_key_exists($provincia, $vector)) {
        return $vector[$provincia];
    } else {
        return "La provincia non è presente nell'array.";
    }
}

//Testo la funzione
$provincia = "Torino";
echo "<br>Qual'è la sigla di " . $provincia . "? " . getSigla($privincePiemonte, $provincia) . "<br>";

echo "<br><br><br>Dopo aver creato un array contenete il nome del prodotto e il prezzo di 10 articoli ed implementare le seguenti funzionalità:
- La media dei prezzi
- Il prodotto più costoso
- Il prodotto meno costoso<br>";

//Creo l'array associativo
$prodotti = array(
    "Pasta" => 1.50,
    "Latte" => 1.00,
    "Pane" => 0.50,
    "Caffè" => 2.00,
    "Zucchero" => 1.00,
    "Cereali" => 2.50,
    "Biscotti" => 1.50,
    "Fette biscottate" => 1.00,
    "Marmellata" => 2.00,
    "Burro" => 1.50
);

//La media dei prezzi
$sum = 0;
foreach ($prodotti as $key => $value) {
    $sum += $value;
}
$media = $sum / count($prodotti);
echo "La media dei prezzi è: " . $media . "<br>";

//Il prodotto più costoso
$prezzoMax = max($prodotti);
$prodottoMax = array_search($prezzoMax, $prodotti);
echo "Il prodotto più costoso è: " . $prodottoMax . " a " . $prezzoMax . "€<br>";

//Il prodotto meno costoso
$prezzoMin = min($prodotti);
$prodottoMin = array_search($prezzoMin, $prodotti);
echo "Il prodotto meno costoso è: " . $prodottoMin . " a " . $prezzoMin . "€<br>";
?>
</body>
</html>