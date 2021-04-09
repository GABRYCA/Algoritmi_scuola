package it.gabryca;

public class Main extends Util{

    public static void main(String[] args) {

        int scelta = 1;
        int numeroNumeri = 0;
        int[] vettore = new int[1000000];

        while(scelta != 0) {

            printf("\n\n|--------------------------" +
                    "\n| Legenda vettori: " +
                    "\n| 0 -> Torna indietro." +
                    "\n| 1 -> Generatore vettore di numeri tra Max e Min." +
                    "\n| 2 -> Ordinamento vettore numeri casuali con scambio (piu' efficiente con pochi numeri)." +
                    "\n| 3 -> Ordinamento vettore numeri casuali in base al valore massimo (piu' efficiente con numeri massimi bassi)." +
                    "\n| 4 -> Leggi vettore." +
                    "\n| Scelta: ");
            scelta = getScanner().nextInt();
            printf("|--------------------------\n");

            switch (scelta){

                case 0:{

                    printf("\nHai scelto: Esci...");
                    printf("\nUscita in corso...");

                    break;
                }

                case 1:{

                    printf("\nHai scelto: Generare vettore con numeri...\n");

                    int numeroMassimo, numeroMinimo;
                    printf("\nNumeri nel vettore: ");
                    numeroNumeri = getScanner().nextInt();

                    printf("\nInserire il numero massimo: ");
                    numeroMassimo = getScanner().nextInt();

                    printf("\nInserire il numero minimo: ");
                    numeroMinimo = getScanner().nextInt();

                    genValSuVett(numeroNumeri, vettore, numeroMassimo, numeroMinimo);

                    printf("\nValori nel vettore scritti con successo!");

                    continua();

                    break;
                }

                case 2:{

                    printf("\nHai scelto: Riordinamento valori con scambio...\n");

                    ordinamentoScambio(numeroNumeri, vettore);

                    continua();

                    break;
                }

                case 3:{

                    printf("\nHai scelto: Riordinamento valori per valore massimo...\n");

                    ordinamentoMax(numeroNumeri, vettore);

                    continua();

                    break;
                }

                case 4:{

                    printf("\nHai scelto: Leggi vettore...\n");

                    printf("\nI valori nel vettore sono: ");
                    letturaVett(numeroNumeri, vettore);

                    continua();

                    break;
                }

                default:{

                    printf("\nScelta non valida, per favore riprovare!\n");

                    break;
                }
            }
        }

        printf("\nUscito con successo.");
    }
}
