package me.gca;

import java.util.ArrayList;

public class Albero {

    private int maxUtenti = 100;
    private Utente[] albero = new Utente[maxUtenti];
    private ArrayList<Integer> senzaPadre = new ArrayList<>();

    public Albero(){
        inizializza();
    }

    private void inizializza(){
        for (int i = 0; i < maxUtenti; i++){
            this.albero[i] = null;
        }
    }

    /**
     * Trova uno spazio libero nel vettore in cui aggiungere l'oggetto.
     * */
    private int spazioLibero(){
        int contatore = 0;
        while (contatore < maxUtenti){
            if (albero[contatore] == null){
                return contatore;
            }
            contatore++;
        }
        Util.printfn("\nNessuno spazio libero trovato, attenzione!");
        return -1;
    }

    /**
     * Ricerca in modo ricorsivo, attraverso ai puntatori dei figli partendo dal padre,
     * un certo nome se disponibile.
     *
     * @param posPadre - int.
     * @param nome - int.
     *
     * @return posizione -1 se non trovato.
     * */
    private int cercaDaPadre(int posPadre, String nome){
        if (albero[posPadre].getNome().equalsIgnoreCase(nome)){
            return posPadre;
        }
        // Inutile, un range for non inizia nemmeno se il range è zero.
        /*if (!albero[posPadre].haFigli()){
            return -1;
        }*/
        for (int n : albero[posPadre].getpFiglio()){
            int numeroRicerca = cercaDaPadre(n, nome);
            if (numeroRicerca != -1){
                return numeroRicerca;
            }
        }
        return -1;
    }

    public int numeroUtenti(){
        int contatore = 0;
        for (int i = 0; i < maxUtenti; i++){
            if (albero[i] != null){
                contatore++;
            }
        }
        return contatore;
    }

    public int cercaUtente(String nome){
        for (int pos : senzaPadre){
            return cercaDaPadre(pos, nome);
        }
        Util.printfn("\nNon trovato! [" + nome + "]");
        return -1;
    }

    public void aggiungiUtente(String nomePadre, String nomeUtente){
        if (nomePadre != null){
            int posizionePadre = cercaUtente(nomePadre);
            if (posizionePadre != -1){
                int spazioLibero = spazioLibero();
                if (spazioLibero != -1) {
                    albero[spazioLibero] = new Utente(posizionePadre, -1, nomeUtente);
                }
                albero[posizionePadre].addpFiglio(spazioLibero);
                Util.printfn("\nUtente " + nomeUtente + " con padre " + nomePadre + " aggiunto con successo!");
            } else {
                Util.printfn("\nPadre non trovato! Utente non aggiunto!");
            }
        } else {
            int spazioLibero = spazioLibero();
            if (spazioLibero != -1){
                albero[spazioLibero] = new Utente(nomeUtente);
                senzaPadre.add(spazioLibero);
                Util.printfn("\nUtente " + nomeUtente + " aggiunto con successo!");
            }
        }
    }

}
