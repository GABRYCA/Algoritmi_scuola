package me.gca;

import java.io.*;
import java.util.List;
import java.util.Random;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("/////////////////////////////////////" +
                   "\n         Grafo G.C. 4BITI" +
                   "\n/////////////////////////////////////");



        // Ciclo che continua fino alla scelta 0 che porta alla chiusura del programma.
        int scelta;
        do {
            // Legenda e valore della scelta utente.
            Util.printf("\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Grafo a matrice." +
                    "\n2 -> Grafo a liste delle adiacenze (Da fare)." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            // Opzioni.
            switch (scelta){

                case 0:{

                    // Messaggio scelta.
                    Util.printfn("\nHai scelto: Esci..." +
                            "\nUscita in corso...");

                    break;
                }

                case 1:{

                    matriceAdiacenze();

                    break;
                }

                case 2:{

                    // Non ancora iniziato, messaggio d'inizio.
                    Util.printfn("\nHai scelto: Grafo con liste delle adiacenze...");

                    // Inizializzo grafo.
                    GrafoListeAdiacenza grafoListeAdiacenza = new GrafoListeAdiacenza();

                    // Carico il FILE se esistente e inizializzo il grafico.
                    try {

                        FileInputStream fi = new FileInputStream(new File("grafoListe.txt"));
                        ObjectInputStream oi = new ObjectInputStream(fi);

                        grafoListeAdiacenza = (GrafoListeAdiacenza) oi.readObject();

                        oi.close();
                        fi.close();

                    } catch (FileNotFoundException e) {
                        Util.printfn("File non trovato.");
                    } catch (IOException e) {
                        Util.printfn("Errore nel caricamento.");
                    } catch (ClassNotFoundException e) {
                        e.printStackTrace();
                    }

                    if (grafoListeAdiacenza == null){
                        grafoListeAdiacenza = new GrafoListeAdiacenza();
                    } else {
                        Util.printfn("\nFile caricato con successo!");
                    }

                    int scelta2;
                    do {
                        // Legenda e scelta utente.
                        Util.printf("\nOpzioni:" +
                                "\n0 -> Esci." +
                                "\n1 -> Aggiungi nodo." +
                                "\n2 -> Aggiungi arco." +
                                "\n3 -> Rimuovi arco." +
                                "\n4 -> Visualizza." +
                                "\n5 -> Modifica nodi." +
                                "\n6 -> Aggiungi N nodi casuali." +
                                "\n7 -> Verifica presenza cammino tra nodo A e B." +
                                "\n8 -> Cammino tra nodo A e B." +
                                "\n9 -> Rimuovi nodo." +
                                "\n10 -> Visita BFS." +
                                "\n11 -> Visita DFS." +
                                "\nScelta: ");
                        scelta2 = Util.getScanner().nextInt();

                        switch (scelta2){

                            case 0:{

                                // Messaggio d'inizio.
                                Util.printfn("\nUscita dal grafo...");

                                // Salvo sul disco il grafo in un file serializzato.
                                File file = new File("grafoListe.txt");
                                try {
                                    if (file.createNewFile()){
                                        Util.printfn("File creato " + file.getName());
                                    } else {
                                        Util.printfn("File gia' esistente.");
                                    }
                                } catch (IOException e) {
                                    e.printStackTrace();
                                }

                                try {
                                    FileOutputStream f = new FileOutputStream(new File("grafoListe.txt"));
                                    ObjectOutputStream o = new ObjectOutputStream(f);

                                    o.writeObject(grafoListeAdiacenza);

                                    o.close();
                                    f.close();

                                } catch (FileNotFoundException e) {
                                    System.out.println("File non trovato.");
                                } catch (IOException e) {
                                    System.out.println("Errore nel salvataggio.");
                                }

                                break;
                            }

                            case 1:{

                                Util.printfn("\nHai scelto: Aggiungi nodo...");

                                // Inizializzo nuovo nodo.
                                NodoLista nodo = new NodoLista();

                                // Opzione.
                                int scelta3;
                                do {
                                    Util.printf("\nInserire informazioni nodo o farne uno vuoto?" +
                                            "\n0 -> Vuoto." +
                                            "\n1 -> Avanzato." +
                                            "\nScelta: ");
                                    scelta3 = Util.getScanner().nextInt();
                                    if (scelta3 != 0 && scelta3 != 1){
                                        Util.printfn("\nScelta non valida, per favore riprovare...");
                                    }
                                } while (scelta3 != 0 && scelta3 != 1);

                                // Se scelta 1 chiedo i dati.
                                if (scelta3 == 1){
                                    Util.printf("\nInserire nome: ");
                                    nodo.setNome(Util.getScanner().nextLine());
                                    Util.printf("\nDifficolta':" +
                                            "\nPiu' e' alto il valore, e maggiore e' il grado, es:" +
                                            "\n1 -> T - Turistico." +
                                            "\n2 -> E - Escursionistico." +
                                            "\nEtc..." +
                                            "\nDifficolta':");
                                    nodo.setDifficolta(Util.getScanner().nextInt());

                                    Util.printf("\nInserire altitudine: ");
                                    nodo.setAltitudine(Util.getScanner().nextInt());
                                }

                                // Aggiungo il nodo al grafo.
                                grafoListeAdiacenza.addNodo(nodo);

                                // Messaggio di fine.
                                Util.printfn("\nNodo aggiunto con successo!");

                                Util.continua();

                                break;
                            }

                            case 2:{

                                Util.printfn("\nHai scelto: Aggiungi arco...");

                                // Stampo adiacenze e nodi.
                                grafoListeAdiacenza.stampaAdiacenze();
                                Util.printfn("\n");
                                grafoListeAdiacenza.stampaNodi();

                                // Chiedo all'utente conferma.
                                Util.printf("\n\nSei sicuro di voler aggiungere un arco? " +
                                        "\n1 -> per confermare." +
                                        "\n? -> Qualsiasi numero per annullare." +
                                        "\nScelta: ");
                                // Se non conferma, fermo qui.
                                if (Util.getScanner().nextInt() != 1){
                                    break;
                                }

                                int nodoA;
                                int nodoB;
                                Util.printf("\nPosizione nodoA: ");
                                nodoA = Util.getScanner().nextInt();

                                Util.printf("\nPosizione nodoB: ");
                                nodoB = Util.getScanner().nextInt();

                                if (grafoListeAdiacenza.addArco(nodoA, nodoB)){
                                    Util.printfn("\nAggiunto arco con successo!");
                                } else {
                                    Util.printfn("\nUno dei dati non e' valido, per favore riprovare!");
                                }

                                // Pausa.
                                Util.continua();
                                break;
                            }

                            case 3:{

                                Util.printfn("\nHai scelto: Rimuovi arco...");

                                // Stampo matrice delle adiacenze e nodi.
                                grafoListeAdiacenza.stampaAdiacenze();
                                Util.printfn("");
                                grafoListeAdiacenza.stampaNodi();

                                // Chiedo conferma all'utente.
                                Util.printf("\n\nSei sicuro di voler rimuovere un arco? " +
                                        "\n1 per confermare." +
                                        "\nQualsiasi numero per annullare." +
                                        "\nScelta: ");
                                // Se l'utente non conferma, mi fermo qui.
                                if (Util.getScanner().nextInt() != 1){
                                    break;
                                }

                                // Chiedo all'utente che nodi voglia interessare e li carico.
                                int nodoA;
                                int nodoB;
                                Util.printfn("\nPosizione Nodo 1: ");
                                nodoA = Util.getScanner().nextInt();

                                Util.printfn("\nPosizione Nodo 2: ");
                                nodoB = Util.getScanner().nextInt();

                                // Rimuovo l'arco e in base all'esito comunico.
                                if (!grafoListeAdiacenza.removeArco(nodoA, nodoB)){
                                    Util.printfn("\nArco non rimosso, era gia' assente!");
                                } else {
                                    Util.printfn("\nArco rimosso con successo!");
                                }

                                Util.continua();
                                break;
                            }

                            case 4:{

                                Util.printfn("\nHai scelto: Visualizza grafo...");

                                grafoListeAdiacenza.stampaNodi();
                                Util.printfn("");
                                grafoListeAdiacenza.stampaAdiacenze();

                                Util.continua();
                                break;
                            }

                            case 5:{

                                Util.printfn("\nHai scelto: Modifica nodi...");

                                Util.printfn("\nSelezionare nodo: ");

                                // Stampo i nodi.
                                grafoListeAdiacenza.stampaNodi();

                                // Scelta utente.
                                Util.printf("\nNumero scelta: ");
                                NodoLista nodoScelto = grafoListeAdiacenza.getNodoPos(Util.getScanner().nextInt());

                                // Se la scelta risulta nulla (non esiste).
                                if (nodoScelto == null){
                                    Util.printfn("\nOpzione non valida, per favore riprovare!");
                                    break;
                                }

                                // Scelta.
                                int sceltaModificaNodo;
                                do {

                                    // Legenda.
                                    Util.printf("\nOpzioni possibili sui nodi: " +
                                            "\n0 -> Esci." +
                                            "\n1 -> Modifica nome." +
                                            "\n2 -> Modifica difficolta'." +
                                            "\n3 -> Modifica altitudine." +
                                            "\n4 -> Visualizza nodo." +
                                            "\nScelta: ");
                                    // Prendo valore della scelta dell'utente inserito.
                                    sceltaModificaNodo = Util.getScanner().nextInt();

                                    // Opzioni.
                                    switch (sceltaModificaNodo){

                                        case 0:{

                                            // Messaggio azione.
                                            Util.printfn("\nHai scelto: Esci dalla modifica nodo...");

                                            break;
                                        }

                                        case 1:{

                                            // Messaggio d'inizio.
                                            Util.printfn("\nHai scelto: Modifica nome...");

                                            // Chiedo dati all'utente e setto.
                                            Util.printf("\nInserire il nuovo nome: ");
                                            nodoScelto.setNome(Util.getScanner().nextLine());

                                            // Fine con successo.
                                            Util.printfn("\nNome impostato con successo!");

                                            // Pausa.
                                            Util.continua();
                                            break;
                                        }

                                        case 2:{

                                            // Messaggio d'inizio.
                                            Util.printfn("\nHai scelto: Modifica difficolta'...");

                                            // Chiedo all'utente i dati e setto.
                                            Util.printf("\nInserire nuova difficolta', facendo riferimento alla tabella" +
                                                    "\nStandard a livelli dei percorsi." +
                                                    "\nDifficolta': ");
                                            nodoScelto.setDifficolta(Util.getScanner().nextInt());

                                            // Messaggio di fine.
                                            Util.printfn("\nDifficolta' impostata con successo!");

                                            // Pausa.
                                            Util.continua();
                                            break;
                                        }

                                        case 3:{

                                            // Messaggio d'inizio
                                            Util.printfn("\nHai scelto: Modifica altitudine...");

                                            // Chiedo dati all'utente e imposto.
                                            Util.printf("\nInserire nuova altitudine: ");
                                            nodoScelto.setAltitudine(Util.getScanner().nextInt());

                                            // Messaggio di fine.
                                            Util.printfn("\nAltitudine modificata con successo!");

                                            // Pausa.
                                            Util.continua();
                                            break;
                                        }

                                        case 4:{

                                            // Messaggio d'inizio.
                                            Util.printfn("\nHai scelto: Visualizza nodo...");

                                            // Comunico risultato all'utente.
                                            Util.printfn("\nInformazioni nodo: ");
                                            Util.printfn(nodoScelto.toString());

                                            // Pausa.
                                            Util.continua();
                                            break;
                                        }

                                        default:{

                                            // Messaggio opzione non valida.
                                            Util.printfn("\nOpzione non valida, per favore riprovare!");

                                            break;
                                        }
                                    }

                                } while (sceltaModificaNodo != 0);

                                break;
                            }

                            case 6:{

                                Util.printfn("\nHai scelto: Genera nodi casuali...");

                                // Chiedo dati all'utente.
                                int nNodi;
                                Util.printf("\nInserire il numero di nodi da generare: ");
                                nNodi = Util.getScanner().nextInt();

                                // Randomico e ripeto per n nodi scelto la generazione.
                                Random rand = new Random();
                                for (int i = 0; i < nNodi; i++){
                                    int nome = rand.nextInt(10000);
                                    int difficolta = rand.nextInt(9);
                                    int altitudine = rand.nextInt(4000);
                                    grafoListeAdiacenza.addNodo(new NodoLista("Punto " + nome, difficolta, altitudine));
                                }

                                // Messaggio di fine.
                                Util.printfn("\n" + nNodi + " Nodi casuali aggiunti con successo!" +
                                        "\nGenerazione archi casuali in corso...");

                                // Aggiungo archi casuali tra i nodi.
                                for (int i = 0; i < nNodi * nNodi / 1.7; i++){
                                    int nodoA;
                                    int nodoB;

                                    do {
                                        nodoA = rand.nextInt(nNodi);
                                        nodoB = rand.nextInt(nNodi);
                                    } while (grafoListeAdiacenza.adiacenti(nodoA, nodoB));

                                    if (!grafoListeAdiacenza.addArco(nodoA, nodoB)){
                                        Util.printfn("Errore nodoA " + nodoA + " NodoB " + nodoB +
                                                "\nPosizione non valida!");
                                    }
                                }

                                // Messaggio di successo.
                                Util.printf("\nAggiunti archi tra i nuovi Nodi con successo!");

                                Util.continua();
                                break;
                            }

                            case 7:{

                                Util.printfn("\nHai scelto: Verifica se presente percorso tra nodoA e nodoB...");

                                int nodoA;
                                int nodoB;
                                Util.printf("\nInserire nodo 1: ");
                                nodoA = Util.getScanner().nextInt();

                                Util.printfn("\nInserire nodo 2: ");
                                nodoB = Util.getScanner().nextInt();

                                if (grafoListeAdiacenza.isAdiacenti(nodoA, nodoB)){
                                    Util.printfn("I Nodi sono adiacenti.");
                                } else {
                                    Util.printfn("Non c'e' nessun percorso possibile tra i nodi.");
                                }

                                Util.continua();
                                break;
                            }

                            default:{

                                Util.printfn("\nScelta non valida, per favore riprovare!");
                                break;
                            }
                        }

                    } while (scelta2 != 0);


                    break;
                }

                default:{

                    // Messaggio opzione non valida.
                    Util.printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }
            }

        } while (scelta != 0);

        Util.printfn("\nUscito con successo!");
    }

    private static void matriceAdiacenze() {
        // Messaggio scelta.
        Util.printfn("\nHai scelto: Grafo a matrice...");

        // Inizializzo grafo.
        GrafoMatrice grafoMatrice = new GrafoMatrice();
        int opzione;

        // Carico il FILE se esistente e inizializzo il grafico.
        try {

            FileInputStream fi = new FileInputStream(new File("grafo.txt"));
            ObjectInputStream oi = new ObjectInputStream(fi);

            grafoMatrice = (GrafoMatrice) oi.readObject();

            oi.close();
            fi.close();

        } catch (FileNotFoundException e) {
            Util.printfn("File non trovato.");
        } catch (IOException e) {
            Util.printfn("Errore nel caricamento.");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        if (grafoMatrice == null){
            grafoMatrice = new GrafoMatrice();
        } else {
            Util.printfn("\nFile caricato con successo!");
        }

        do {

            // Legenda e scelta utente.
            Util.printf("\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Aggiungi nodo." +
                    "\n2 -> Aggiungi arco." +
                    "\n3 -> Rimuovi arco." +
                    "\n4 -> Visualizza." +
                    "\n5 -> Modifica nodi." +
                    "\n6 -> Aggiungi N nodi casuali." +
                    "\n7 -> Verifica presenza cammino tra nodo A e B." +
                    "\n8 -> Cammino tra nodo A e B." +
                    "\n9 -> Rimuovi nodo." +
                    "\n10 -> Visita BFS." +
                    "\n11 -> Visita DFS." +
                    "\nScelta: ");
            opzione = Util.getScanner().nextInt();

            // Opzioni.
            switch (opzione){

                case 0:{

                    // Messaggio d'inizio.
                    Util.printfn("\nUscita dal grafo...");

                    // Salvo sul disco il grafo in un file serializzato.
                    File file = new File("grafo.txt");
                    try {
                        if (file.createNewFile()){
                            Util.printfn("File creato " + file.getName());
                        } else {
                            Util.printfn("File gia' esistente.");
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                    try {
                        FileOutputStream f = new FileOutputStream(new File("grafo.txt"));
                        ObjectOutputStream o = new ObjectOutputStream(f);

                        o.writeObject(grafoMatrice);

                        o.close();
                        f.close();

                    } catch (FileNotFoundException e) {
                        System.out.println("File non trovato.");
                    } catch (IOException e) {
                        System.out.println("Errore nel salvataggio.");
                    }

                    break;
                }

                case 1:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Aggiungi nodo...");

                    // Inizializzo nuovo nodo.
                    Nodo nodo = new Nodo();

                    // Opzione.
                    int scelta2;
                    do {
                        Util.printf("\nInserire informazioni nodo o farne uno vuoto?" +
                                "\n0 -> Vuoto." +
                                "\n1 -> Avanzato." +
                                "\nScelta: ");
                        scelta2 = Util.getScanner().nextInt();
                        if (scelta2 != 0 && scelta2 != 1){
                            Util.printfn("\nScelta non valida, per favore riprovare...");
                        }
                    } while (scelta2 != 0 && scelta2 != 1);

                    // Se scelta 1 chiedo i dati.
                    if (scelta2 == 1){
                        Util.printf("\nInserire nome: ");
                        nodo.setNome(Util.getScanner().nextLine());
                        Util.printf("\nDifficolta':" +
                                "\nPiu' e' alto il valore, e maggiore e' il grado, es:" +
                                "\n1 -> T - Turistico." +
                                "\n2 -> E - Escursionistico." +
                                "\nEtc..." +
                                "\nDifficolta':");
                        nodo.setDifficolta(Util.getScanner().nextInt());

                        Util.printf("\nInserire altitudine: ");
                        nodo.setAltitudine(Util.getScanner().nextInt());
                    }

                    // Aggiungo il nodo al grafo.
                    grafoMatrice.addNodo(nodo);

                    // Messaggio di fine.
                    Util.printfn("\nNodo aggiunto con successo!");

                    Util.continua();
                    break;
                }

                case 2:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Aggiungi arco...");

                    // Stampo adiacenze e nodi.
                    grafoMatrice.stampaAdiacenze();
                    Util.printfn("\n");
                    grafoMatrice.stampaNodi();

                    // Chiedo all'utente conferma.
                    Util.printf("\n\nSei sicuro di voler aggiungere un arco? " +
                            "\n1 -> per confermare." +
                            "\n? -> Qualsiasi numero per annullare." +
                            "\nScelta: ");
                    // Se non conferma, fermo qui.
                    if (Util.getScanner().nextInt() != 1){
                        break;
                    }

                    // Chiedo dati all'utente dell'arco e lo aggiungo.
                    int peso;
                    Util.printf("\nInserire peso arco: ");
                    peso = Util.getScanner().nextInt();
                    Nodo nodo1;
                    Nodo nodo2;
                    do {
                        Util.printf("\nPosizione nodo 1: ");
                        nodo1 = grafoMatrice.getNodoPos(Util.getScanner().nextInt());
                        if (nodo1 == null) {
                            Util.printfn("\nPosizione nodo non valida!");
                        }
                    } while (nodo1 == null);

                    do {
                        Util.printf("\nPosizione nodo 2: ");
                        nodo2 = grafoMatrice.getNodoPos(Util.getScanner().nextInt());
                        if (nodo2 == null) {
                            Util.printfn("\nPosizione nodo non valida!");
                        }
                    } while (nodo2 == null);

                    if (!grafoMatrice.addArco(nodo1, nodo2, peso)){
                        Util.printfn("\nArco non aggiunto, era gia' presente.");
                    } else {
                        Util.printfn("\nArco aggiunto con successo!");
                    }

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 3:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Rimuovi arco...");

                    // Stampo matrice delle adiacenze e nodi.
                    grafoMatrice.stampaAdiacenze();
                    Util.printfn("");
                    grafoMatrice.stampaNodi();

                    // Chiedo conferma all'utente.
                    Util.printf("\n\nSei sicuro di voler rimuovere un arco? " +
                            "\n1 per confermare." +
                            "\nQualsiasi numero per annullare." +
                            "\nScelta: ");
                    // Se l'utente non conferma, mi fermo qui.
                    if (Util.getScanner().nextInt() != 1){
                        break;
                    }

                    // Chiedo all'utente che nodi voglia interessare e li carico.
                    Nodo nodo1;
                    Nodo nodo2;
                    do {
                        Util.printf("\nPosizione nodo 1: ");
                        nodo1 = grafoMatrice.getNodoPos(Util.getScanner().nextInt());
                        if (nodo1 == null) {
                            Util.printfn("\nPosizione nodo non valida!");
                        }
                    } while (nodo1 == null);

                    do {
                        Util.printf("\nPosizione nodo 2: ");
                        nodo2 = grafoMatrice.getNodoPos(Util.getScanner().nextInt());
                        if (nodo2 == null) {
                            Util.printfn("\nPosizione nodo non valida!");
                        }
                    } while (nodo2 == null);

                    // Rimuovo l'arco e in base all'esito comunico.
                    if (!grafoMatrice.rimuoviArco(nodo1, nodo2)){
                        Util.printfn("\nArco non rimosso, era gia' assente!");
                    } else {
                        Util.printfn("\nArco rimosso con successo!");
                    }

                    Util.continua();
                    break;
                }

                case 4:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Visualizza...");

                    // Stampo i nodi.
                    Util.printfn("\nNodi: ");
                    grafoMatrice.stampaNodi();

                    // Stampo la matrice.
                    Util.printf("\nMatrice delle adiacenze: ");
                    grafoMatrice.stampaAdiacenze();

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 5:{

                    // Messaggio d'inizio e chiedo all'utente che nodo voglia interessare.
                    Util.printfn("\nHai scelto: Modifica nodi...");
                    Util.printfn("\nSelezionare nodo: ");

                    // Stampo i nodi.
                    grafoMatrice.stampaNodi();

                    // Scelta utente.
                    Util.printf("\nNumero scelta: ");
                    Nodo nodoScelto = grafoMatrice.getNodoPos(Util.getScanner().nextInt());

                    // Se la scelta risulta nulla (non esiste).
                    if (nodoScelto == null){
                        Util.printfn("\nOpzione non valida, per favore riprovare!");
                        break;
                    }

                    // Scelta.
                    int sceltaModificaNodo;
                    do {

                        // Legenda.
                        Util.printf("\nOpzioni possibili sui nodi: " +
                                "\n0 -> Esci." +
                                "\n1 -> Modifica nome." +
                                "\n2 -> Modifica difficolta'." +
                                "\n3 -> Modifica altitudine." +
                                "\n4 -> Visualizza nodo." +
                                "\nScelta: ");
                        // Prendo valore della scelta dell'utente inserito.
                        sceltaModificaNodo = Util.getScanner().nextInt();

                        // Opzioni.
                        switch (sceltaModificaNodo){

                            case 0:{

                                // Messaggio azione.
                                Util.printfn("\nHai scelto: Esci dalla modifica nodo...");

                                break;
                            }

                            case 1:{

                                // Messaggio d'inizio.
                                Util.printfn("\nHai scelto: Modifica nome...");

                                // Chiedo dati all'utente e setto.
                                Util.printf("\nInserire il nuovo nome: ");
                                nodoScelto.setNome(Util.getScanner().nextLine());

                                // Fine con successo.
                                Util.printfn("\nNome impostato con successo!");

                                // Pausa.
                                Util.continua();
                                break;
                            }

                            case 2:{

                                // Messaggio d'inizio.
                                Util.printfn("\nHai scelto: Modifica difficolta'...");

                                // Chiedo all'utente i dati e setto.
                                Util.printf("\nInserire nuova difficolta', facendo riferimento alla tabella" +
                                        "\nStandard a livelli dei percorsi." +
                                        "\nDifficolta': ");
                                nodoScelto.setDifficolta(Util.getScanner().nextInt());

                                // Messaggio di fine.
                                Util.printfn("\nDifficolta' impostata con successo!");

                                // Pausa.
                                Util.continua();
                                break;
                            }

                            case 3:{

                                // Messaggio d'inizio
                                Util.printfn("\nHai scelto: Modifica altitudine...");

                                // Chiedo dati all'utente e imposto.
                                Util.printf("\nInserire nuova altitudine: ");
                                nodoScelto.setAltitudine(Util.getScanner().nextInt());

                                // Messaggio di fine.
                                Util.printfn("\nAltitudine modificata con successo!");

                                // Pausa.
                                Util.continua();
                                break;
                            }

                            case 4:{

                                // Messaggio d'inizio.
                                Util.printfn("\nHai scelto: Visualizza nodo...");

                                // Comunico risultato all'utente.
                                Util.printfn("\nInformazioni nodo: ");
                                Util.printfn(nodoScelto.toString());

                                // Pausa.
                                Util.continua();
                                break;
                            }

                            default:{

                                // Messaggio opzione non valida.
                                Util.printfn("\nOpzione non valida, per favore riprovare!");

                                break;
                            }
                        }

                    } while (sceltaModificaNodo != 0);

                    break;
                }

                case 6:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Genera N nodi casuali...");

                    // Chiedo dati all'utente.
                    int nNodi;
                    Util.printf("\nInserire il numero di nodi da generare: ");
                    nNodi = Util.getScanner().nextInt();

                    // Randomico e ripeto per n nodi scelto la generazione.
                    Random rand = new Random();
                    for (int i = 0; i < nNodi; i++){
                        int nome = rand.nextInt(10000);
                        int difficolta = rand.nextInt(9);
                        int altitudine = rand.nextInt(4000);
                        grafoMatrice.addNodo(new Nodo("Punto " + nome, difficolta, altitudine));
                    }

                    // Messaggio di fine.
                    Util.printfn("\n" + nNodi + " Nodi casuali aggiunti con successo!" +
                            "\nGenerazione archi casuali in corso...");

                    // Aggiungo archi casuali tra i nodi.
                    for (int i = 0; i < nNodi * nNodi / 1.7; i++){
                        int nodoA;
                        int nodoB;

                        do {
                            nodoA = rand.nextInt(nNodi);
                            nodoB = rand.nextInt(nNodi);
                        } while (grafoMatrice.getPesoPos(nodoA, nodoB) != 0);

                        if (!grafoMatrice.addArco(nodoA, nodoB, rand.nextInt(61))){
                            Util.printfn("Errore nodoA " + nodoA + " NodoB " + nodoB +
                                    "\nPosizione non valida!");
                        }
                    }

                    // Messaggio di successo.
                    Util.printf("\nAggiunti archi tra i nuovi Nodi con successo!");

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 7:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Verifica presenza percorso tra A e B...");

                    // Stampo nodi.
                    grafoMatrice.stampaNodi();

                    // Chiedo dati all'utente.
                    int nodoA;
                    int nodoB;
                    Util.printf("\nScegli il nodo di partenza: ");
                    nodoA = Util.getScanner().nextInt();

                    Util.printf("\nScegli il nodo di destinazione: ");
                    nodoB = Util.getScanner().nextInt();

                    // In base al risultato, stampo un messaggio.
                    if (grafoMatrice.isAdiacente(nodoA, nodoB)){
                        Util.printfn("\nTrovato percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                    } else {
                        Util.printfn("\nNon e' stato trovato nessun percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                    }

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 8:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Percorso tra nodo A e B...");

                    // Stampo i nodi.
                    grafoMatrice.stampaNodi();

                    // Chiedo dati all'utente.
                    int nodoA;
                    int nodoB;
                    Util.printf("\nScegli il nodo di partenza: ");
                    nodoA = Util.getScanner().nextInt();

                    Util.printf("\nScegli il nodo di destinazione: ");
                    nodoB = Util.getScanner().nextInt();

                    // In base al risultato, invio un messaggio.
                    if (grafoMatrice.isAdiacente(nodoA, nodoB)){
                        Util.printfn("\nTrovato percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                    } else {
                        Util.printfn("\nNon e' stato trovato nessun percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                    }

                    // Stampo il percorso se maggiore di 0 la sua lunghezza.
                    List<Integer> percorso = grafoMatrice.percorso(nodoA, nodoB);
                    if (percorso == null || percorso.size() == 0){
                        Util.printfn("Nessun percorso trovato!");
                    } else {
                        for (int n : percorso) {
                            Util.printf("[" + n + "] ");
                        }
                    }

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 9:{

                    // Messaggio d'inizio.
                    Util.printfn("Hai scelto: Rimuovi nodo...");

                    // Stampo i nodi.
                    grafoMatrice.stampaNodi();

                    // Chiedo dati all'utente.
                    int nNodo;
                    Util.printf("\nNodo scelto: ");
                    nNodo = Util.getScanner().nextInt();

                    // In base al risultato dell'azione, comunico all'utente l'esito.
                    if (grafoMatrice.rimuoviNodo(nNodo)){
                        Util.printfn("\nRimosso nodo con successo!");
                    } else {
                        Util.printfn("\nNodo non rimosso, forse ne hai selezionato uno non valido.");
                    }

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 10: {

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Visita BFS...");

                    // Stampo i nodi.
                    grafoMatrice.stampaNodi();

                    // Chiedo dati all'utente.
                    int nodoA;
                    Util.printf("\nScegliere nodo di partenza: ");
                    nodoA = Util.getScanner().nextInt();

                    Util.printfn("\nInizio visita GFS:");

                    // Eseguo.
                    grafoMatrice.visitaBFS(nodoA);

                    // Pausa.
                    Util.continua();
                    break;
                }

                case 11:{

                    // Messaggio d'inizio.
                    Util.printfn("\nHai scelto: Visita DFS...");

                    // Stampo i nodi.
                    grafoMatrice.stampaNodi();

                    // Chiedo dati all'utente.
                    int nodoA;
                    Util.printf("\nScegliere nodo di partenza: ");
                    nodoA = Util.getScanner().nextInt();

                    Util.printfn("\nInizio visita GFS:");

                    // Eseguo.
                    grafoMatrice.visitaDFS(nodoA);

                    // Pausa.
                    Util.continua();
                    break;
                }

                default:{

                    // Messaggio opzione non valida.
                    Util.printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }
            }

        } while (opzione != 0);
    }

    // Utility per generare un numero casuale in un range dato.
    public static int randomInRange(int min, int max) {
        Random random = new Random();
        return random.nextInt(max - min) + min;
    }
}