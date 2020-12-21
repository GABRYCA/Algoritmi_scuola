package it.gabryca;

public class Equaz2 extends Util {

    /**
     * Metodo principale della classe.
     * Serve a calcolare un'equazione specificata dall'utente.
     * */
    public void equaz2 (){

        // Dichiaro variabili.
        double a,b,c, delta, soluzione1, soluzione2;

        // Chiedo dati in ingresso all'utente.
        printfn("\nInizia l'equazione, inserire i valori seguendo il seguente formato quando richiesto: " +
                "\ny = ax2+bx+c\n");
        printf("Inserire a: ");
        a = getScanner().nextInt();
        printf("Inserire b: ");
        b = getScanner().nextInt();
        printf("Inserire c: ");
        c = getScanner().nextInt();

        // Ottengo delta e soluzioni.
        delta = delta(a,b,c);

        if (delta == 0 || delta < 0){

            // Ottengo la soluzione.
            soluzione1 = -b/(2*a);

            // Comunico la soluzione.
            printfn("\nL'equazione è di tipo reale, ha solamente 1 soluzione!");
            printfn("Soluzione: " + soluzione1);

        } else {

            // Ottengo le soluzioni.
            soluzione1 = soluzione(a,b,delta,1);
            soluzione2 = soluzione(a,b,delta,2);

            // Comunico le soluzioni.
            printfn("\nSoluzione 1 (+): " + soluzione1);
            printfn("Soluzione 2 (-): " + soluzione2);

        }
    }


    /**
     * Inserire 3 dati, a, b e c.
     * Ritorna il delta.
     *
     * @param a;
     * @param b;
     * @param c;
     *
     * @return delta;
     * */
    private double delta (double a, double b, double c){
        // Inizializzo variabile che sarà anche il risultato.
        double delta;

        // Eseguo espressione per ottenere il risultato (delta)
        delta = ((b*b) - (4 * (a*c)));

        // Ritorno il delta o risultato del metodo.
        return delta;
    }

    /**
     * Inserire il delta e l'argomento.
     * L'argomento se vale 1 darà il risultato con la radice +.
     * L'argomento se vale 2 darà il risultato con la radice -.
     *
     * @param a;
     * @param b;
     * @param delta;
     * @param argomento;
     *
     * @return soluzione;
     * */
    private double soluzione(double a, double b, double delta, double argomento){
        // Inizializzo variabile o soluzione del metodo.
        double soluzione = 0;

        // Se il delta è uguale a 0 o minore, saranno prese misure speciali.
        if (delta == 0 || delta < 0){

            // Ottengo soluzione.
            soluzione = -b/(2*a);

            // Ritorno soluzione
            return soluzione;
        }

        // In base all'argomento ottengo una delle soluzioni (solitamente 1 è positivo, 2 negativo).
        if (argomento == 1){

            soluzione = ((-b + Math.sqrt(delta))) / (2*a);


        } else if (argomento == 2){

            soluzione = ((-b - Math.sqrt(delta))) / (2*a);

        }

        // Ritorno il valore della soluzione.
        return soluzione;
    }


    /**
     * Metodo creato per trovare una soluzione reale, inizialmente era necessario, ora
     * sarebbe anche evitabile ma lo mantengo comunque.
     *
     * @param a;
     * @param b;
     * @param c;
     * */
    public void soluzioneReale(double a, double b, double c){

        // Dichiaro variabili e ottengo delta
        double soluzione1, soluzione2, delta;
        delta = delta(a,b,c);

        // Verifico condizioni del delta, nel caso si avverassero verranno prese misure speciali.
        if (delta == 0 || delta < 0){
            // Ottengo il valore della soluzione.
            soluzione1 = -b/(2*a);
            // Comunico il risultato.
            printfn("\nL'equazione è reale e avrà solamente 1 soluzione! Oppure ha delta minore 0...");
            printfn("Soluzione: " + soluzione1 + "\n");
            // Fermo il metodo.
            return;
        }

        // Ottengo le soluzioni.
        soluzione1 = ((-b + Math.sqrt(delta)) / (2*a));
        soluzione2 = ((-b - Math.sqrt(delta)) / (2*a));

        // Comunico le soluzioni.
        printfn("\nL'equazione non è reale e avrà 2 soluzioni!");
        printfn("Soluzione 1: " + soluzione1);
        printfn("Soluzione 2: " + soluzione2  + "\n");
    }
}
