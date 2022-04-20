package me.gca;

import java.util.*;

public class Main {

    static int contatore;

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("\n/////////////////////////////////////" +
                "\n// Compito Pag.540 di G.C. 4BITI //" +
                "\n/////////////////////////////////////");

        int scelta;
        do {

            FileManager fileManager = new FileManager();

            Util.printf("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Simulazione." +
                    "\n2 -> Configurazione." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta){

                case 0:{

                    Util.printfn("\nUscita in corso...");
                    fileManager.salvaFile();

                    break;
                }

                case 1:{

                    Util.printfn("\nHai scelto: Programma 1, casse...");

                    fileManager = new FileManager(); // Reload del file.
                    List<Cassa> casse = fileManager.getCasse();

                    //Stampa info di ogni cassa
                    for (Cassa cassa : casse) {
                        Util.printfn("\n" + cassa.toString() + "\n");
                    }

                    int etaMassima = 100;
                    int etaMinima = 15;
                    final int[] secondo = {1};
                    // Modalita', 0 mattina-pomeriggio, 1 notte, 2 orario di punta.
                    int orario;
                    Util.printf("\nIn che modalità eseguire il programma?" +
                            "\n0 -> Mattina-Pomeriggio." +
                            "\n1 -> Notte." +
                            "\n2 -> Orario di punta." +
                            "\nScelta: ");
                    orario = Util.getScanner().nextInt();

                    int nPersone;
                    Util.printf("\nQuante persone vuoi accodare: ");
                    nPersone = Util.getScanner().nextInt();

                    int velocita;
                    do {
                        Util.printf("\nScegli: " +
                                "\n0 -> Velocità lenta (1 persona al secondo)." +
                                "\n1 -> Istantaneo." +
                                "\nScelta: ");
                        velocita = Util.getScanner().nextInt();
                        if (velocita != 0 && velocita != 1) {
                            Util.printfn("\nScelta non valida.\n");
                        }
                    } while (velocita != 0 && velocita != 1);

                    int periodo = 1;
                    if (velocita == 0) {
                        periodo = 1000;
                    }

                    contatore = 0;
                    Timer timer = new Timer();
                    TimerTask task = null;
                    timer.scheduleAtFixedRate(task = new TimerTask() {
                        public void run() {

                            contatore++;

                            if (contatore == nPersone) {
                                // Stampo code:
                                Util.printfn("\nCoda 1: " + casse.get(0).getNomeLista() + " (" + casse.get(0).numeroPersone() + ") (" + casse.get(0).getCoda().toString() + ")");
                                Util.printfn("\nCoda 2: " + casse.get(1).getNomeLista() + " (" + casse.get(1).numeroPersone() + ") (" + casse.get(1).getCoda().toString() + ")");
                                Util.printfn("\nCoda 3: " + casse.get(2).getNomeLista() + " (" + casse.get(2).numeroPersone() + ") (" + casse.get(2).getCoda().toString() + ")");
                                timer.cancel();
                                timer.purge();
                                return;
                            }

                            Util.printf("\n- Secondo " + secondo[0]++ + ":");

                            // True se per probabilita' accoda, false se non.
                            boolean accodareODeAccodare;
                            Random r = new Random();
                            float casuale = r.nextFloat();

                            if (orario == 0){
                                accodareODeAccodare = casuale <= 0.5f;
                            } else if (orario == 1){
                                accodareODeAccodare = casuale <= 0.2f;
                            } else {
                                accodareODeAccodare = casuale <= 0.8f;
                            }

                            if (accodareODeAccodare) {
                                miAccodo(numeroCasuale(etaMinima, etaMassima), casse.get(0), casse.get(1), casse.get(2));
                                if (casse.get(0).numeroPersone() > 15) {
                                    if (!casse.get(1).isAttiva()) {
                                        casse.get(1).setAttiva(true);
                                        Util.printfn("\nAttivata '" + casse.get(1).getNomeLista() + "'.");
                                    }
                                    Util.printf("\nSpostamento utenti dalla coda!");
                                    for (int i = 0; i < casse.get(0).getCoda().size(); i++) {
                                        // Sposta elementi posizione pari e diversi da nullo.
                                        if (i % 2 == 0) {
                                            casse.get(1).addElemento(casse.get(0).get(i));
                                            casse.get(0).removeElemento(casse.get(0).get(i));
                                        }
                                    }
                                    Util.printfn("\nFine spostamento utenti dalla coda.");
                                }
                                if (casse.get(0).numeroPersone() > 15 && casse.get(1).numeroPersone() > 15) {
                                    if (!casse.get(2).isAttiva()){
                                        casse.get(2).setAttiva(true);
                                        Util.printfn("\nAttivata '" + casse.get(2).getNomeLista() + "'.");
                                    }
                                    Util.printf("\nSpostamento utenti dalla coda!");
                                    for (int i = 0; i < casse.get(0).getCoda().size(); i++) {
                                        if (casse.get(0).get(i) >= casse.get(2).getEta()) {
                                            casse.get(2).addElemento(casse.get(0).get(i));
                                            casse.get(0).removeElemento(casse.get(0).get(i));
                                        }
                                    }
                                    for (int i = 0; i < casse.get(1).getCoda().size(); i++) {
                                        if (casse.get(1).get(i) >= casse.get(2).getEta()) {
                                            casse.get(2).addElemento(casse.get(1).get(i));
                                            casse.get(1).removeElemento(casse.get(1).get(i));
                                        }
                                    }
                                    Util.printfn("\nFine spostamento utenti dalla coda.");
                                }
                            } else {
                                if (casse.get(2).isAttiva() && casse.get(2).numeroPersone() > 0){
                                    if (casse.get(1).numeroPersone() > 0){
                                        if (casse.get(0).numeroPersone() > 0){
                                            int numeroCasuale = numeroCasuale(0,2);
                                            if (numeroCasuale == 0){
                                                casse.get(0).removePrimoElemento();
                                            } else if (numeroCasuale == 1){
                                                casse.get(1).removePrimoElemento();
                                            } else if (numeroCasuale == 2){
                                                casse.get(2).removePrimoElemento();
                                            }
                                        } else {
                                            casse.get(1).removePrimoElemento();
                                        }
                                    } else if (casse.get(0).numeroPersone() > 0){
                                        casse.get(0).removePrimoElemento();
                                    }
                                } else if (casse.get(1).isAttiva() && casse.get(1).numeroPersone() > 0) {
                                    if (casse.get(0).numeroPersone() > 0){
                                        if (numeroCasuale(0,1) == 0){
                                            casse.get(0).removePrimoElemento();
                                        } else {
                                            casse.get(1).removePrimoElemento();
                                        }
                                    } else {
                                        casse.get(1).removePrimoElemento();
                                    }
                                } else if (casse.get(0).numeroPersone() > 0){
                                    casse.get(0).removePrimoElemento();
                                }
                            }
                        }
                    }, 0, periodo);

                    break;
                }

                case 2: {

                    int scelta2;
                    do {
                        Util.printf("\nOpzioni:" +
                                "\n0 -> Esci" +
                                "\n1 -> Impostazioni singole casse." +
                                "\n2 -> Imposta numero casse." +
                                "\n3 -> Imposta numero persone a cui attivare nuova cassa." +
                                "\n4 -> Visualizza impostazioni correnti globali" +
                                "\nScelta: ");
                        scelta2 = Util.getScanner().nextInt();

                        switch (scelta2){
                            case 0: {
                                Util.printfn("\nUscita dalla configurazione...");
                                fileManager.salvaFile();
                                break;
                            }

                            case 1: {
                                Util.printfn("\nImpostazioni singole casse:");

                                if (fileManager.nCasse == 0){
                                    Util.printfn("\nNon ci sono casse da configurare, il numero di casse è 0!");
                                    break;
                                }

                                List<Cassa> casse = fileManager.getCasse();
                                int contatore = 0;
                                for (Cassa cassa : casse){
                                    Util.printfn("\n[" + contatore + "] -> " + cassa.toString() + "\n");
                                    contatore++;
                                }

                                int cassaScelta;
                                do {
                                    Util.printf("\nScelta casa (Inserire -1 per annullare): ");
                                    cassaScelta = Util.getScanner().nextInt();

                                    if (cassaScelta == -1){
                                        Util.printfn("\nAnnullamento...");
                                        break;
                                    }
                                    if (cassaScelta < 0 || cassaScelta >= casse.size()){
                                        Util.printfn("\nScelta non valida!");
                                    }
                                } while (cassaScelta < 0 || cassaScelta >= casse.size());

                                if (cassaScelta == -1){
                                    break;
                                }

                                int scelta3;
                                do {
                                    Util.printf("\nOpzioni singole casse: " +
                                            "\n0 -> Esci" +
                                            "\n1 -> Leggi informazioni cassa." +
                                            "\n2 -> Imposta età." +
                                            "\n3 -> Attiva/Disattiva età minima cassa." +
                                            "\n4 -> Imposta numero massime persone accettabili." +
                                            "\n5 -> Imposta nome cassa." +
                                            "\nScelta: ");
                                    scelta3 = Util.getScanner().nextInt();

                                    switch (scelta3){

                                        case 0: {
                                            Util.printfn("\nAnnullamento...");
                                            break;
                                        }

                                        case 1:{
                                            Util.printfn("\nInformazioni cassa...");
                                            Util.printfn("\n" + casse.get(cassaScelta).toString());
                                            break;
                                        }

                                        case 2:{
                                            Util.printfn("\nImposta età minima...");

                                            Util.printf("\nInserire età minima: ");
                                            casse.get(cassaScelta).setEta(Util.getScanner().nextInt());

                                            Util.printfn("\nEtà impostata con successo!");
                                            break;
                                        }

                                        case 3:{

                                            Util.printfn("\nAttiva/Disattiva età minima...");

                                            Util.printf("\nAttivare età minima? (s/n): ");
                                            String attiva = Util.getScanner().next();

                                            if (attiva.equals("s")){
                                                casse.get(cassaScelta).setEtaMinima(true);
                                                Util.printfn("\nEtà minima attivata con successo!");
                                            } else if (attiva.equals("n")){
                                                casse.get(cassaScelta).setEtaMinima(false);
                                                Util.printfn("\nEtà minima disattivata con successo!");
                                            } else {
                                                Util.printfn("\nScelta non valida!");
                                            }

                                            break;
                                        }

                                        case 4:{

                                            Util.printfn("\nImposta numero massimo persone accettabili...");

                                            Util.printf("\nInserire numero massimo persone accettabili: ");
                                            casse.get(cassaScelta).setMaxLista(Util.getScanner().nextInt());

                                            Util.printfn("\nNumero massimo persone accettabili impostato con successo!");
                                            break;
                                        }

                                        case 5:{

                                            Util.printfn("\nImposta nome cassa...");

                                            Util.printf("\nInserire nome cassa: ");
                                            casse.get(cassaScelta).setNomeCassa(Util.getScanner().next());

                                            Util.printfn("\nNome cassa impostato con successo!");
                                            break;
                                        }

                                        default:{
                                            Util.printfn("\nScelta non valida!");
                                            break;
                                        }
                                    }
                                } while (scelta3 != 0);

                                fileManager.setCasse(casse);
                                break;
                            }

                            case 2:{

                                Util.printfn("\nImposta numero casse...");

                                Util.printfn("\nNumero attuale casse: " + fileManager.nCasse);

                                Util.printf("\nInserire numero casse: ");
                                fileManager.setnCasse(Util.getScanner().nextInt());

                                Util.printfn("\nNumero casse impostato con successo!");
                                break;
                            }

                            case 3:{

                                Util.printfn("\nImposta numero persona a cui attivare nuova cassa...");

                                Util.printfn("\nNumero attuale persone: " + fileManager.nPersoneAttiva);

                                Util.printf("\nInserire numero persone: ");
                                fileManager.setnPersoneAttiva(Util.getScanner().nextInt());

                                Util.printfn("\nNumero persone impostato con successo!");
                                break;
                            }

                            case 4:{
                                Util.printfn("\nVisualizza impostazioni correnti globali...");

                                Util.printfn("\nImpostazioni correnti globali:");
                                Util.printfn("\nNumero casse: " + fileManager.nCasse);
                                Util.printfn("\nNumero persone a cui attivare nuova cassa: " + fileManager.nPersoneAttiva);
                                break;
                            }

                            default:{
                                Util.printfn("\nScelta non valida.");
                                break;
                            }
                        }
                    } while (scelta2 != 0);

                    break;
                }

                default:{

                    Util.printfn("\nScelta non valida, per favore riprovare!");

                    break;
                }

            }

        } while (scelta != 0);
    }

    public static int numeroCasuale(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }

    /**
     * In modo casuale accoda a lista attiva.
     * */
    public static void miAccodo(int eta, Cassa cassa1, Cassa cassa2, Cassa cassa3){
        if (cassa2.isAttiva()) {
            if (cassa3.isAttiva()){
                if (eta >= cassa3.getEta()){
                    cassa3.addElemento(eta);
                } else if (numeroCasuale(0,1) == 0){
                    cassa1.addElemento(eta);
                } else {
                    cassa2.addElemento(eta);
                }
            } else {
                if (numeroCasuale(0,1) == 0){
                    cassa1.addElemento(eta);
                } else {
                    cassa2.addElemento(eta);
                }
            }
            return;
        }
        cassa1.addElemento(eta);
    }
}

