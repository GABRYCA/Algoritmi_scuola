package me.gca;

public class Dado {

    private int max = 6;
    private int min = 1;
    private int numeroUscito;

    /**
     * Quando si crea il dado, viene in automatico lanciato ed è possibile prenderne il numero casuale tra 1 e 6.
     * */
    public Dado(){
        lanciaDadi();
    }

    public int lanciaDadi(){
        return this.numeroUscito = (int) ((Math.random() * (max - min)) + min);
    }

    public int getNumero() {
        return numeroUscito;
    }
}
