package me.gca;

public class Dado {

    // Dichiaro attributi/variabili della classe.
    private int max = 6;
    private int min = 1;
    private int numeroUscito;

    /**
     * Quando si crea il dado, viene in automatico lanciato ed è possibile prenderne il numero casuale tra 1 e 6.
     * */
    public Dado(){
        lanciaDadi();
    }

    /**
     * Lancia i dadi e ne ritorna il valore oltre a salvarlo in una variabile privata intera.
     *
     * @return numeroDado - int.
     * */
    public int lanciaDadi(){
        return this.numeroUscito = (int) ((Math.random() * (max - min)) + min);
    }

    /**
     * Ritorna il numero del dado.
     *
     * @return numeroDado - int.
     * */
    public int getNumero() {
        return numeroUscito;
    }
}
