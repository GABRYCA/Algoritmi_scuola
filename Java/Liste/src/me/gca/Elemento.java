package me.gca;

public class Elemento {

    // Dati.
    private String contenuto;
    private int pos_suc;

    /**
     * Inizializzo oggetto elemento.
     *
     * @param contenuto - String.
     * @param puntatore - int.
     * */
    public Elemento(String contenuto, int puntatore){
        this.contenuto = contenuto;
        this.pos_suc = puntatore;
    }

    /**
     * Ritorna il contenuto memorizzato.
     *
     * @return String.
     * */
    public String getContenuto(){
        return this.contenuto;
    }

    /**
     * Ritorna la posizione puntata dall'elemento della lista.
     *
     * @return int.
     * */
    public int getPos_suc(){
        return this.pos_suc;
    }

    /**
     * Setta contenuto della lista.
     *
     * @param contenuto - String.
     * */
    public void setContenuto(String contenuto){
        this.contenuto = contenuto;
    }

    /**
     * Setta posizione puntata della lista.
     *
     * @param pos_suc - int.
     * */
    public void setPos_suc(int pos_suc){
        this.pos_suc = pos_suc;
    }
}
