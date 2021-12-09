package me.gca;

public class Persona {
    String cognome;
    String nome;
    Persona(){}
    Persona(String co, String no){
        cognome = co;
        nome = no;
    }
    void setNome(String no){
        nome = no;
    }

    public void setCognome(String co) {
        this.cognome = co;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    void stampa(){
        System.out.println("Nome   : " + nome);
        System.out.println("Cognome: " + cognome);
    }
}
