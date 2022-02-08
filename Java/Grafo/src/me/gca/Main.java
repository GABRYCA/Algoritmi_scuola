package me.gca;

import java.io.*;

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
                    }

                    do {

                        Util.printf("\nOpzioni:" +
                                "\n0 -> Esci." +
                                "\n1 -> Aggiungi nodo." +
                                "\n2 -> Aggiungi arco." +
                                "\n3 -> Rimuovi arco." +
                                "\n4 -> Visualizza." +
                                "\n5 -> Modifica nodi." +
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
                                    nodo.setNome(Util.getScanner().next());
                                    Util.printfn("\nDifficolta':" +
                                            "\nPiu' e' alto il valore, e maggiore e' il grado, es:" +
                                            "\n1 -> T - Turistico." +
                                            "\n2 -> E - Escursionistico." +
                                            "\nEtc..." +
                                            "\nDifficolta':");
                                    nodo.setDifficolta(Util.getScanner().nextInt());
                                }

                                grafoMatrice.addNodo(nodo);

                                Util.printfn("\nNodo aggiunto con successo!");

                                Util.continua();
                                break;
                            }

                            case 2:{

                                Util.printfn("\nHai scelto: Aggiungi arco...");

                                grafoMatrice.stampaAdiacenze();
                                Util.printfn("");
                                grafoMatrice.stampaNodi();

                                Util.printf("\n\nSei sicuro di voler aggiungere un arco? " +
                                        "\n1 -> per confermare." +
                                        "\n -> Qualsiasi numero per annullare." +
                                        "\nScelta: ");
                                if (Util.getScanner().nextInt() != 1){
                                    break;
                                }
                                int peso;
                                Util.printfn("\nInserire peso arco: ");
                                peso = Util.getScanner().nextInt();
                                Nodo nodo1;
                                Nodo nodo2;
                                do {
                                    Util.printfn("\nPosizione nodo 1: ");
                                    nodo1 = grafoMatrice.getNodoPos(Util.getScanner().nextInt());
                                    if (nodo1 == null) {
                                        Util.printfn("\nPosizione nodo non valida!");
                                    }
                                } while (nodo1 == null);

                                do {
                                    Util.printfn("\nPosizione nodo 2: ");
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
                                    Util.printfn("\nPosizione nodo 1: ");
                                    nodo1 = grafoMatrice.getNodoPos(Util.getScanner().nextInt());
                                    if (nodo1 == null) {
                                        Util.printfn("\nPosizione nodo non valida!");
                                    }
                                } while (nodo1 == null);

                                do {
                                    Util.printfn("\nPosizione nodo 2: ");
                                    nodo2 = grafoMatrice.getNodoPos(Util.getScanner().nextInt());
                                    if (nodo2 == null) {
                                        Util.printfn("\nPosizione nodo non valida!");
                                    }
                                } while (nodo2 == null);

                                if (!grafoMatrice.rimuoviArco(nodo1, nodo2)){
                                    Util.printfn("\nArco non rimosso, era gia' assente.!");
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
                                Util.printf("\nSelezionare nodo: ");

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
                                            "\n2 -> Modifica difficolta'.");

                                    sceltaModificaNodo = Util.getScanner().nextInt();

                                    switch (sceltaModificaNodo){

                                        case 0:{

                                            Util.printfn("\nHai scelto: Esci dalla modifica nodo...");

                                            break;
                                        }

                                        case 1:{

                                            Util.printfn("\nHai scelto: Modifica nome...");

                                            Util.printf("\nInserire il nuovo nome: ");
                                            nodoScelto.setNome(Util.getScanner().next());

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

                                        default:{

                                            Util.printfn("\nOpzione non valida, per favore riprovare!");

                                            break;
                                        }
                                    }

                                } while (sceltaModificaNodo != 0);

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

        Util.printfn("\nUsito con successo!");
    }
}
