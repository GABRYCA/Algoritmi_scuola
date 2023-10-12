package me.gca.api;

public class ApeLigustica extends Ape {

    public String nomeTipo;
    public int tempoDiVita;

    public ApeLigustica(String nome, String ruolo, String nomeTipo, int tempoDiVita){
        this.nome = nome;
        this.ruolo = ruolo;
        this.nomeTipo = nomeTipo;
        this.tempoDiVita = tempoDiVita;
    }

    public String getNomeTipo() {
        return nomeTipo;
    }

    public int getTempoDiVita() {
        return tempoDiVita;
    }

    public void setNomeTipo(String nomeTipo) {
        this.nomeTipo = nomeTipo;
    }

    public void setTempoDiVita(int tempoDiVita) {
        this.tempoDiVita = tempoDiVita;
    }

    @Override
    public String toString() {
        return "ApeLigustica{" +
                "nomeTipo='" + nomeTipo + '\'' +
                ", tempoDiVita=" + tempoDiVita +
                '}';
    }
}
