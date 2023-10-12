<head>
    <title>Numero 3 - G.C.</title>
    <!--
    Mostra un form composto da due list box, regione e provincia di nascita, quindi
    trasferiscili in una seconda pagina, mostrandoli a video. Sempre mediante i cookie
    viene chiesto di memorizzare il nome e il cognome del visitatore.
    -->
</head>
<body>
<?php
// Verifico se nei cookie c'è già il nome e il cognome, nel caso ci siano, allora li mostro
if (isset($_COOKIE['nome']) && isset($_COOKIE['cognome'])) {
    echo "<p>Ciao " . $_COOKIE['nome'] . " " . $_COOKIE['cognome'] . "</p>";
}
?>
    <form action="numero3b.php" method="post">
        <label for="regione">Regione</label>
        <select name="regione" id="regione">
            <option value="Abruzzo">Abruzzo</option>
            <option value="Basilicata">Basilicata</option>
            <option value="Calabria">Calabria</option>
            <option value="Campania">Campania</option>
            <option value="Emilia-Romagna">Emilia-Romagna</option>
            <option value="Friuli-Venezia Giulia">Friuli-Venezia Giulia</option>
            <option value="Lazio">Lazio</option>
            <option value="Liguria">Liguria</option>
            <option value="Lombardia">Lombardia</option>
            <option value="Marche">Marche</option>
            <option value="Molise">Molise</option>
            <option value="Piemonte">Piemonte</option>
            <option value="Puglia">Puglia</option>
            <option value="Sardegna">Sardegna</option>
            <option value="Sicilia">Sicilia</option>
            <option value="Toscana">Toscana</option>
            <option value="Trentino-Alto Adige">Trentino-Alto Adige</option>
            <option value="Umbria">Umbria</option>
            <option value="Valle d'Aosta">Valle d'Aosta</option>
            <option value="Veneto">Veneto</option>
        </select>
        <label for="provincia">Provincia</label>
        <select name="provincia" id="provincia">
            <option value="Agrigento">Agrigento</option>
            <option value="Alessandria">Alessandria</option>
            <option value="Ancona">Ancona</option>
            <option value="Aosta">Aosta</option>
            <option value="Arezzo">Arezzo</option>
            <option value="Ascoli Piceno">Ascoli Piceno</option>
            <option value="Asti">Asti</option>
            <option value="Avellino">Avellino</option>
            <option value="Bari">Bari</option>
            <option value="Barletta-Andria-Trani">Barletta-Andria-Trani</option>
            <option value="Belluno">Belluno</option>
            <option value="Benevento">Benevento</option>
            <option value="Bergamo">Bergamo</option>
            <option value="Biella">Biella</option>
            <option value="Bologna">Bologna</option>
            <option value="Bolzano">Bolzano</option>
            <option value="Brescia">Brescia</option>
            <option value="Brindisi">Brindisi</option>
            <option value="Cagliari">Cagliari</option>
            <option value="Caltanissetta">Caltanissetta</option>
            <option value="Campobasso">Campobasso</option>
            <option value="Carbonia-Iglesias">Carbonia-Iglesias</option>
            <option value="Caserta">Caserta</option>
            <option value="Catania">Catania</option>
            <option value="Catanzaro">Catanzaro</option>
            <option value="Chieti">Chieti</option>
            <option value="Como">Como</option>
            <option value="Cosenza">Cosenza</option>
            <option value="Cremona">Cremona</option>
            <option value="Crotone">Crotone</option>
            <option value="Cuneo">Cuneo</option>
            <option value="Enna">Enna</option>
            <option value="Fermo">Fermo</option>
            <option value="Ferrara">Ferrara</option>
            <option value="Firenze">Firenze</option>
            <option value="Foggia">Foggia</option>
            <option value="Forlì-Cesena">Forlì-Cesena</option>
            <option value="Frosinone">Frosinone</option>
            <option value="Genova">Genova</option>
            <option value="Gorizia">Gorizia</option>
            <option value="Grosseto">Grosseto</option>
            <option value="Imperia">Imperia</option>
            <option value="Isernia">Isernia</option>
            <option value="La Spezia">La Spezia</option>
            <option value="L'Aquila">L'Aquila</option>
            <option value="Latina">Latina</option>
            <option value="Lecce">Lecce</option>
            <option value="Lecco">Lecco</option>
            <option value="Livorno">Livorno</option>
            <option value="Lodi">Lodi</option>
            <option value="Lucca">Lucca</option>
            <option value="Macerata">Macerata</option>
            <option value="Mantova">Mantova</option>
            <option value="Massa-Carrara">Massa-Carrara</option>
            <option value="Matera">Matera</option>
            <option value="Medio Campidano">Medio Campidano</option>
            <option value="Messina">Messina</option>
            <option value="Milano">Milano</option>
            <option value="Modena">Modena</option>
        </select>
        <label for="nome">Nome</label>
        <input type="text" name="nome" id="nome" value="<?php
        if (isset($_COOKIE['nome'])) {
            echo $_COOKIE['nome'];
        }
        ?>">
        <label for="cognome">Cognome</label>
        <input type="text" name="cognome" id="cognome" value="<?php
        if (isset($_COOKIE['cognome'])) {
            echo $_COOKIE['cognome'];
        }
        ?>">
        <input type="submit" value="Invia">
    </form>
</body>