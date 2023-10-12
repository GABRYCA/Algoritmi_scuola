<?php
    function connessione() {
        // Info (PER FAVORE NON ABUSARNE).
        $DATABASE_HOST = '129.152.17.38';
        $DATABASE_USER = 'progetto_utente';
        $DATABASE_PASS = 'UtenteProgettoInfo666!';
        $DATABASE_NAME = 'progetto_info';

        // Connessione.
        $con = mysqli_connect($DATABASE_HOST, $DATABASE_USER, $DATABASE_PASS, $DATABASE_NAME);
        if (mysqli_connect_errno()) {
            // Errore di connessione, errore.
            exit('Connessione fallita al database: ' . mysqli_connect_error());
        }

        return $con;
    }

    function chiudiConnessione($con): void
    {
        $con->close();
    }
?>