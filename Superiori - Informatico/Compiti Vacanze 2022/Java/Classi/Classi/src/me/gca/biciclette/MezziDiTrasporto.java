package me.gca.biciclette;

public class MezziDiTrasporto {

    public String nome;
    public String alimentazione;

    public MezziDiTrasporto() {

    }

    public String getNome() {
        return nome;
    }

    public String getAlimentazione() {
        return alimentazione;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setAlimentazione(String alimentazione) {
        this.alimentazione = alimentazione;
    }

    @Override
    public String toString() {
        return "MezziDiTrasporto{" +
                "nome='" + nome + '\'' +
                ", alimentazione='" + alimentazione + '\'' +
                '}';
    }
}
