package me.gca;

public class Moneta {
    private final int TESTA = 0;
    private final int CROCE = 1;
    private int faccia;

    public Moneta(){
        lancia();
    }

    // Lancio casuale della moneta.
    public void lancia(){
        faccia = (int) (Math.random() * 2);
    }

    // Ritorna VERO se il valore e' testa.
    public boolean isTesta(){
        return (faccia == TESTA);
    }

    // Ritorna nome della faccia corrente.
    public String toString(){
        String nomeFaccia;
        if (faccia == TESTA){
            nomeFaccia = "Testa";
        } else {
            nomeFaccia = "Croce";
        }
        return nomeFaccia;
    }
}
