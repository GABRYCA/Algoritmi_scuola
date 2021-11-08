package it.gabryca;

public class Frazione extends Util{

    private int[] numeratori = {0,0,0};
    private int[] denominatori = {0,0,0};
    private int denominatore1PrimaDimcm;
    private int denominatore2PrimaDimcm;

    /**
     * Assegna un valore alla prima frazione usando la stringa.
     * Formato stringa: a/b
     * */
    public void setFrazione1(String frazione){

        String[] partiFrazione;

        // Divide i numeri in presenza dello /
        partiFrazione = frazione.split("/");
        numeratori[0] = Integer.parseInt(partiFrazione[0]);
        denominatori[0] = Integer.parseInt(partiFrazione[1]);

    }

    /**
     * Assegna un valora alla seconda frazione usando la stringa.
     * Formato stringa: a/b
     * */
    public void setFrazione2(String frazione){

        String[] partiFrazione;

        // Divide i numeri in presenza dello /
        partiFrazione = frazione.split("/");
        numeratori[1] = Integer.parseInt(partiFrazione[0]);
        denominatori[1] = Integer.parseInt(partiFrazione[1]);
    }

    /**
     * Sono riuscito ad applicarli.
     * */
    public static int mcd(int a, int b) {

        while (a != b) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }

        return a;
    }

    /**
     * Sono riuscito ad applicarli.
     * */
    public static int mcm(int a, int b) {
        return (a * b) / mcd(a, b);
    }

    /**
     * Effettua la somma tra la frazione 1 e frazione 2.
     * */
    public void somma(){

        stessaBaseFraz1e2();

        numeratori[2] = numeratori[0] + numeratori[1];

    }

    /**
     * Effettua la sottrazione tra frazione 1 e frazione 2.
     * */
    public void sottrai(){

        stessaBaseFraz1e2();

        numeratori[2] = numeratori[0] - numeratori[1];

    }

    private void stessaBaseFraz1e2() {
        int mcm = mcm(denominatori[0], denominatori[1]);

        numeratori[0] = numeratori[0] * (mcm / denominatori[0]);
        numeratori[1] = numeratori[1] * (mcm / denominatori[1]);

        denominatori[0] = mcm;
        denominatori[1] = mcm;
        denominatori[2] = mcm;
    }

    /**
     * Effettua moltiplicazione tra frazione 1 e frazione 2.
     * */
    public void moltiplica(){

        numeratori[2] = numeratori[0] * numeratori[1];
        denominatori[2] = denominatori[0] * numeratori[1];

    }

    /**
     * Effettua divisione tra frazione 1 e frazione 2.
     * */
    public void dividi(){

        numeratori[2] = numeratori[0] * denominatori[1];
        denominatori[2] = denominatori[0] * numeratori[1];

    }

    /**
     * Ritorna il valore del numeratore.
     * Scegliere tra:
     * 1 -> Frazione 1
     * 2 -> Frazione 2
     * 3 -> Frazione 3
     * */
    public int getNumeratore(int numeroFrazione){

        numeroFrazione--;

        return numeratori[numeroFrazione];
    }

    /**
     * Ritorna il valore del denominatore.
     * Scegliere tra:
     * 1 -> Frazione 1
     * 2 -> Frazione 2
     * 3 -> Frazione 3
     * */
    public int getDenominatore(int numeroFrazione){

        numeroFrazione--;

        return denominatori[numeroFrazione];
    }

    /**
     * Ritorna il valore, sotto forma di stringa, della frazione.
     * Scegliere tra:
     * 1 -> Frazione 1
     * 2 -> Frazione 2
     * 3 -> Frazione 3
     *
     * @return numeratore/denominatore;
     * */
    public String stampa(int numeroFrazione){

        numeroFrazione--;
        String ris = numeratori[numeroFrazione] + "/" + denominatori[numeroFrazione];

        // printfn(ris);

        return ris;
    }

    public void riduci(int numeroFrazione){

        if (numeratori[numeroFrazione] != 0){

            int mcd = mcd(numeratori[0], denominatori[0]);

            while (numeratori[numeroFrazione] % mcd == 0 && denominatori[numeroFrazione] % mcd == 0){
                numeratori[numeroFrazione] = numeratori[numeroFrazione] / mcd;
                denominatori[numeroFrazione] = denominatori[numeroFrazione] / mcd;
            }
        }
    }
}
