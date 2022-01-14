package me.gca;

import java.util.Collections;
import java.util.Iterator;
import java.util.PriorityQueue;

public class Main {

    public static long numeroAzioni = 0;

    public static void main(String[] args) {

        System.out.println(   "////////////////////////////" +
                            "\nAlbero Binario di GCA 4BITI." +
                            "\n////////////////////////////");

        // Legenda Globale
        int[] numeri;
        // Cambiare nNumeriCasuali per impostare il numero di numeri da inserire e ordinare nell'albero.
        int nNumeriCasuali = 10000000, min = 1, max = 10001;
        // Scelta Menu'.
        int scelta;
        do {

            // Legenda e scelta.
            Util.printf("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> BuildSort." +
                    "\n2 -> HeapSort." +
                    "\n3 -> Code di priorita' con Heap." +
                    "\n4 -> PriorityQueue Java." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            // Switch scelta.
            switch (scelta){
                case 0:{

                    // Uscita.
                    Util.printfn("\nHai scelto: Esci..." +
                            "\nUscita in corso...");
                    break;
                }

                case 1:{

                    // Inizio BuildSort.
                    Util.printfn("\nHai scelto: BuildSort...");

                    // Creazione numeri casuali.
                    Util.printfn("\nGenerazione " + nNumeriCasuali + " numeri in corso...");
                    numeri = new int[nNumeriCasuali];
                    for (int i = 0; i < nNumeriCasuali; i++){
                        numeri[i] = getNumeroCasuale(min, max);
                    }
                    Util.printfn("\nNumeri generati con successo! [" + nNumeriCasuali + "]");

                    // Creazione Albero (non strettamente necessario).
                    Util.printfn("\nCreazione albero in corso...");
                    AlberoBin alberoBin = new AlberoBin();
                    alberoBin.creaDaVettore(numeri, 0, numeri.length);
                    Util.printfn("\nAlbero creato con successo!");

                    // Inizializzo classe in cui si usa heapify.
                    HeapSort buildSort = new HeapSort();

                    // Avvio BuildSort.
                    Util.printfn("\nAvviato BuildSort: ");
                    numeroAzioni = 0;
                    long inizio = System.currentTimeMillis();
                    buildSort.buildHeap(numeri, numeri.length);
                    long fine = System.currentTimeMillis();
                    Util.printfn("\nFine BuildSort!");

                    // Comunico tempi.
                    System.out.println("Tempo impiegato in secondi: "+ ((fine-inizio) / 1000));
                    System.out.println("Numero azioni: " + numeroAzioni);

                    // Stamp vettore se mostra e' true.
                    boolean mostra = false;
                    if (mostra) {
                        System.out.println("Vettore ordinato: ");
                        stampaVettore(numeri);
                    }

                    // Verifica se Heap valido se analizzaHeap e' true.
                    boolean analizzaHeap = false;
                    if (analizzaHeap) {
                        if (isHeap(numeri)) {
                            System.out.println("\nSi, e' un heap valido.");
                        } else {
                            System.out.println("\nNo, non e' un heap valido!");
                        }
                    }

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 2:{

                    // Inizio HeapSort.
                    Util.printfn("\nHai scelto: HeapSort....");

                    // Genero numeri casuali.
                    Util.printfn("\nGenerazione " + nNumeriCasuali + " in corso...");
                    numeri = new int[nNumeriCasuali];
                    for (int i = 0; i < nNumeriCasuali; i++){
                        numeri[i] = getNumeroCasuale(min, max);
                    }
                    Util.printfn("\nNumeri generati con successo! [" + nNumeriCasuali + "]");

                    // Creo albero (Non strettamente necessario).
                    Util.printfn("\nCreazione albero in corso...");
                    AlberoBin alberoBin = new AlberoBin();
                    alberoBin.creaDaVettore(numeri, 0, numeri.length);
                    Util.printfn("\nAlbero creato con successo!");

                    // Avvio HeapSort.
                    Util.printfn("\nAvviato HeapSort: ");
                    numeroAzioni = 0;
                    HeapSort heapSort = new HeapSort();
                    long inizio = System.currentTimeMillis();
                    heapSort.sort(numeri);
                    long fine = System.currentTimeMillis();
                    Util.printfn("\nFine HeapSort!");

                    // Se mostra e' true, leggo il vettore.
                    boolean mostra = false;
                    if (mostra) {
                        System.out.println("Vettore ordinato: ");
                        stampaVettore(numeri);
                    }

                    // Comunico tempi.
                    System.out.println("Tempo impiegato in secondi: "+ ((fine-inizio) / 1000));
                    System.out.println("Numero azioni: " + numeroAzioni);

                    // Scambia ultimi con primi.
                    numeri = reverse(numeri, numeri.length);

                    // Se mostra e' true, leggo il vettore di nuovo.
                    mostra = false;
                    if (mostra) {
                        System.out.println("Vettore ordinato: ");
                        stampaVettore(numeri);
                    }

                    // Analizza Heap se analizzaHeap e' true.
                    boolean analizzaHeap = true;
                    if (analizzaHeap) {
                        if (isHeap(numeri)) {
                            System.out.println("\nSi, e' un heap valido.");
                        } else {
                            System.out.println("\nNo, non e' un heap valido!");
                        }
                    }

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 3:{

                    Util.printfn("\nHai scelto: Code di priorita' con Heap...");

                    // Genero numeri casuali.
                    Util.printfn("\nGenerazione " + nNumeriCasuali + " in corso...");
                    numeri = new int[nNumeriCasuali];
                    for (int i = 0; i < nNumeriCasuali; i++){
                        numeri[i] = getNumeroCasuale(min, max);
                    }
                    Util.printfn("\nNumeri generati con successo! [" + nNumeriCasuali + "]");

                    numeroAzioni = 0;
                    Util.printfn("\nCreo albero da vettore...");
                    long inizio = System.currentTimeMillis();
                    AlberoHeap alberoHeap = new AlberoHeap(numeri.length);
                    // Abuso di insert qui.
                    alberoHeap.daVettore(numeri);
                    long fine = System.currentTimeMillis();
                    Util.printfn("\nAlbero creato con successo!");

                    // Comunico tempi.
                    System.out.println("Tempo impiegato in secondi: "+ ((fine-inizio) / 1000));
                    System.out.println("Numero azioni: " + numeroAzioni);

                    // Elemento massimo.
                    Util.printfn("\nMaximum: " + alberoHeap.maximum());

                    // Rimuovo elemento massimo.
                    Util.printfn("\nRimuovo Maximum ossia: " + alberoHeap.maximum());
                    alberoHeap.extractMax();

                    // Nuovo Maximum:
                    Util.printfn("\nNuovo Maximum: " + alberoHeap.maximum());

                    boolean stampaAlbero = false;
                    if (stampaAlbero) {
                        // Stampo albero:
                        Util.printfn("\nAlbero completo: ");
                        alberoHeap.stampa();
                    }

                    Util.continua();
                    break;
                }

                case 4: {

                    Util.printfn("\nHai scelto: PriorityQueue Java...");

                    // Genero numeri casuali.
                    Util.printfn("\nGenerazione " + nNumeriCasuali + " in corso...");
                    numeri = new int[nNumeriCasuali];
                    for (int i = 0; i < nNumeriCasuali; i++){
                        numeri[i] = getNumeroCasuale(min, max);
                    }
                    Util.printfn("\nNumeri generati con successo! [" + nNumeriCasuali + "]");

                    // Creo una PriorityQueue vuota.
                    PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());

                    // Inserisco i valori del vettore numeri.
                    long inizio = System.currentTimeMillis();
                    for (int i : numeri){
                        priorityQueue.add(i);
                    }
                    long fine = System.currentTimeMillis();

                    System.out.println("Tempo impiegato in secondi: "+ ((fine-inizio) / 1000));

                    // Elemento con priorita' massima:
                    System.out.println("Valore peek (testa):" + priorityQueue.peek());

                    boolean stampaTutto = false;
                    if (stampaTutto) {
                        // Stampo tutti gli elementi:
                        System.out.println("Elementi:");
                        for (Integer integer : priorityQueue) {
                            System.out.println(integer);
                        }
                    }

                    // Rimuovo l'elemento con più priorita' tramite poll e stampo di nuovo la coda.
                    priorityQueue.poll();
                    if (stampaTutto) {
                        Util.printfn("Dopo rimozione elemento con poll:");
                        for (Integer integer : priorityQueue) {
                            System.out.println(integer);
                        }
                    }

                    // Rimuovo valore specifico.
                    boolean rimuovoValoreSpecifico = false;
                    if (rimuovoValoreSpecifico) {
                        int valore = 13;
                        priorityQueue.remove(valore);
                        Util.printfn("Dopo rimozione di " + valore + " con la funzione di rimozione:");

                        if (stampaTutto) {
                            for (Integer integer : priorityQueue) {
                                System.out.println(integer);
                            }
                        }
                    }

                    // Verifico se un elemento e' presente con la funzione contains:
                    boolean verificoSePresenteValore = false;
                    if (verificoSePresenteValore) {
                        int valore = 17;
                        boolean b = priorityQueue.contains(valore);
                        Util.printfn("Coda di priorita' contiene il valore " + valore + " oppure no?: " + b);
                    }

                    // Ottengo valori usando toArray e stampo.
                    boolean ottieniValoriEStampa = false;
                    if (ottieniValoriEStampa) {
                        Object[] arr = priorityQueue.toArray();
                        System.out.println("Valore nel vettore: ");

                        for (Object o : arr) {
                            System.out.println("Value: " + o.toString());
                        }
                    }

                    Util.continua();
                    break;
                }

                default: {

                    // Scelta non valida.
                    Util.printfn("\nValore inserito non valido! Per favore riprovare...");

                }
            }

        } while (scelta != 0);

        /*if (numeriCasuali){
            numeri = new int[nNumeriCasuali];
            for (int i = 0; i < nNumeriCasuali; i++){
                numeri[i] = getRandomNumber(min, max);
            }
            System.out.println("\nNumeri generati con successo! [" + nNumeriCasuali + "]\n");
        }

        if (letturaAlbero) {
            AlberoBin alberoBin = new AlberoBin();
            alberoBin.creaDaVettore(numeri, 0, numeri.length);
            stampaAlbero(alberoBin);
        }

        if (heapSortAttivo) {
            HeapSort heapSort = new HeapSort();
            long inizio = System.currentTimeMillis();
            heapSort.sort(numeri);
            long fine = System.currentTimeMillis();

            if (mostraVettore) {
                System.out.println("Vettore ordinato: ");
                stampaVettore(numeri);
            }
            System.out.println("Tempo impiegato in secondi: "+ ((fine-inizio) / 1000));
            System.out.println("Numero azioni: " + numeroAzioni);

            // Scambia ultimi con primi.
            numeri = reverse(numeri, numeri.length);

            if (isHeap(numeri)){
                System.out.println("\nSi, e' un heap valido.");
            } else {
                System.out.println("\nNo, non e' un heap valido!");
            }
            if (letturaAlberoHeap) {
                AlberoBin alberoBin = new AlberoBin();
                alberoBin.creaDaVettore(numeri, 0, numeri.length);
                stampaAlbero(alberoBin);
            }

            if (mostraVettoreDopoHeapify){
                System.out.println("\nVettore dopo Heapify: ");
                stampaVettore(numeri);
            }

            if (buildHeap){
                System.out.println("\nBuildHeap: ");
                numeroAzioni = 0;
                inizio = System.currentTimeMillis();
                heapSort.sort(numeri);
                fine = System.currentTimeMillis();

                System.out.println("Tempo impiegato in secondi: "+ ((fine-inizio) / 1000));
                System.out.println("Numero azioni: " + numeroAzioni);
            }
        }*/

        // Messaggio di uscita.
        Util.printf("\nUscito con successo!");
    }

    private static void stampaAlbero(AlberoBin alberoBin) {
        // radice, sinistra, destro etc.
        alberoBin.preorder1();
        // sinistra, destro, radice etc.
        alberoBin.postorder1();
        // sinistra, radice, destro etc.
        alberoBin.inorder1();

        System.out.println("\n\n" + alberoBin);
    }

    public static int getNumeroCasuale(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }

    public static void stampaVettore(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }

    public static int[] reverse(int[] vettore, int n) {
        int[] temp = new int[n];
        int j = n;
        for (int i = 0; i < n; i++) {
            temp[j - 1] = vettore[i];
            j = j - 1;
        }
        return temp;
    }

    public static boolean isHeap(int[] vettore){
        for (int i = 0; i < vettore.length - 1; i++){
            if (vettore[i] < vettore[i+1]){
                return false;
            }
        }
        return true;
    }
}