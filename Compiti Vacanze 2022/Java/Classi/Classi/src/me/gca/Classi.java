package me.gca;

import me.gca.api.ApeLigustica;
import me.gca.biciclette.Bicicletta;

public class Classi extends Util{

    public static void main(String[] args){
        printf("////////////////////" +
                "\nLavoro G.C. 4BITI" +
                "\n////////////////////");

        int scelta;

        do {

            Util.printf("\n\nOpzioni:" +
                    "\n0 -> Esci." +
                    "\n1 -> Api." +
                    "\n2 -> Biciclette." +
                    "\nScelta: ");
            scelta = getScanner().nextInt();

            switch (scelta){

                case 0 -> {
                    printfn("\nHai scelto: Esci..." +
                            "\nUscita in corso...");
                }

                case 1 -> {
                    printfn("\nHai scelto: Api...");

                    ApeLigustica apeLigustica = new ApeLigustica("Ape", "Regina", "Ape Ligustica", 1460);

                    printfn(apeLigustica.toString());
                    printfn("\nInformazioni nel dettaglio con eredità: ");
                    printfn("Nome: " + apeLigustica.getNome() + ".");
                    printfn("Ruolo: " + apeLigustica.getRuolo() + ".");
                    printfn("Nome tipo: " + apeLigustica.getNomeTipo() + ".");
                    printfn("Tempo di vita: " + apeLigustica.getTempoDiVita() + " Giorni.");
                }

                case 2 -> {
                    printf("\nHai scelto: Biciclette...");

                    Bicicletta bicicletta = new Bicicletta("Traverse", "Elettrica", "Metallo e Plastica", 20);

                    printfn(bicicletta.toString());
                    printfn("\nInformazioni nel dettaglio con eredità: ");
                    printfn("Nome: " + bicicletta.nome + ".");
                    printfn("Alimentazione: " + bicicletta.alimentazione + ".");
                    printfn("Materiale: " + bicicletta.materiale + ".");
                    printfn("Peso: " + bicicletta.peso + "KG.");
                }

                default -> {
                    Util.printfn("\nScelta non valida! Per favore riprovare!");
                }

            }

        } while (scelta != 0);

    }
}
