package me.gca.esclassi;

public class O {

    int x = 0;
    String a = "";

    public O(){}

    protected String somma(String s){
        a += s;
        return a;
    }

    protected String somma(String a, String b){
        this.a += a + b;
        return this.a;
    }

    protected int somma(int i){
        x += i;
        return x;
    }

    protected int somma(int a, int b){
        x += a + b;
        return x;
    }

    protected void reset(){
        x = 0;
        a = "";
    }
}
