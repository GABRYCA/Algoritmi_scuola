package it.gabryca;

public class Main extends Util {

    public static void main(String[] args) {

        // Messaggio d'inizio.
        printfn("/////////////////////////////////////////////////////////////////");
        printfn("/           Alunno: Gabriele Caretti, MasterMindJava            /");
        printfn("/////////////////////////////////////////////////////////////////");

        int scelta = 1;

        while (scelta != 0){

            int max = 9, min = 0, dimensioni = 0, nCifre = 4, nCifreGenerate = 0, nTentativi = 10;
            int[] mioVettore = new int[10000];
            
            printf("\nLegenda MasterMind: " +
                    "\n 0 -> Chiudi." +
                    "\n 1 -> MasterMind normale." +
                    "\n 2 -> MasterMind Computer." +
                    "\n 3 -> MasterMind Utente VS Computer (Sperimentale e con problemi ignoti)." +
                    "\nScelta: ");
            scelta = getScanner().nextInt();

            switch (scelta){

                case 0:{

                    printfn("\nHai scelto: Chiudi...");

                    break;
                }

                case 1:{

                    // Messaggio d'inizio
                    printfn("\nHai scelto: MasterMind Normale...");

                    // Chiedo input dall'utente
                    printf("\nInserire numero tentativi: ");
                    nTentativi = getScanner().nextInt();
                    printf("\nInserire numero cifre: ");
                    nCifre = getScanner().nextInt();
                    printf("\nInserire numero max: ");
                    max = getScanner().nextInt();
                    printf("\nInserire numero min: ");
                    min = getScanner().nextInt();

                    // Richiamo MasterMind
                    new MasterMindNormale().masterMindNormale(mioVettore, max, min, nCifre, nCifreGenerate, nTentativi);

                    continua();
                    break;
                }
                case 2:{

                    // Messaggioi d'inizio
                    printf("\n\nHai scelto: MasterMind PC 3.0...");

                    // Richiamo MasterMind 3.0
                    new MasterMindComputer().masterMindComputer(max, min, dimensioni, mioVettore, nCifre, nTentativi);

                    continua();
                    break;
                }

                case 3:{

                    // Messaggio d'inizio
                    printf("\nHai scelto: Uomo VS PC...\n");

                    // Chiedo input dall'utente
                    printf("\nInserire numero massimo (es.9): ");
                    max = getScanner().nextInt();
                    printf("\nInserire numero minimo (es.0): ");
                    min = getScanner().nextInt();
                    printf("\nInserire numero cifre (es.4): ");
                    nCifre = getScanner().nextInt();

                    new MasterMindUtenteVSPC().masterMindUtenteVSPC(mioVettore, max, min, nCifre, nCifreGenerate);

                    continua();
                    break;
                }

                default:{

                    printfn("\nHai inserito un valore non valido, per favore riprova!");

                    continua();

                    break;
                }

            }
        }

        printfn("\n\nChiusura in corso...");
        printfn("\nChiuso con successo!");

    }
}
