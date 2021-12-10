package me.gca;

public class Main extends Util{

    public static void main(String[] args) {

        printfn("/////////////////////////////////////////" +
                "\n   Gerarchia Cellulare di G.C. 4BITI" +
                "\n/////////////////////////////////////////");

        int nCellulari = 3;
        Cellulari[] cellulari = new Cellulari[nCellulari];
        cellulari[0] = new Cellulari("TELEFONO", "Mi 9T Pro", "Xiaomi", 399, "SNAPDRAGON 855", "Android", 8, 128, 8);

        int scelta;
        do {

            printf("\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Vedi tutti i telefoni." +
                    "\n2 -> Aggiungi telefono." +
                    "\n3 -> Rimuovi telefono." +
                    "\nScelta: ");
            scelta = getScanner().nextInt();

            switch (scelta){

                case 0:{

                    printfn("\nHai scelto: Esci..." +
                            "\n\nUscita in corso...");

                    break;
                }

                case 1:{

                    printfn("\nHai scelto: Informazioni cellulari...");

                    int conta = 1;
                    for (int i = 0; i < nCellulari; i++){
                        if (cellulari[i] != null){
                            printf("\nCellulare " + conta + ":");
                            cellulari[i].stampa();
                            printfn("\n-------------");
                            conta++;
                        }
                    }

                    if (conta == 1){
                        printfn("\nNessun cellulare disponibile!");
                    }

                    continua();
                    break;
                }

                case 2:{

                    printfn("\nHai scelto: Aggiungi telefono...");

                    int conta = 0;
                    int spazioVuoto = -1;
                    for (int i = 0; i < nCellulari; i++){
                        if (cellulari[i] != null){
                            conta++;
                        } else {
                            spazioVuoto = i;
                        }
                    }

                    if (conta == nCellulari || spazioVuoto == -1){
                        printfn("\nNon è possibile aggiungere cellulari, il limite interno massimo supportato è " + nCellulari + "." +
                                "\nPuoi aumentare il valore da codice, il nome della variabile è 'int nCellulari'.");
                        break;
                    }

                    Cellulari tempCell = new Cellulari();

                    tempCell.setTipo("TELEFONO");

                    printfn("\nInserire il nome del cellulare: ");
                    tempCell.setNome(getScanner().nextLine());

                    printf("\nInserire la marca del cellulare: ");
                    tempCell.setMarca(getScanner().next());

                    printf("\nInserire il prezzo del cellulare: ");
                    tempCell.setPrezzo(getScanner().nextDouble());

                    printfn("\nInserire il nome del processore del cellulare: ");
                    tempCell.setProcessore(getScanner().nextLine());

                    printf("\nInserire il nome del sistema operativo del cellulare: ");
                    tempCell.setSistema_operativo(getScanner().next());

                    printf("\nInserire il numero di core del cellulare: ");
                    tempCell.setNumero_core(getScanner().nextInt());

                    printf("\nInserire numero GB interni del cellulare: ");
                    tempCell.setMemoria_interna_GB(getScanner().nextFloat());

                    printf("\nInserire il numero di GB di RAM del cellulare: ");
                    tempCell.setRAM_GB(getScanner().nextFloat());

                    cellulari[spazioVuoto] = tempCell;

                    printfn("\nAggiunto con successo cellulare, informazioni: ");
                    cellulari[spazioVuoto].stampa();

                    continua();
                    break;
                }

                case 3:{

                    printfn("\nHai scelto: Rimuovi cellulare...");

                    int conta = 0;
                    for (int i = 0; i < nCellulari; i++){
                        if (cellulari[i] != null){
                            conta++;
                        }
                    }

                    if (conta == nCellulari){
                        printfn("\nNon è possibile rimuovere cellulari, non ne sono disponibili!");
                        break;
                    }

                    conta = 0;
                    for (int i = 0; i < nCellulari; i++){
                        if (cellulari[i] != null){
                            printfn("\nCellulare " + conta + ":" +
                                    "\nNome: " + cellulari[i].getNome());
                        }
                    }

                    printfn("\nInserire il nome del cellulare da rimuovere: ");
                    String nome = getScanner().nextLine();

                    int posizioneDaEliminare = -1;
                    for (int i = 0; i < nCellulari; i++){
                        if (cellulari[i] != null){
                            if (cellulari[i].getNome().equalsIgnoreCase(nome)){
                                cellulari[i] = null;
                                break;
                            }
                        }
                    }

                    printfn("\nCellulare '" + nome + "' rimosso con successo!");
                    continua();
                    break;
                }

                default:{

                    printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }

            }

        } while (scelta != 0);

        printfn("\n\nUscito con successo!");
    }
}
