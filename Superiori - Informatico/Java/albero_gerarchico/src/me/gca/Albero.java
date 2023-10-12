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
            if (numeroRicerca != -1) return numeroRicerca;

        }
        return -1;
    }

    private void visualizzaInferioriRicorsivo(int posPadre){
        Util.printf(albero[posPadre].getNome());
        int conta = 0;
        for (int n : albero[posPadre].getpFiglio()){
            if (conta >= 1){
                Util.printf("\n L_ " + albero[posPadre].getNome() + " -> ");
                visualizzaInferioriRicorsivo(n);
            } else {
                Util.printf(" --> ");
                visualizzaInferioriRicorsivo(n);
            }
            conta++;
        }
    }

    private void visualizzaSuperioriRicorsivo(int posFiglio){
        Util.printf(albero[posFiglio].getNome());
        int conta = 0;
        for (int n : albero[posFiglio].getpPadre()){
            if (conta >= 1){
                Util.printf("\n L_" + albero[posFiglio].getNome() + " -> ");
                visualizzaSuperioriRicorsivo(n);
            } else {
                Util.printf(" <-- ");
                visualizzaSuperioriRicorsivo(n);
            }
            conta++;
        }
    }

    public void visualizzaVettoreGrezzo(){
        for (int i = 0; i < albero.length; i++){
            if (albero[i] != null){
                Util.printfn("\n" + i + " -> " + albero[i].getNome());
            }
        }
    }

    public int numeroUtenti(){
        int contatore = 0;
        for (int i = 0; i < maxUtenti; i++){
            if (albero[i] != null) contatore++;
        }
        return contatore;
    }

    public int cercaUtente(String nome){
        for (int pos : senzaPadre){
            int cerca = cercaDaPadre(pos, nome);
            if (cerca != -1) return cerca;
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
                    albero[posizionePadre].addpFiglio(spazioLibero);
                    Util.printfn("\nUtente " + nomeUtente + " con padre " + nomePadre + " aggiunto con successo!");
                } else {
                    Util.printfn("\nNessuno spazio libero rimasto! Aumentare il limite da codice int 'maxUtenti', classe Albero.");
                }
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

    public void eliminaUtente(String nomeUtente){
        int posUtente = cercaUtente(nomeUtente);
        if (posUtente == -1) return;
        Utente daEliminare = albero[posUtente];
        // Elimina puntatori padri e figli.
        for (int p : daEliminare.getpPadre()){
            albero[p].removepFiglio(posUtente);
        }
        // Attenzione, i figli non hanno solitamente più di un padre quindi questo potrebbe spostarli in cima all'albero.
        for (int f : daEliminare.getpFiglio()){
            albero[f].removepPadre(posUtente);
            if (cercaUtente(albero[f].getNome()) == -1){
                senzaPadre.add(f);
            }
        }
        albero[posUtente] = null;
        Util.printfn("\nRimosso con successo utente " + nomeUtente + " e modificati puntatori padre e figli.");
    }

    public void visualizzaInferiori(String nomeUtente){
        int posUtente = cercaUtente(nomeUtente);
        if (posUtente == -1) return;
        Util.printfn("");
        visualizzaInferioriRicorsivo(posUtente);
    }

    public void visualizzaSuperiori(String nomeUtente){
        int posUtente = cercaUtente(nomeUtente);
        if (posUtente == -1) return;
        Util.printfn("");
        visualizzaSuperioriRicorsivo(posUtente);
    }
}
