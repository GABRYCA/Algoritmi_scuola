package it.gabryca;

public class Pesata extends Util {

    private String nome;
    private float altezza;
    private float peso;

    public void setNome(String nomeCl){
        nome = nomeCl;
    }

    public String getNome(){
        return nome;
    }

    public void setAltezza(float altezzaCl){
        altezza = altezzaCl;
    }

    public float getAltezza(){
        return altezza;
    }

    public void setPeso(float pesoCl){
        peso = pesoCl;
    }

    public float getPeso(){
        return peso;
    }

    /**
     * Metodo booleano che ritorna se una persona è inForma, calcola
     * il suo IMC utilizzando peso e altezza definiti con setAltezza e setPeso nella classe;
     *
     * @return true o false -> imc >= 23 && imc <= 27;
     * */
    public boolean inForma(){

        // Calcola IMC (Indice di massa corporeo, formula -> peso diviso altezza alla seconda).
        float imc = peso/(altezza*altezza);

        // Se le condizioni sono vere, ritorna true, altrimenti false.
        return imc >= 23 && imc <= 27;
    }
}
