package me.gca;

import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

public class Main {

    public static void main(String[] args) {

        // Messaggio di benvenuto.
        Util.printfn("\n/////////////////////////////////////" +
                "\n// Compito Pag.502 di G.C. 4BITI //" +
                "\n/////////////////////////////////////");

        int scelta;
        do {

            Util.printfn("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Esercizio 1." +
                    "\n2 -> Esercizio 2." +
                    "\nScelta: ");
            scelta = Util.getScanner().nextInt();

            switch (scelta){

                case 0:{

                    Util.printfn("\nUscita in corso...");

                    break;
                }

                case 1:{

                    Util.printfn("\nHai scelto: Programma 1, casse...");

                    Coda coda1 = new Coda("Coda 1");
                    Coda coda2 = new Coda("Coda 2");
                    Coda coda3 = new Coda(true, "Coda 3");
                    int etaLista3 = 60;
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

                    // Setto eta' cassa.
                    coda3.setEta(etaLista3);

                    // Di base una cassa e' attiva.
                    coda1.setAttiva(true);

                    Timer timer = new Timer();
                    timer.scheduleAtFixedRate(new TimerTask() {
                        public void run() {

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
                                miAccodo(numeroCasuale(etaMinima, etaMassima), coda1, coda2);
                                if (coda1.numeroPersone() > 15) {
                                    if (!coda2.isAttiva()) {
                                        coda2.setAttiva(true);
                                        Util.printfn("\nAttivata '" + coda2.getNomeLista() + "'.");
                                    }
                                    Util.printf("\nSpostamento utenti dalla coda!");
                                    int[] lista = coda1.getLista();
                                    for (int i = 0; i < coda1.getMaxLista(); i++) {
                                        // Sposta elementi posizione pari e diversi da nullo.
                                        if (lista[i] != -1) {
                                            if (i % 2 == 0) {
                                                coda2.addElemento(lista[i]);
                                                coda1.removeElemento(lista[i]);
                                            }
                                        }
                                    }
                                    Util.printfn("\nFine spostamento utenti dalla coda.");
                                }
                                if (coda1.numeroPersone() > 15 && coda2.numeroPersone() > 15) {
                                    if (!coda3.isAttiva()){
                                        coda3.setAttiva(true);
                                        Util.printfn("\nAttivata '" + coda3.getNomeLista() + "'.");
                                    }
                                    Util.printf("\nSpostamento utenti dalla coda!");
                                    int[] lista1 = coda1.getLista();
                                    int[] lista2 = coda2.getLista();
                                    for (int i = 0; i < coda1.getMaxLista(); i++) {
                                        if (lista1[i] >= etaLista3) {
                                            coda3.addElemento(lista1[i]);
                                            coda1.removeElemento(lista1[i]);
                                        }
                                    }
                                    for (int i = 0; i < coda2.getMaxLista(); i++) {
                                        if (lista2[i] >= etaLista3) {
                                            coda3.addElemento(lista2[i]);
                                            coda2.removeElemento(lista2[i]);
                                        }
                                    }
                                    Util.printfn("\nFine spostamento utenti dalla coda.");
                                }
                            } else {
                                if (coda3.isAttiva() && coda3.numeroPersone() > 0){
                                    if (coda2.numeroPersone() > 0){
                                        if (coda1.numeroPersone() > 0){
                                            int numeroCasuale = numeroCasuale(0,2);
                                            if (numeroCasuale == 0){
                                                coda1.removePrimoElemento();
                                            } else if (numeroCasuale == 1){
                                                coda2.removePrimoElemento();
                                            } else if (numeroCasuale == 2){
                                                coda3.removePrimoElemento();
                                            }
                                        } else {
                                            coda2.removePrimoElemento();
                                        }
                                    } else if (coda1.numeroPersone() > 0){
                                        coda1.removePrimoElemento();
                                    }
                                } else if (coda2.isAttiva() && coda2.numeroPersone() > 0) {
                                    if (coda1.numeroPersone() > 0){
                                        if (numeroCasuale(0,1) == 0){
                                            coda1.removePrimoElemento();
                                        } else {
                                            coda2.removePrimoElemento();
                                        }
                                    } else {
                                        coda2.removePrimoElemento();
                                    }
                                } else if (coda1.numeroPersone() > 0){
                                    coda1.removePrimoElemento();
                                }
                            }
                        }
                    }, 0, 1000);

                    break;
                }

                case 2:{

                    Util.printfn("\nHai scelto: Esercizio 2...");

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
    public static void miAccodo(int eta, Coda coda1, Coda coda2){
        if (coda2.isAttiva()) {
            if (numeroCasuale(0,1) == 0){
                coda1.addElemento(eta);
            } else {
                coda2.addElemento(eta);
            }
            return;
        }
        coda1.addElemento(eta);
    }
}

