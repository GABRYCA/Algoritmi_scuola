-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Creato il: Mar 09, 2023 alle 13:45
-- Versione del server: 10.6.12-MariaDB-0ubuntu0.22.04.1
-- Versione PHP: 8.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `TPS_Verifica_Formativa`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `movimenti`
--

CREATE TABLE `movimenti` (
  `id` int(11) NOT NULL,
  `descrizione` varchar(255) NOT NULL,
  `euro` int(11) NOT NULL,
  `id_utente` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `movimenti`
--

INSERT INTO `movimenti` (`id`, `descrizione`, `euro`, `id_utente`) VALUES
(1, 'Esempio', -100, 670);

-- --------------------------------------------------------

--
-- Struttura della tabella `utenti`
--

CREATE TABLE `utenti` (
  `id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `nome` varchar(255) NOT NULL,
  `cognome` varchar(255) NOT NULL,
  `num_conto` int(11) NOT NULL,
  `saldo` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `utenti`
--

INSERT INTO `utenti` (`id`, `username`, `password`, `nome`, `cognome`, `num_conto`, `saldo`) VALUES
(1, 'anastasiya', 'qwerty', 'anastasiya', 'kozemko', 5, 50000000),
(2, 'GiovanniPacella', 'password', 'Giovanni', 'Pacella', 1234567, 200000),
(3, 'raffaello_morga', '12345', 'Raffaello', 'Morga', 3457882, 100000000),
(4, 'alice', '1234', 'alice', 'minuzzo', 123456, 555555550),
(5, 'andreatagini', 'password', 'Andrea', 'Tagini', 123456789, 987654321),
(6, 'GalbasiniMirko', '123', 'Mirko', 'Galbasini', 7, 50000000),
(7, 'gaiacasalini', '123', 'gaia', 'casalini', 4, 90000000),
(8, 'Mirko', '1234', 'Mirko', 'Sassi', 124312, 15000),
(9, 'andrecomo', '1234', 'andrea', 'comolli', 6, 100000),
(10, 'Angeloide', 'Passw', 'Riccardo', 'Angelo', 666, 6666666),
(11, 'Nico', '12345678', 'Nicola', 'Sannino', 17, 100000),
(12, 'Tara', '1234', 'Alberto', 'Tarabella', 18, 10000),
(13, 'joelalvarez', 'cobianchi', 'Joel', 'Alvarez', 2077, 2000000001),
(14, 'RicComo', '123', 'Riccardo', 'Como', 10, 40000),
(15, 'RSam', 'passoparola', 'Samuele', 'Rosetta', 88, 987654321),
(33, 'Sgrodo', 'Sgroda', 'Sosa', 'Saso', 3, 2147483647),
(670, 'AnonymousGCA', '1234', 'Anonymous', 'GAC', 13, 13000000),
(672, 'PIPPO', 'COCAINA', 'TUTTI', 'I GIORNI', 69, 666);

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `movimenti`
--
ALTER TABLE `movimenti`
  ADD PRIMARY KEY (`id`);

--
-- Indici per le tabelle `utenti`
--
ALTER TABLE `utenti`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `movimenti`
--
ALTER TABLE `movimenti`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT per la tabella `utenti`
--
ALTER TABLE `utenti`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=673;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
