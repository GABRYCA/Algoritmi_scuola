package me.gca;

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

                    do {

                        Util.printf("\nOpzioni:" +
                                "\n0 -> Esci." +
                                "\n1 -> Aggiungi nodo." +
                                "\n2 -> Aggiungi arco." +
                                "\n3 -> Rimuovi arco." +
                                "\n4 -> Visualizza." +
                                "\nScelta: ");
                        opzione = Util.getScanner().nextInt();

                        switch (opzione){

                            case 0:{

                                Util.printfn("\nUscita dal grafo...");

                                break;
                            }

                            case 1:{

                                Util.printfn("\nHai scelto: Aggiungi nodo...");

                                Nodo nodo = new Nodo();

                                grafoMatrice.addNodo(nodo);

                                Util.printfn("\nNodo aggiunto con successo!");

                                Util.continua();
                                break;
                            }

                            case 2:{

                                Util.printfn("\nHai scelto: Aggiungi arco...");

                                grafoMatrice.stampaAdiacenze();
                                grafoMatrice.stampaNodi();

                                Util.printf("\n\nSei sicuro di voler aggiungere un arco? " +
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

                                if (!grafoMatrice.addArco(nodo1, nodo2)){
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
