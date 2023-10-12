package eu.anonymousgca.verifica.verifica;

public class Utente {

    private String nome;
    private String cognome;
    private String username;
    private String password;
    private double saldo;

    public Utente(String nome, String cognome, String username, String password, double saldo){
        this.nome = nome;
        this.cognome = cognome;
        this.username = username;
        this.password = password;
        this.saldo = saldo;
    }

    public String getNome(){
        return this.nome;
    }

    public String getCognome(){
        return this.cognome;
    }

    public String getUsername(){
        return this.username;
    }

    public String getPassword(){
        return this.password;
    }

    public double getSaldo(){
        return this.saldo;
    }

    public void setSaldo(double saldo){
        this.saldo = saldo;
    }

}
