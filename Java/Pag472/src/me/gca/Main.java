package me.gca;

import java.util.Vector;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("\n/////////////////////////////////////" +
                "\n// Compito vector di G.C. 4BITI //" +
                "\n/////////////////////////////////////");

        Util.printfn("\nProgramma 1: ");
        Vector vector = new Vector();
        int randNumero;
        do {
            randNumero = numeroCasuale(1, 9);
            vector.addElement(randNumero);
        } while (randNumero != 5);

        // Visualizza vettore:
        Util.printf("\nNumeri: " + vector);



        Util.printfn("\nProgramma 2:");
        Vector vectorA = new Vector();
        Vector vectorB = new Vector();
        Vector vectorC = new Vector();
        int randNumero2;
        do {
            randNumero2 = numeroCasuale(0, 999);
            if (randNumero2 <= 9){
                vectorA.addElement(randNumero2);
            } else if (randNumero2 <= 99){
                vectorB.addElement(randNumero2);
            } else if (randNumero2 <= 999){
                vectorC.addElement(randNumero2);
            }
        } while (randNumero2 != 0);
        Util.printf("\nNumeri 0-9: " + vectorA);
        Util.printf("\nNumeri 10-99: " + vectorB);
        Util.printf("\nNumeri 100-999: " + vectorC);



        Util.printfn("\n\nProgramma 3:");
        int contatore;

        // Numero parole da inserire.
        Util.printf("\nQuante parole vorresti inserire: ");
        contatore = Util.getScanner().nextInt();

        Vector parole = new Vector();

        // Inserimento parole.
        Util.printfn("\nInserire parole una ad una: ");
        for(int i = 0; i < contatore; i++) {
            parole.addElement(Util.getScanner().nextLine());
        }
        // Ordino le parole
        for (int i = 0; i < contatore; i++) {
            for (int j = i + 1; j < contatore; j++) {
                String parola1 = (String) parole.get(i), parola2 = (String) parole.get(j);
                if (parola1.compareTo(parola2) > 0) {
                    parole.set(i, parola2);
                    parole.set(j, parola1);
                }
            }
        }

        // Visualizza in ordine alfabetico il vector.
        Util.printfn("\nParole ordinate: " + parole);



        // Programma 4
        Util.printfn("\nProgramma 4: " +
                "\n\nInserire dei numeri, inserire 0 per uscire: ");
        Vector vectorNumeri = new Vector();
        int numeroIngresso;
        do {
            numeroIngresso = Util.getScanner().nextInt();
            if (numeroIngresso != 0) {
                vectorNumeri.addElement(numeroIngresso);
            }
        } while (numeroIngresso != 0);
        tuttiNumeriDueVolte(vectorNumeri);



        // Programma 5
        Util.printfn("\nProgramma 5:");
        Vector vectorN = new Vector();
        int numeroGenerato;
        do {
            numeroGenerato = numeroCasuale(1,9);
            vectorN.addElement(numeroGenerato);
        } while (numeroGenerato != 5);
        tuttiNumeriDueVolte(vectorN);



        // Programma 6
        Util.printfn("\nProgramma 6:");
        Vector vectorP6 = new Vector();
        int nGen, nPari = 0, nDispari = 0;
        do {
            nGen = numeroCasuale(20, 40);
            vectorP6.addElement(nGen);
        } while (nGen % 5 != 0);
        dispariQuantiPari(vectorP6, nPari, nDispari);



        // Programma 7
        Util.printfn("\nProgramma 7:");
        Vector esempio = new Vector();
        Vector clone = CustomVector.clone(esempio);
        Util.printfn("\n" + clone);



        // Programma 8
        Util.printfn("\nProgramma 8:");
        Vector verificoOrdine = new Vector();
        boolean ordinato = CustomVector.ordinato(verificoOrdine);
        Util.printfn("\n" + ordinato);


        // Programma 9
        Util.printfn("\nProgramma 9:");
        int nPermutazioni = 5, nNumeriValidi = 0, tempNum;
        Vector vetBase = new Vector(), tempVet = new Vector();
        // Genera.
        do {
            tempNum = numeroCasuale(1, 10);
            if (!contieneNumero(tempNum, tempVet)){
                tempVet.addElement(tempNum);
                nNumeriValidi++;
            }
        } while (nNumeriValidi < nPermutazioni);
        // Sposta.
        for (int i = 0; i < nPermutazioni; i++){
            boolean valido;
            int posizioneCasuale, numeroDaSpostare;
            do {
                posizioneCasuale = numeroCasuale(0, nPermutazioni);
                numeroDaSpostare = (int) tempVet.get(posizioneCasuale);
                valido = numeroDaSpostare != 0;
            } while (!valido);
            tempVet.setElementAt(posizioneCasuale, 0);
            vetBase.addElement(numeroDaSpostare);
        }

    }

    /**
     * Verifica se un Vector contiene un numero.
     * */
    private static boolean contieneNumero(int n, Vector v){
        for (Object o : v){
            if ((int) o == n){
                return true;
            }
        }
        return false;
    }

    /**
     * Conta quanti numeri pari e dispari sono disponibili nel vettore e ritorna true se i pari sono quanti i dispari.
     * */
    private static boolean dispariQuantiPari(Vector vectorP6, int nPari, int nDispari) {
        for (Object o : vectorP6){
            if ((int) o % 2 == 0){
                nPari++;
            } else {
                nDispari++;
            }
        }
        if (nPari == nDispari){
            Util.printfn("\nI numero pari sono quanti quelli dispari!");
            return true;
        }
        return false;
    }

    /**
     * Ritorna anche un valore booleano come da consegna.
     * */
    private static boolean tuttiNumeriDueVolte(Vector vectorNumeri) {
        int numeriTrue = 0;
        for (int i = 0; i < vectorNumeri.size(); i++){
            int numero = (int) vectorNumeri.get(i);
            for (int j = 0; j < vectorNumeri.size(); j++){
                if (j != i){
                    if (numero == (int) vectorNumeri.get(j)){
                        numeriTrue++;
                    }
                }
            }
        }

        if (numeriTrue == vectorNumeri.size()){
            Util.printfn("\nPresente almeno 2 volte: True.");
            return true;
        } else {
            Util.printfn("\nPresente almeno 2 volte: False.");
            return false;
        }
    }

    public static int numeroCasuale(int min, int max){
        return (int) ((Math.random() * (max - min)) + min);
    }
}
