package me.gca;

import me.gca.api.ApeLigustica;
import me.gca.biciclette.Bicicletta;
import me.gca.lampadine.Lampadina;

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
                    "\n3 -> Lampadine." +
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
                    printfn("\nHai scelto: Biciclette...");

                    Bicicletta bicicletta = new Bicicletta("Traverse", "Elettrica", "Metallo e Plastica", 20);

                    printfn(bicicletta.toString());
                    printfn("\nInformazioni nel dettaglio con eredità: ");
                    printfn("Nome: " + bicicletta.nome + ".");
                    printfn("Alimentazione: " + bicicletta.alimentazione + ".");
                    printfn("Materiale: " + bicicletta.materiale + ".");
                    printfn("Peso: " + bicicletta.peso + "KG.");
                }

                case 3 -> {

                    printfn("\nHai scelto: Lampadine...");

                    printfn("\nCreo una lampadina...");

                    Lampadina lampadina = new Lampadina(5, 10);

                    printfn("\nLampadina creata con successo, stampo le informazioni dettagliate della classe: ");
                    Util.printfn(lampadina.toString());

                    printfn("\nFaccio un click alla lampadina...");
                    lampadina.click();
                    printfn("\nStato della lampadina attuale: ");
                    lampadina.stato();

                    printfn("\nFaccio passare 1 ora di vita alla lampadina: ");
                    lampadina.faiPassareOra();
                    printfn("\nNumero di ore rimaste alla lampadina: " + lampadina.numeroOreRimaste());

                    printfn("\nRompo la lampadina per utilizzi...");
                    int numeroClick = 10;
                    for (int i = 0; i < numeroClick; i++){
                        lampadina.click();
                    }
                    printfn("\nStato della lampadina: ");
                    lampadina.stato();

                    printfn("\nRompo la lampadina anche per ore di utilizzo...");
                    int numeroOre = 10;
                    lampadina.setNumeroOre(numeroOre);
                    printfn("\nStato della lampadina: ");
                    lampadina.stato();

                    Util.printfn("\nFINE DIMOSTRAZIONE LAMPADINA!");

                    break;
                }

                default -> {
                    Util.printfn("\nScelta non valida! Per favore riprovare!");
                }

            }

        } while (scelta != 0);

    }
}
