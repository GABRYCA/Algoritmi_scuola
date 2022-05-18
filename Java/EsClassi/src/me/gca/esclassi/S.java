package me.gca.esclassi;

public class S extends O {

    String a = "";

    public S(){}

    @Override
    public String somma(String s) {
        a = super.somma(s);
        return a;
    }

    @Override
    public void reset(){
        a = "";
    }
}
