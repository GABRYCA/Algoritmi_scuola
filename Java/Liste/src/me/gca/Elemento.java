package me.gca;

public class Elemento {

    public String contenuto;
    public int pos_suc;

    public Elemento(String contenuto, int puntatore){
        this.contenuto = contenuto;
        this.pos_suc = puntatore;
    }

    public String getContenuto(){
        return this.contenuto;
    }

    public int getPos_suc(){
        return this.pos_suc;
    }

    public void setContenuto(String contenuto){
        this.contenuto = contenuto;
    }

    public void setPos_suc(int pos_suc){
        this.pos_suc = pos_suc;
    }
}
