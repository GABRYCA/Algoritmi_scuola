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

            Util.printf("\nOpzioni: " +
                    "\n0 -> Esci." +
                    "\n1 -> Coda." +
                    /*"\n2 -> Esercizio 2." +*/
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

                    // Setto eta' cassa.
                    coda3.setEta(etaLista3);

                    // Di base una cassa e' attiva.
                    coda1.setAttiva(true);

                    contatore = 0;
                    Timer timer = new Timer();
                    TimerTask task;
                    timer.scheduleAtFixedRate(task = new TimerTask() {
                        public void run() {

                            contatore++;

                            if (contatore == nPersone) {
                                // Stampo code:
                                Util.printfn("\nCoda 1: " + coda1.getNomeLista() + " (" + coda1.numeroPersone() + ") (" + Arrays.toString(coda1.getLista()).replace(" -1,", "").replace("-1", "") + ")");
                                Util.printfn("\nCoda 2: " + coda2.getNomeLista() + " (" + coda2.numeroPersone() + ") (" + Arrays.toString(coda2.getLista()).replace(" -1,", "").replace("-1", "") + ")");
                                Util.printfn("\nCoda 3: " + coda3.getNomeLista() + " (" + coda3.numeroPersone() + ") (" + Arrays.toString(coda3.getLista()).replace(" -1,", "").replace("-1", "") + ")");
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
                    }, 0, periodo);

                    break;
                }

                /*case 2:{

                    Util.printfn("\nHai scelto: Esercizio 2...");

                    int scelta2;
                    // In minuti.
                    int tempoAttesaMedio = 5;
                    List<String> A = new ArrayList<>();
                    List<String> B = new ArrayList<>();
                    List<String> C = new ArrayList<>();
                    List<String> D = new ArrayList<>();
                    List<String> E = new ArrayList<>();

                    do {

                        Util.printf("\nOpzioni: " +
                                "\n0 -> Esci." +
                                "\n1 -> Visualizza coda grezza." +
                                "\n2 -> Aggiungi utente." +
                                "\nScelta: ");

                        scelta2 = Util.getScanner().nextInt();

                        switch (scelta2){

                            case 0:{

                                Util.printfn("\nHai scelto: Esci..." +
                                        "\n\nUscito con successo!");

                                break;
                            }

                            case 1:{

                                Util.printfn("\nHai scelto: Coda grezza...");

                                Util.printf("\n\nCoda: A");
                                Util.printfn(A.toString());

                                Util.printf("\nCoda: B");
                                Util.printfn(B.toString());

                                Util.printf("\nCoda: C");
                                Util.printfn(C.toString());

                                Util.printf("\nCoda: D");
                                Util.printfn(D.toString());

                                Util.printf("\nCoda: E");
                                Util.printfn(E.toString());

                                break;
                            }

                            case 2:{

                                Util.printfn("\nHai scelto: Aggiungi persona...");

                                int priorita;
                                do {
                                    Util.printfn("\nScegliere priorita':" +
                                            "\n0 -> Annulla." +
                                            "\n1 -> Pronto soccorso (PS)." +
                                            "\n2 -> Anziani, incinta, altre urgenze (AD)." +
                                            "\n3 -> Bambini (BA)." +
                                            "\n4 -> Altri normale (AL)." +
                                            "\nScelta: ");

                                    priorita = Util.getScanner().nextInt();

                                    if (priorita < 0 || priorita > 4){
                                        Util.printfn("\nNon valido!");
                                    }

                                } while (priorita < 0 || priorita > 4);

                                if (priorita == 0){
                                    Util.printfn("\nAnnullato.");
                                    break;
                                }

                                switch (priorita){

                                    case 1:{

                                        String daAggiungere = "PS";

                                        Util.printfn("\nAggiungo con priorita' Pronto Soccorso...");

                                        // Verifico se vuoto uno, e aggiungo.
                                        if (senzaCoda(A, B, C, D, E, daAggiungere)) break;

                                        int nCodaA = A.size();
                                        int nCodaB = B.size();
                                        int nCodaC = C.size();
                                        int nCodaD = D.size();
                                        int nCodaE = E.size();

                                        int min = Math.min(Math.min(nCodaA, Math.min(nCodaB, Math.min(nCodaC, nCodaD))), nCodaE);

                                        if (A.size() == min){

                                            daAggiungere += "A" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda A  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            A.add(daAggiungere);
                                        } else if (B.size() == min){

                                            daAggiungere += "B" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda B  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            B.add(daAggiungere);
                                        } else if (C.size() == min){

                                            daAggiungere += "C" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda C  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            C.add(daAggiungere);
                                        } else if (D.size() == min){

                                            daAggiungere += "D" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda D  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            D.add(daAggiungere);
                                        } else {
                                            // Coda E.

                                            daAggiungere += "E" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda E  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            E.add(daAggiungere);
                                        }

                                        break;
                                    }

                                    case 2:{

                                        String daAggiungere = "AD";

                                        Util.printfn("\nAggiungo con priorita' anziano, donne incinte etc...");

                                        // Verifico se vuoto uno, e aggiungo.
                                        if (senzaCoda(A, B, C, D, E, daAggiungere)) break;

                                        // Numero persone in ogni coda.
                                        int nCodaA = A.size();
                                        int nCodaB = B.size();
                                        int nCodaC = C.size();
                                        int nCodaD = D.size();
                                        int nCodaE = E.size();

                                        int min = Math.min(Math.min(nCodaA, Math.min(nCodaB, Math.min(nCodaC, nCodaD))), nCodaE);

                                        if (A.size() == min){

                                            daAggiungere += "A" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda A  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            A.add(daAggiungere);
                                        } else if (B.size() == min){

                                            daAggiungere += "B" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda B  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            B.add(daAggiungere);
                                        } else if (C.size() == min){

                                            daAggiungere += "C" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda C  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            C.add(daAggiungere);
                                        } else if (D.size() == min){

                                            daAggiungere += "D" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda D  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            D.add(daAggiungere);
                                        } else {
                                            // Coda E.

                                            daAggiungere += "E" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda E  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            E.add(daAggiungere);
                                        }

                                        break;
                                    }

                                    case 3:{

                                        String daAggiungere = "BA";

                                        Util.printfn("\nAggiungo con priorita' bambino...");

                                        // Verifico se vuoto uno, e aggiungo.
                                        if (senzaCoda(A, B, C, D, E, daAggiungere)) break;

                                        int nCodaA = A.size();
                                        int nCodaB = B.size();
                                        int nCodaC = C.size();
                                        int nCodaD = D.size();
                                        int nCodaE = E.size();

                                        int min = Math.min(Math.min(nCodaA, Math.min(nCodaB, Math.min(nCodaC, nCodaD))), nCodaE);

                                        if (A.size() == min){

                                            daAggiungere += "A" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda A  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            A.add(daAggiungere);
                                        } else if (B.size() == min){

                                            daAggiungere += "B" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda B  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            B.add(daAggiungere);
                                        } else if (C.size() == min){

                                            daAggiungere += "C" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda C  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            C.add(daAggiungere);
                                        } else if (D.size() == min){

                                            daAggiungere += "D" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda D  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            D.add(daAggiungere);
                                        } else {
                                            // Coda E.

                                            daAggiungere += "E" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda E  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            E.add(daAggiungere);
                                        }

                                        break;
                                    }

                                    case 4:{

                                        String daAggiungere = "AL";

                                        Util.printfn("\nAggiungo con priorita' normale...");

                                        // Verifico se vuoto uno, e aggiungo.
                                        if (senzaCoda(A, B, C, D, E, daAggiungere)) break;

                                        int nCodaA = A.size();
                                        int nCodaB = B.size();
                                        int nCodaC = C.size();
                                        int nCodaD = D.size();
                                        int nCodaE = E.size();

                                        int min = Math.min(Math.min(nCodaA, Math.min(nCodaB, Math.min(nCodaC, nCodaD))), nCodaE);

                                        if (A.size() == min){

                                            daAggiungere += "A" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda A  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            A.add(daAggiungere);
                                        } else if (B.size() == min){

                                            daAggiungere += "B" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda B  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            B.add(daAggiungere);
                                        } else if (C.size() == min){

                                            daAggiungere += "C" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda C  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            C.add(daAggiungere);
                                        } else if (D.size() == min){

                                            daAggiungere += "D" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda D  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            D.add(daAggiungere);
                                        } else {
                                            // Coda E.

                                            daAggiungere += "E" + min;

                                            Util.printfn("\n|----------|" +
                                                    "\n|Biglietto:|" +
                                                    "\n|  Coda E  |" +
                                                    "\n  " + daAggiungere +
                                                    "\n| Attesa:  |" +
                                                    "\n" + min * tempoAttesaMedio  + " min    " +
                                                    "\n|//////////|");

                                            E.add(daAggiungere);
                                        }

                                        break;
                                    }
                                    default:{

                                        Util.printfn("\nOpzione non valida!");

                                        break;
                                    }

                                }

                                break;
                            }

                            default:{

                                Util.printfn("\nScelta non valida, per favore riprovare!");

                                break;
                            }

                        }
                    } while (scelta2 != 0);

                    break;
                }*/

                default:{

                    Util.printfn("\nScelta non valida, per favore riprovare!");

                    break;
                }

            }

        } while (scelta != 0);
    }

    private static boolean senzaCoda(List<String> a, List<String> b, List<String> c, List<String> d, List<String> e, String daAggiungere) {
        if (a.isEmpty()){

            daAggiungere += "A";

            Util.printfn("\n|----------|" +
                    "\n|Biglietto:|" +
                    "\n|  Coda A  |" +
                    "\n  " + daAggiungere + "1" +
                    "\n| Attesa:  |" +
                    "\n  0 min    " +
                    "\n|//////////|");

            a.add(daAggiungere + "1");

            return true;
        } else if (b.isEmpty()){

            daAggiungere += "B";

            Util.printfn("\n|----------|" +
                    "\n|Biglietto:|" +
                    "\n|  Coda B  |" +
                    "\n  " + daAggiungere + "1" +
                    "\n| Attesa:  |" +
                    "\n  0 min    " +
                    "\n|//////////|");

            b.add(daAggiungere + "1");

            return true;
        } else if (c.isEmpty()){

            daAggiungere += "C";

            Util.printfn("\n|----------|" +
                    "\n|Biglietto:|" +
                    "\n|  Coda C  |" +
                    "\n  " + daAggiungere + "1" +
                    "\n| Attesa:  |" +
                    "\n  0 min    " +
                    "\n|//////////|");

            c.add(daAggiungere + "1");

            return true;
        } else if (d.isEmpty()){

            daAggiungere += "D";

            Util.printfn("\n|----------|" +
                    "\n|Biglietto:|" +
                    "\n|  Coda D  |" +
                    "\n  " + daAggiungere + "1" +
                    "\n| Attesa:  |" +
                    "\n  0 min    " +
                    "\n|//////////|");

            d.add(daAggiungere + "1");

            return true;
        } else if (e.isEmpty()){

            daAggiungere += "E";

            Util.printfn("\n|----------|" +
                    "\n|Biglietto:|" +
                    "\n|  Coda E  |" +
                    "\n  " + daAggiungere + "1" +
                    "\n| Attesa:  |" +
                    "\n  0 min    " +
                    "\n|//////////|");

            e.add(daAggiungere + "1");

        }
        return false;
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

