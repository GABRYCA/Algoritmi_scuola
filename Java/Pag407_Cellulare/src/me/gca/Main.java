package me.gca;

public class Main extends Util{

    public static void main(String[] args) {

        printfn("/////////////////////////////////////////" +
                "\nGerarchia Elettrodomestici di G.C. 4BITI" +
                "\n/////////////////////////////////////////");

        int sceltaDispositivo;

        do {

            printf("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Cellulare." +
                    "\n2 -> Computer." +
                    "\nScelta: ");
            sceltaDispositivo = getScanner().nextInt();

            switch (sceltaDispositivo){

                case 0:{

                    printfn("\nHai scelto: Esci..." +
                            "\n\nUscita in corso...");

                    break;
                }

                case 1:{

                    printfn("\nHai scelto: Cellulari...");

                    cellulari();

                    break;
                }

                case 2:{

                    printfn("\nHai scelto: Computer...");

                    computer();

                    break;
                }

                default:{

                    printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }

            }

        } while (sceltaDispositivo != 0);

        printfn("\n\nUscito con successo!");
    }

    private static void cellulari() {
        int nCellulari = 3;
        SistemaOSCellulare[] cellulari = new SistemaOSCellulare[nCellulari];
        cellulari[0] = new SistemaOSCellulare("TELEFONO", "Mi 9T Pro", "Xiaomi", 399, "SNAPDRAGON 855", 8, 128, 8, "Android", "12.0");

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

                    SistemaOSCellulare tempCell = new SistemaOSCellulare();

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

                    printfn("\nInserire la versione del sistema operativo del cellulare: ");
                    tempCell.setVersione(getScanner().next());

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

                    boolean eliminato = false;
                    for (int i = 0; i < nCellulari; i++){
                        if (cellulari[i] != null){
                            if (cellulari[i].getNome().equalsIgnoreCase(nome)){
                                cellulari[i] = null;
                                eliminato = true;
                                break;
                            }
                        }
                    }

                    if (eliminato) {
                        printfn("\nCellulare '" + nome + "' rimosso con successo!");
                    } else {
                        printfn("\nDispositivo con quel nome non trovato!");
                    }
                    continua();
                    break;
                }

                default:{

                    printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }

            }

        } while (scelta != 0);
    }

    private static void computer() {
        int nComputer = 3;
        SistemaOSComputer[] computers = new SistemaOSComputer[nComputer];
        computers[0] = new SistemaOSComputer("COMPUTER", "Acer Nitro 5", "Acer", 1099, "Intel Core i7-10750H", 6, 512, 8, "Windows", "10", 15.6, "Nvidia RTX 3060");

        int scelta;
        do {

            printf("\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Vedi tutti i computer." +
                    "\n2 -> Aggiungi computer." +
                    "\n3 -> Rimuovi computer." +
                    "\nScelta: ");
            scelta = getScanner().nextInt();

            switch (scelta){

                case 0:{

                    printfn("\nHai scelto: Esci..." +
                            "\n\nUscita in corso...");

                    break;
                }

                case 1:{

                    printfn("\nHai scelto: Informazioni computers...");

                    int conta = 1;
                    for (int i = 0; i < nComputer; i++){
                        if (computers[i] != null){
                            printf("\nComputer " + conta + ":");
                            computers[i].stampa();
                            printfn("\n-------------");
                            conta++;
                        }
                    }

                    if (conta == 1){
                        printfn("\nNessun computer disponibile!");
                    }

                    continua();
                    break;
                }

                case 2:{

                    printfn("\nHai scelto: Aggiungi Computer...");

                    int conta = 0;
                    int spazioVuoto = -1;
                    for (int i = 0; i < nComputer; i++){
                        if (computers[i] != null){
                            conta++;
                        } else {
                            spazioVuoto = i;
                        }
                    }

                    if (conta == nComputer || spazioVuoto == -1){
                        printfn("\nNon è possibile aggiungere computers, il limite interno massimo supportato è " + nComputer + "." +
                                "\nPuoi aumentare il valore da codice, il nome della variabile è 'int nComputer'.");
                        break;
                    }

                    SistemaOSComputer tempComputer = new SistemaOSComputer();

                    tempComputer.setTipo("COMPUTER");

                    printfn("\nInserire il nome del computer: ");
                    tempComputer.setNome(getScanner().nextLine());

                    printf("\nInserire la marca del computer: ");
                    tempComputer.setMarca(getScanner().next());

                    printf("\nInserire il prezzo del computer: ");
                    tempComputer.setPrezzo(getScanner().nextDouble());

                    printfn("\nInserire il nome del processore del computer: ");
                    tempComputer.setProcessore(getScanner().nextLine());

                    printf("\nInserire il nome del sistema operativo del computer: ");
                    tempComputer.setSistema_operativo(getScanner().next());

                    printfn("\nInserire la versione del sistema operativo del computer: ");
                    tempComputer.setVersione(getScanner().next());

                    printf("\nInserire il numero di core del computer: ");
                    tempComputer.setNumero_core(getScanner().nextInt());

                    printf("\nInserire numero GB interni del computer: ");
                    tempComputer.setMemoria_interna_GB(getScanner().nextFloat());

                    printf("\nInserire il numero di GB di RAM del computer: ");
                    tempComputer.setRAM_GB(getScanner().nextFloat());

                    printfn("\nInserire le dimensioni dello schermo del computer: ");
                    tempComputer.setDimensione_schermo(getScanner().nextFloat());

                    printfn("\nInserire la scheda video del computer: ");
                    tempComputer.setScheda_video(getScanner().next());

                    computers[spazioVuoto] = tempComputer;

                    printfn("\nAggiunto con successo cellulare, informazioni: ");
                    computers[spazioVuoto].stampa();

                    continua();
                    break;
                }

                case 3:{

                    printfn("\nHai scelto: Rimuovi computer...");

                    int conta = 0;
                    for (int i = 0; i < nComputer; i++){
                        if (computers[i] != null){
                            conta++;
                        }
                    }

                    if (conta == nComputer){
                        printfn("\nNon è possibile rimuovere computer, non ne sono disponibili!");
                        break;
                    }

                    conta = 0;
                    for (int i = 0; i < nComputer; i++){
                        if (computers[i] != null){
                            printfn("\nComputer " + conta + ":" +
                                    "\nNome: " + computers[i].getNome());
                        }
                    }

                    printfn("\nInserire il nome del computer da rimuovere: ");
                    String nome = getScanner().nextLine();

                    boolean eliminato = false;
                    for (int i = 0; i < nComputer; i++){
                        if (computers[i] != null){
                            if (computers[i].getNome().equalsIgnoreCase(nome)){
                                computers[i] = null;
                                eliminato = true;
                                break;
                            }
                        }
                    }

                    if (eliminato) {
                        printfn("\nComputer '" + nome + "' rimosso con successo!");
                    } else {
                        printfn("\nUn dispositivo con quel nome non è stato trovato!");
                    }
                    continua();
                    break;
                }

                default:{

                    printfn("\nOpzione non valida, per favore riprovare!");

                    break;
                }

            }

        } while (scelta != 0);
    }
}
