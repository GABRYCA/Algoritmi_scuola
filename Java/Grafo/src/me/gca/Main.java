package me.gca;

import java.io.*;
import java.util.Random;

public class Main {

    public static void main(String[] args) {

        Util.printfn("/////////////////////////////////////" +
                   "\n         Grafo G.C. 4BITI" +
                   "\n/////////////////////////////////////");



        int scelta;
        do {
            Util.printf("\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Grafo a matrice." +
                    "\n2 -> Grafo a liste delle adiacenze." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta){

                case 0:{

                    Util.printfn("\nHai scelto: Esci..." +
                            "\nUscita in corso...");

                    break;
                }

                case 1:{

                    Util.printfn("\nHai scelto: Grafo a matrice...");

                    GrafoMatrice grafoMatrice = new GrafoMatrice();
                    int opzione;

                    try {

                        FileInputStream fi = new FileInputStream(new File("grafo.txt"));
                        ObjectInputStream oi = new ObjectInputStream(fi);

                        grafoMatrice = (GrafoMatrice) oi.readObject();

                        oi.close();
                        fi.close();

                    } catch (FileNotFoundException e) {
                        System.out.println("File non trovato.");
                    } catch (IOException e) {
                        System.out.println("Errore nel caricamento.");
                    } catch (ClassNotFoundException e) {
                        e.printStackTrace();
                    }

                    if (grafoMatrice == null){
                        grafoMatrice = new GrafoMatrice();
                    } else {
                        Util.printfn("\nFile caricato con successo!");
                    }

                    do {

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
                                "\nScelta: ");
                        opzione = Util.getScanner().nextInt();

                        switch (opzione){

                            case 0:{

                                Util.printfn("\nUscita dal grafo...");

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

                                Util.printfn("\nHai scelto: Aggiungi nodo...");

                                Nodo nodo = new Nodo();

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

                                grafoMatrice.addNodo(nodo);

                                Util.printfn("\nNodo aggiunto con successo!");

                                Util.continua();
                                break;
                            }

                            case 2:{

                                Util.printfn("\nHai scelto: Aggiungi arco...");

                                grafoMatrice.stampaAdiacenze();
                                Util.printfn("\n");
                                grafoMatrice.stampaNodi();

                                Util.printf("\n\nSei sicuro di voler aggiungere un arco? " +
                                        "\n1 -> per confermare." +
                                        "\n? -> Qualsiasi numero per annullare." +
                                        "\nScelta: ");
                                if (Util.getScanner().nextInt() != 1){
                                    break;
                                }
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

                                Util.continua();
                                break;
                            }

                            case 3:{

                                Util.printfn("\nHai scelto: Rimuovi arco...");

                                grafoMatrice.stampaAdiacenze();
                                Util.printfn("");
                                grafoMatrice.stampaNodi();

                                Util.printf("\n\nSei sicuro di voler rimuovere un arco? " +
                                        "\n1 per confermare." +
                                        "\nQualsiasi numero per annullare." +
                                        "\nScelta: ");
                                if (Util.getScanner().nextInt() != 1){
                                    break;
                                }
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

                                if (!grafoMatrice.rimuoviArco(nodo1, nodo2)){
                                    Util.printfn("\nArco non rimosso, era gia' assente!");
                                } else {
                                    Util.printfn("\nArco rimosso con successo!");
                                }

                                Util.continua();
                                break;
                            }

                            case 4:{

                                Util.printfn("\nHai scelto: Visualizza...");

                                Util.printfn("\nNodi: ");
                                grafoMatrice.stampaNodi();

                                Util.printf("\nMatrice delle adiacenze: ");
                                grafoMatrice.stampaAdiacenze();

                                Util.continua();
                                break;
                            }

                            case 5:{

                                Util.printfn("\nHai scelto: Modifica nodi...");
                                Util.printfn("\nSelezionare nodo: ");

                                grafoMatrice.stampaNodi();

                                Util.printf("\nNumero scelta: ");
                                Nodo nodoScelto = grafoMatrice.getNodoPos(Util.getScanner().nextInt());

                                if (nodoScelto == null){
                                    Util.printfn("\nOpzione non valida, per favore riprovare!");
                                    break;
                                }

                                int sceltaModificaNodo;
                                do {

                                    Util.printf("\nOpzioni possibili sui nodi: " +
                                            "\n0 -> Esci." +
                                            "\n1 -> Modifica nome." +
                                            "\n2 -> Modifica difficolta'." +
                                            "\n3 -> Modifica altitudine." +
                                            "\n4 -> Visualizza nodo." +
                                            "\nScelta: ");

                                    sceltaModificaNodo = Util.getScanner().nextInt();

                                    switch (sceltaModificaNodo){

                                        case 0:{

                                            Util.printfn("\nHai scelto: Esci dalla modifica nodo...");

                                            break;
                                        }

                                        case 1:{

                                            Util.printfn("\nHai scelto: Modifica nome...");

                                            Util.printf("\nInserire il nuovo nome: ");
                                            nodoScelto.setNome(Util.getScanner().nextLine());

                                            Util.printfn("\nNome impostato con successo!");

                                            Util.continua();
                                            break;
                                        }

                                        case 2:{

                                            Util.printfn("\nHai scelto: Modifica difficolta'...");

                                            Util.printf("\nInserire nuova difficolta', facendo riferimento alla tabella" +
                                                    "\nStandard a livelli dei percorsi." +
                                                    "\nDifficolta': ");
                                            nodoScelto.setDifficolta(Util.getScanner().nextInt());

                                            Util.printfn("\nDifficolta' impostata con successo!");

                                            Util.continua();
                                            break;
                                        }

                                        case 3:{

                                            Util.printfn("\nHai scelto: Modifica altitudine...");

                                            Util.printf("\nInserire nuova altitudine: ");
                                            nodoScelto.setAltitudine(Util.getScanner().nextInt());

                                            Util.printfn("\nAltitudine modificata con successo!");

                                            Util.continua();
                                            break;
                                        }

                                        case 4:{

                                            Util.printfn("\nHai scelto: Visualizza nodo...");

                                            Util.printfn("\nInformazioni nodo: ");
                                            Util.printfn(nodoScelto.toString());

                                            Util.continua();
                                            break;
                                        }

                                        default:{

                                            Util.printfn("\nOpzione non valida, per favore riprovare!");

                                            break;
                                        }
                                    }

                                } while (sceltaModificaNodo != 0);

                                break;
                            }

                            case 6:{

                                Util.printfn("\nHai scelto: Genera N nodi casuali...");

                                int nNodiVecchio = grafoMatrice.numeroNodi();
                                int nNodi;
                                Util.printf("\nInserire il numero di nodi da generare: ");
                                nNodi = Util.getScanner().nextInt();

                                Random rand = new Random();
                                for (int i = 0; i < nNodi; i++){
                                    int nome = rand.nextInt(10000);
                                    int difficolta = rand.nextInt(9);
                                    int altitudine = rand.nextInt(4000);
                                    grafoMatrice.addNodo(new Nodo("Punto " + Integer.toString(nome), difficolta, altitudine));
                                }

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

                                Util.printf("\nAggiunti archi tra i nuovi Nodi con successo!");

                                Util.continua();
                                break;
                            }

                            case 7:{

                                Util.printfn("\nHai scelto: Verifica presenza percorso tra A e B...");

                                grafoMatrice.stampaNodi();

                                int nodoA;
                                int nodoB;
                                Util.printf("\nScegli il nodo di partenza: ");
                                nodoA = Util.getScanner().nextInt();

                                Util.printf("\nScegli il nodo di destinazione: ");
                                nodoB = Util.getScanner().nextInt();

                                if (grafoMatrice.isAdiacente(nodoA, nodoB)){
                                    Util.printfn("\nTrovato percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                                } else {
                                    Util.printfn("\nNon e' stato trovato nessun percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                                }

                                Util.continua();
                                break;
                            }

                            case 8:{

                                Util.printfn("\nHai scelto: Percorso tra nodo A e B...");

                                grafoMatrice.stampaNodi();

                                int nodoA;
                                int nodoB;
                                Util.printf("\nScegli il nodo di partenza: ");
                                nodoA = Util.getScanner().nextInt();

                                Util.printf("\nScegli il nodo di destinazione: ");
                                nodoB = Util.getScanner().nextInt();

                                if (grafoMatrice.isAdiacente(nodoA, nodoB)){
                                    Util.printfn("\nTrovato percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                                } else {
                                    Util.printfn("\nNon e' stato trovato nessun percorso tra il Nodo " + nodoA + " e Nodo " + nodoB);
                                }

                                for (int n : grafoMatrice.percorso(nodoA, nodoB)){
                                    Util.printf(n + " ");
                                }

                                Util.continua();
                                break;
                            }

                            default:{

                                Util.printfn("\nOpzione non valida, per favore riprovare!");

                                break;
                            }
                        }

                    } while (opzione != 0);

                    break;
                }

                case 2:{

                    Util.printfn("\nHai scelto: Grafo con liste delle adiacenze...");

                    break;
                }

                default:{

                    Util.printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }
            }

        } while (scelta != 0);

        Util.printfn("\nUscito con successo!");
    }

    public static int randomInRange(int min, int max) {
        Random random = new Random();
        return random.nextInt(max - min) + min;
    }
}