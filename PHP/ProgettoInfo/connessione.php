<?php
    function connessione() {
        // Info.
        $DATABASE_HOST = 'localhost';
        $DATABASE_USER = 'progetto_utente_locale';
        $DATABASE_PASS = 'UtenteProgettoInfo666!Locale';
        $DATABASE_NAME = 'progetto_info_locale';

        // Connessione.
        $con = mysqli_connect($DATABASE_HOST, $DATABASE_USER, $DATABASE_PASS, $DATABASE_NAME);
        if (mysqli_connect_errno()) {
            // Errore di connessione, errore.
            exit('Connessione fallita al database: ' . mysqli_connect_error());
        }

        return $con;
    }

    function chiudiConnessione($con) {
        $con->close();
    }
?>