package me.gca.esclassi;

public class N extends O{

    int x = 0;
    public N(){}

    @Override
    public int somma(int i) {
        x = super.somma(i);
        return x;
    }

    @Override
    public void reset(){
        x = 0;
    }
}