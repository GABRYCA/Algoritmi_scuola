package me.gca;

public class Calciatore extends Sportivo{
    String squadra;
    String ruolo;
    Calciatore(){}
    Calciatore(String co, String no, String spo, String squ){
        super(co, no, spo);
        squadra = squ;
    }
    void stampa(){
        super.stampa();
        System.out.println("Squadra: " + squadra);
    }
    void stampaSquadra(){
        System.out.println("Squadra:" + squadra);
    }
}