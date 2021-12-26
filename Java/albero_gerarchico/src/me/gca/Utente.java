package me.gca;

import java.util.ArrayList;

public class Utente {


    /**
     * Valore bandiera -1 significa nullo.
     * */

    private ArrayList<Integer> pPadre = new ArrayList<>();
    private ArrayList<Integer> pFiglio = new ArrayList<>();
    private String nome;

    public Utente(int pPadre, int pFiglio, String nome){
        if (pPadre != -1) {
            this.pPadre.add(pPadre);
        }
        if (pFiglio != -1) {
            this.pFiglio.add(pFiglio);
        }
        this.nome = nome;
    }

    public Utente(String nome){
        this.nome = nome;
    }

    public Utente(){}

    public boolean haPadri(){
        return !pPadre.isEmpty();
    }

    public boolean haFigli(){
        return !pFiglio.isEmpty();
    }

    public boolean puntaPadre(int pPadre){
        return this.pPadre.contains(pPadre);
    }

    public boolean puntaFiglio(int pFiglio){
        return this.pFiglio.contains(pFiglio);
    }

    public ArrayList<Integer> getpPadre() {
        return pPadre;
    }

    public ArrayList<Integer> getpFiglio() {
        return pFiglio;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void addpPadre(int pPadre){
        if (!this.pPadre.contains(pPadre)){
            this.pPadre.add(pPadre);
        }
    }

    public void addpFiglio(int pFiglio){
        if (!this.pFiglio.contains(pFiglio)){
            this.pFiglio.add(pFiglio);
        }
    }

    public void removepPadre(int pPadre){
        if (this.pPadre.contains(pPadre)){
            this.pPadre.remove(pPadre);
        }
    }

    public void removepFiglio(int pFiglio){
        if (this.pFiglio.contains(pFiglio)){
            this.pFiglio.remove(pFiglio);
        }
    }
}
