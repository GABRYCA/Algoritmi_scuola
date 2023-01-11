<?php
session_start();

if (isset($_SESSION['username'])){
    echo "<h3>Credenziali corrette</h3>";
    return;
}

header("Location: login.php");

?>