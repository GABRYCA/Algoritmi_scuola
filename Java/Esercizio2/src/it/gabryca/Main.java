package it.gabryca;

import java.util.ArrayList;
import java.util.List;

public class Main extends Util {

    public static void main(String[] args) {

        int scelta, numeroRegistrati = 0, pesoForma = 0;
        List<String> personePesoForma = new ArrayList<>();

        // Messaggio d'inizio.
        printfn("/////////////////////////////////////////////////////////////////");
        printfn("/        Alunno: Gabriele Caretti, Esercizio 2 (Pesata)         /");
        printfn("/////////////////////////////////////////////////////////////////");

        // Legenda e input utente -> scelta
        printf("\nScegli uno dei due: " +
                "\n1 -> Inserire numero di persone da registrare." +
                "\n2 -> Confermare ogni volta se registrare altre persone o meno (Rispondere stop per fermare)." +
                "\nScelta: ");
        scelta = getScanner().nextInt();

        // Richiama classe pesata, per evitare di fare new ogni volta con il rischio di azzerare i valori.
        Pesata pesata = new Pesata();

        // Switch scelta
        switch (scelta){

            case 1:{

                // Inizializzo variabile
                int numeroPersone;

                // Richiedo input utente per il numero di persone
                printf("\nHai scelto: in base al numero di persone prestabilito..." +
                        "\nInserire numero di persone: ");
                numeroPersone = getScanner().nextInt();

                // Esegue un loop per ogni utente
                for (int i = 0; i < numeroPersone; i++){

                    // Se sono state registrate 5 persone, allora esegue l'azione.
                    if (numeroRegistrati == 5){
                        printfn("\nSono stati inserite 5 persone, ecco i risultati: " +
                                "\n- Numero persone in pesoForma: " + pesoForma +
                                "\n- Nomi persone in pesoForma: " + personePesoForma.toString());
                        continua();
                    }

                    // Comunica a che persona si è arrivati
                    printfn("\nInserimento dati persona numero [" + (numeroRegistrati + 1) + "]");

                    // Richiedo valori in input
                    printf("\nInserire nome persona: ");
                    pesata.setNome(getScanner().next());
                    printf("\nInserire altezza: ");
                    pesata.setAltezza(getScanner().nextFloat());
                    printf("\nInserire peso: ");
                    pesata.setPeso(getScanner().nextFloat());

                    // Ottengo risultato booleano e in base al risultato aggiungo o meno l'utente alla lista.
                    if (pesata.inForma()){
                        personePesoForma.add(pesata.getNome());
                        pesoForma++;
                    }

                    // Incremento numero registrati, è specificato in questo modo per il caso particolare sotto.
                    numeroRegistrati++;
                }

                // Caso particolare:
                // Nel caso si sia messo come numero massimo 5, allora questo mostrerà comunque il risultato,
                // Il for esce quando si raggiunge il numero prestabilito e farebbe saltare questa parte.
                if (numeroRegistrati == 5){
                    printfn("\nSono stati inserite 5 persone, ecco i risultati: " +
                            "\n- Numero persone in pesoForma: " + pesoForma +
                            "\n- Nomi persone in pesoForma: " + personePesoForma.toString());
                    continua();
                }


                break;
            }

            case 2:{

                // Dichiaro variabile, con un valore diverso da stop così continua.
                String risposta = "ok";

                // Messaggio d'inizio
                printfn("\nHai scelto: in base alla risposta ad ogni persona (parola chiave -> Stop)...");

                // Continua fintanto che l'utente non abbia inserito -stop-.
                while (!risposta.equalsIgnoreCase("stop")){

                    // Se si è arrivati a 5, allora esegue l'azione come da consegna.
                    if (numeroRegistrati == 5){
                        printfn("\nSono stati inserite 5 persone, ecco i risultati: " +
                                "\n- Numero persone in pesoForma: " + pesoForma +
                                "\n- Nomi persone in pesoForma: " + personePesoForma.toString());
                        continua();
                    }

                    // Comunica a che numero si è arrivati.
                    printfn("\nInserimento dati persona numero [" + (numeroRegistrati + 1) + "]");

                    // Richiede input.
                    printf("\nInserire nome persona: ");
                    pesata.setNome(getScanner().next());
                    printf("\nInserire altezza: ");
                    pesata.setAltezza(getScanner().nextFloat());
                    printf("\nInserire peso: ");
                    pesata.setPeso(getScanner().nextFloat());

                    // Se la condizione è vera (la prende dal metodo booleano), allora aggiunge la persona alla lista
                    // e incrementa il numero di persone in pesoForma trovate.
                    if (pesata.inForma()){
                        personePesoForma.add(pesata.getNome());
                        pesoForma++;
                    }

                    // Chiede se si vuole inserire un nuovo utente, se si digita stop fermerà l'algoritmo.
                    printf("\nVuoi inserire un altro utente? Scrivi -stop- per fermarti o altro per continuare..." +
                            "\nRisposta: ");
                    risposta = getScanner().next();

                    // Si incrementa ad ogni ciclo, questo è necessario per il caso particolare menzionato sotto...
                    numeroRegistrati++;
                }

                // Caso particolare:
                // In caso un utente fermi l'algoritmo al 5° utente, questo permetterà di vedere il risultato
                // comunque se era stata aggiunta la 5a persona.
                if (numeroRegistrati == 5){
                    printfn("\nSono stati inserite 5 persone, ecco i risultati: " +
                            "\n- Numero persone in pesoForma: " + pesoForma +
                            "\n- Nomi persone in pesoForma: " + personePesoForma.toString());
                    continua();
                }

                break;
            }

            default:{

                // Se viene inserito un valore non valido, comunicherà il messaggio d'errore e fermerà l'esercizio.
                printfn("\nHai inserito una scelta non valida, per favore riprova!");

                break;
            }
        }

        // Messaggio di fine.
        printfn("\nFine esercizio! " +
                "\nChiusura in corso...");
    }
}
