package me.gca.lampadine;

import me.gca.Util;

public class Lampadina {

    boolean accesa;
    int numeroUtilizzi;
    int numeroOre;
    int numeroUtilizziMax;
    int numeroOreMax;

    /**
     * Costruttore lampadina.
     * @param numeroUtilizziMax
     * @param numeroOreMax
     */
    public Lampadina(int numeroUtilizziMax, int numeroOreMax){
        this.numeroUtilizziMax = numeroUtilizziMax;
        this.numeroOreMax = numeroOreMax;
    }

    /**
     * Ritorna se accesa o meno.
     * @return
     */
    public boolean isAccesa(){
        return accesa;
    }

    /**
     * Semplice click, accende o spegne la lampadina.
     */
    public void click(){
        if (!isRotta()) {
            accesa = !accesa;
            numeroUtilizzi++;
        } else {
            accesa = false;
        }
    }

    /**
     * Ritorna lo stato attuale della lampadina ossia: Acccesa, Spenta, Rotta.
     */
    public void stato(){

        if (numeroUtilizzi >= numeroUtilizziMax && numeroOre >= numeroOreMax){
            Util.printfn("\nLa lampadina è rotta (Utilizzata " + numeroUtilizzi + "/" + numeroUtilizziMax + " volte e " + numeroOre + "/" + numeroOreMax + " ore).");
            return;
        }

        if (numeroUtilizzi >= numeroUtilizziMax){
            Util.printfn("\nLa lampadina è rotta (Utilizzata " + numeroUtilizzi + "/" + numeroUtilizziMax + " volte).");
            return;
        } else if (numeroOre >= numeroOreMax) {
            Util.printfn("\nLa lampadina è rotta (Utilizzata " + numeroOre + "/" + numeroOreMax + " ore).");
            return;
        }

        if (accesa){
            Util.printfn("\nLa lampadina è accesa!");
        } else {
            Util.printfn("\nLa lampadina è spenta!");
        }
    }

    /**
     * Fai passare un ora di tempo di utilizzo.
     */
    public void faiPassareOra(){
        if (!isRotta()) {
            if (accesa) { // Faccio passare le ore solamente se accesa.
                numeroOre++;
            }
        } else {
            accesa = false;
        }
    }

    /**
     * Fai passare un certo numero di ore di utilizzo.
     * @param ore
     */
    public void faiPassareOre(int ore){
        if (!isRotta()) {
            if (accesa) { // Faccio passare le ore solamente se accesa.
                numeroOre += ore;
            }
        } else {
            accesa = false;
        }
    }

    /**
     * Imposta le ore di utilizzo ad un certo numero di ore.
     * @param ore
     */
    public void setNumeroOre(int ore){
        numeroOre = ore;
    }

    /**
     * Imposta il numero utilizzi ad un certo valore.
     * @param numeroUtilizzi
     */
    public void setNumeroUtilizzi(int numeroUtilizzi){
        this.numeroUtilizzi = numeroUtilizzi;
    }

    /**
     * Imposta il numero di utilizzi massimo.
     * @param numeroUtilizziMax
     */
    public void setNumeroUtilizziMax(int numeroUtilizziMax){
        this.numeroUtilizziMax = numeroUtilizziMax;
    }

    /**
     * Imposta il numero di ore massimo.
     * @param numeroOreMax
     */
    public void setNumeroOreMax(int numeroOreMax) {
        this.numeroOreMax = numeroOreMax;
    }

    /**
     * Ritorna il numero di ore utilizzate.
     * @return
     */
    public int getNumeroOre() {
        return numeroOre;
    }

    /**
     * Ritorna il numero di utilizzi utilizzati.
     * @return
     */
    public int getNumeroUtilizzi() {
        return numeroUtilizzi;
    }

    /**
     * Ritorna il numero di ore massime.
     * @return
     */
    public int getNumeroOreMax() {
        return numeroOreMax;
    }

    /**
     * Ritorna il numero di utilizzi massimi.
     * @return
     */
    public int getNumeroUtilizziMax() {
        return numeroUtilizziMax;
    }

    /**
     * Ritorna il numero di ore rimaste.
     * @return
     */
    public int numeroOreRimaste(){
        return numeroOreMax - numeroOre;
    }

    /**
     * Ritorna il numero di utizzi rimasti.
     * @return
     */
    public int numeroUtilizziRimasti(){
        return numeroUtilizziMax - numeroUtilizzi;
    }

    boolean isRotta(){
        return numeroUtilizzi >= numeroUtilizziMax || numeroOre >= numeroOreMax;
    }

    @Override
    public String toString() {
        return "Lampadina{" +
                "accesa=" + accesa +
                ", numeroUtilizzi=" + numeroUtilizzi +
                ", numeroOre=" + numeroOre +
                ", numeroUtilizziMax=" + numeroUtilizziMax +
                ", numeroOreMax=" + numeroOreMax +
                '}';
    }
}
