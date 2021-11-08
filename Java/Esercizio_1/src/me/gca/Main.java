package me.gca;

public class Main extends Util {

    public static void main(String[] args) {

        int scelta;
        printfn("Esercizio 1 di G.C. 4BITI.");

        do {

            printf("\nEcco le scelte disponibili: " +
                    "\n0 -> Esci." +
                    "\n1 -> Area, Perimetro." +
                    "\nScelta: ");
            scelta = getScanner().nextInt();

            switch (scelta){

                case 0:{

                    printfn("\nHai scelto: Esci...");

                    break;
                }

                case 1:{


                    int base, altezza, area, perimetro;
                    printfn("\nHai scelto: Area e perimetro...");

                    printf("Inserire base: ");
                    base = getScanner().nextInt();

                    printf("Inserire altezza: ");
                    altezza = getScanner().nextInt();

                    printfn("Calcolo in corso...");

                    area = base * altezza;
                    perimetro = (base + altezza) * 2;

                    printfn("\nL'area misura " + area + " e il perimetro " + perimetro + ".");

                    continua();
                    break;
                }

                default: {
                    printfn("Scelta non valida, per favore riprovare!");
                    break;
                }

            }

        } while (scelta != 0);
        printfn("\nUscito con successo!");

    }
}
