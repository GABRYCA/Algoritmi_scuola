package me.gca;

public class Coda {

    private int maxLista = 100;
    private int[] lista = new int[maxLista];
    private int eta = 60;
    private boolean etaMinima = false;
    private boolean attiva = false;
    private String nomeLista;

    private void inizializza(){
        for (int i = 0; i < maxLista; i++){
            lista[i] = -1;
        }
    }

    private int spazioVuoto(){
        for (int i = 0; i < maxLista; i++){
            if (lista[i] == -1) return i;
        }
        Util.printfn("\nNessuno spazio libero disponibile!");
        return -1;
    }

    public Coda(String nome){
        inizializza();
        this.nomeLista = nome;
    }

    public Coda(boolean etaMinima, String nome){
        inizializza();
        this.etaMinima = etaMinima;
        this.nomeLista = nome;
    }

    public boolean isEtaMinima() {
        return etaMinima;
    }

    public int getMaxLista() {
        return maxLista;
    }

    public int[] getLista() {
        return lista;
    }

    public void setEtaMinima(boolean etaMinima) {
        this.etaMinima = etaMinima;
    }

    public void setLista(int[] lista) {
        this.lista = lista;
    }

    public void setMaxLista(int maxLista) {
        this.maxLista = maxLista;
    }

    public int getElemento(int posizione){
        if (lista[posizione] != -1){
            return lista[posizione];
        }
        Util.printfn("\nElemento nullo!");
        return -1;
    }

    public void addElemento(int persona){
        int spazio = spazioVuoto();
        if (spazio == -1){
            return;
        }
        lista[spazio] = persona;
        Util.printfn("\nAggiunto utente di eta' " + lista[spazio] + " alla coda '" + nomeLista + "'.");
    }

    public void removeElemento(int persona){
        for (int i = 0; i < maxLista; i++){
            if (lista[i] == persona){
                Util.printfn("Spostato utente di eta' " + lista[i] + " dalla coda '" + nomeLista + "'.");
                lista[i] = -1;
                eliminaVuotiInterni();
                return;
            }
        }
    }

    public void removePrimoElemento(){
        if (numeroPersone() == 0){
            Util.printfn("\nNon sono presenti persone in coda!");
            return;
        }
        Util.printfn("\nRimosso primo utente di eta' " + lista[0] + " dalla coda '" + nomeLista + "'.");
        lista[0] = -1;
        eliminaVuotiInterni();
    }

    public boolean isAttiva() {
        return attiva;
    }

    public void setAttiva(boolean attiva) {
        this.attiva = attiva;
    }

    public int getEta() {
        return eta;
    }

    public void setEta(int eta) {
        this.eta = eta;
    }

    public int numeroPersone(){
        int contatore = 0;
        for (int i = 0; i < maxLista; i++){
            if (lista[i] != -1) contatore++;
        }
        return contatore;
    }

    public void eliminaVuotiInterni(){
        boolean trovatoSpazio;
        do {
            trovatoSpazio = false;
            int spazio = spazioVuoto();
            if (spazio == -1) {
                return;
            }
            for (int i = 0; i < maxLista; i++){
                if (lista[i] != -1 && i > spazio){
                    lista[spazio] = lista[i];
                    lista[i] = -1;
                    trovatoSpazio = true;
                    break;
                }
            }
        } while (trovatoSpazio);
    }

    public String getNomeLista() {
        return nomeLista;
    }

    public void setNomeLista(String nomeLista) {
        this.nomeLista = nomeLista;
    }
}
