<?php
// Array associativo delle nazioni con capitale, lingua e bandiera di:
// Italia, Francia, Spagna, Germania, Inghilterra, Portogallo, Belgio, Svezia, Norvegia, Danimarca

$nazioni = array(
    "Italia" => array(
        "capitale" => "Roma",
        "lingua" => "Italiano",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/7/71/Flag_of_Italy_%28Pantone%2C_2003%E2%80%932006%29.svg/220px-Flag_of_Italy_%28Pantone%2C_2003%E2%80%932006%29.svg.png"
    ),
    "Francia" => array(
        "capitale" => "Parigi",
        "lingua" => "Francese",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/b/bc/Flag_of_France_%281794%E2%80%931815%2C_1830%E2%80%931974%2C_2020%E2%80%93present%29.svg/280px-Flag_of_France_%281794%E2%80%931815%2C_1830%E2%80%931974%2C_2020%E2%80%93present%29.svg.png"
    ),
    "Spagna" => array(
        "capitale" => "Madrid",
        "lingua" => "Spagnolo",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Flag_of_Spain.svg/2000px-Flag_of_Spain.svg.png"
    ),
    "Germania" => array(
        "capitale" => "Berlino",
        "lingua" => "Tedesco",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/b/ba/Flag_of_Germany.svg/2000px-Flag_of_Germany.svg.png"
    ),
    "Inghilterra" => array(
        "capitale" => "Londra",
        "lingua" => "Inglese",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/8/83/Flag_of_the_United_Kingdom_%283-5%29.svg/280px-Flag_of_the_United_Kingdom_%283-5%29.svg.png"
    ),
    "Portogallo" => array(
        "capitale" => "Lisbona",
        "lingua" => "Portoghese",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/5/5c/Flag_of_Portugal.svg/800px-Flag_of_Portugal.svg.png"
    ),
    "Belgio" => array(
        "capitale" => "Bruxelles",
        "lingua" => "Francese",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/6/65/Flag_of_Belgium.svg/2000px-Flag_of_Belgium.svg.png"
    ),
    "Svezia" => array(
        "capitale" => "Stoccolma",
        "lingua" => "Svedese",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/4/4c/Flag_of_Sweden.svg/800px-Flag_of_Sweden.svg.png"
    ),
    "Norvegia" => array(
        "capitale" => "Oslo",
        "lingua" => "Norvegese",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/d/d9/Flag_of_Norway.svg/2000px-Flag_of_Norway.svg.png"
    ),
    "Danimarca" => array(
        "capitale" => "Copenaghen",
        "lingua" => "Danese",
        "bandiera" => "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Flag_of_Denmark.svg/2000px-Flag_of_Denmark.svg.png"
    )
);

// Prendo la post del form select con nome "nazione" il valore della quale sarà la chiave dell'array
$nazione = $_POST["nazione"];

// Verifico che sia contenuta la chiave nel vettore.
if(!array_key_exists($nazione, $nazioni)){
    echo "Nazione non trovata";
    return;
}

// Stampo i dati della nazione selezionata
echo "<h1>$nazione</h1>";
echo "<p>Capitale: " . $nazioni[$nazione]["capitale"] . "</p>";
echo "<p>Lingua: " . $nazioni[$nazione]["lingua"] . "</p>";
echo "<img style='width: 50%; height:50%' src='" . $nazioni[$nazione]["bandiera"] . "' alt='Bandiera di $nazione' />";
?>