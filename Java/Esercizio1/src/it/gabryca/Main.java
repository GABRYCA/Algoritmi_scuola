package it.gabryca;

public class Main extends Util{

    public static void main(String[] args) {

        // Messaggio d'inizio.
        printfn("/////////////////////////////////////////////////////////////////");
        printfn("/        Alunno: Gabriele Caretti, Esercizio 1 (Equaz2)         /");
        printfn("/////////////////////////////////////////////////////////////////");

        // Richiamo la classe, per comodità ed evitare di usare new tante volte.
        Equaz2 equazClasse = new Equaz2();

        // Richiamo il metodo per eseguire un'equazione con i valori che si vogliono (descritti dall'utente).
        equazClasse.equaz2();

        // Pausa, chiedo all'utente di dare un input per continuare, pcosì ha tempo di vedere il suo risultato
        // Prima di iniziare la seconda parte descritta dall'esercizio.
        printfn("\nConfermare come detto dal messaggio di conferma per la seconda parte...");
        continua();

        // Comunico diversi risultati e chiamo i metodi.
        printfn("\nSoluzioni reali delle seguenti equazioni: ");
        printfn("Equazione: y = x2 - 4x + 3...");
        equazClasse.soluzioneReale(1,-4,3);
        printfn("\nEquazione: y = 3x2 +5x -2...");
        equazClasse.soluzioneReale(3,5,-2);
        printfn("\nEquazione: y = 2x2 + 4x +5...");
        equazClasse.soluzioneReale(2,4,5);

        // Messaggio di fine.
        printfn("\n\nFine Esercizio 1! Chiusura in corso...");
    }
}
