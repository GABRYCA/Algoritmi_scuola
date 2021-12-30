package me.gca;

public class Coda {

    private int maxLista = 100;
    private int lista[] = new int[maxLista];
    private boolean etaMinima = false;

    private void inizializza(){
        for (int i = 0; i < maxLista; i++){
            lista[i] = -1;
        }
    }

    public Coda(){}

    public Coda(boolean etaMinima){
        this.etaMinima = etaMinima;
    }
}
