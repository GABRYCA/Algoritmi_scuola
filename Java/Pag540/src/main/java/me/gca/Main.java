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
                    TimerTask task;
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

