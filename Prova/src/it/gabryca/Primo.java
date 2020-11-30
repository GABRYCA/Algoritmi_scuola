package it.gabryca;

public class Primo extends Util {

    public void altPerArRet(){

        // Input
        // InputStreamReader input = new InputStreamReader(System.in);
        // BufferedReader tastiera = new BufferedReader(input);

        printfn("Hai scelto: Pag.101 libro...");

        // Dichiaro variabili
        int base, altezza, area, perimetro;

        // Richiedo input
        printf("Inserire la base: ");
        base = getScanner().nextInt();
        printf("Inserire l'altezza: ");
        altezza = getScanner().nextInt();

        // Eseguo calcoli
        perimetro = (base + altezza) * 2;
        area = base * altezza;

        // Comunico risultati
        printfn("Il perimetro misura: " + perimetro);
        printfn("L'area misura: " + area);
    }
}
