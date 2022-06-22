package me.gca.api;

public class Insetto {

    public String nome;

    public Insetto(){
        
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString() {
        return "Insetto{" +
                "nome='" + nome + '\'' +
                '}';
    }
}
