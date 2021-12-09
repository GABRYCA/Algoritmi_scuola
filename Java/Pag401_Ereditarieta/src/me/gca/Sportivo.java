package me.gca;

public class Sportivo extends Persona {
    String sport;
    Sportivo(){}
    Sportivo(String co, String no, String spo){
        super(co, no);
        sport = spo;
    }
    void stampa(){
        super.stampa();
        System.out.println("Sport  : " + sport);
    }

}
