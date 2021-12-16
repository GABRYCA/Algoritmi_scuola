package me.gca;

public class Computer extends Elettrodomestici {

    private String processore;
    private int numero_core;
    private float memoria_interna_GB;
    private float RAM_GB;
    private double dimensione_schermo;
    private String scheda_video;

    public Computer(){}

    /**
     * Si intente un computer portatile, in caso di fisso lasciare i parametri come 0 oppure vuoti.
     * @param tipo
     * @param nome
     * @param marca
     * @param prezzo
     * @param processore
     * @param numero_core
     * @param memoria_interna_GB
     * @param RAM_GB
     * @param dimensione_schermo
     */
    public Computer(String tipo, String nome, String marca, double prezzo, String processore, int numero_core, float memoria_interna_GB, float RAM_GB, double dimensione_schermo, String scheda_video){
        setTipo(tipo);
        setNome(nome);
        setPrezzo(prezzo);
        setMarca(marca);
        this.processore = processore;
        this.numero_core = numero_core;
        this.memoria_interna_GB = memoria_interna_GB;
        this.RAM_GB = RAM_GB;
        this.dimensione_schermo = dimensione_schermo;
        this.scheda_video = scheda_video;
    }

    public String getProcessore() {
        return processore;
    }

    public void setProcessore(String processore) {
        this.processore = processore;
    }

    public int getNumero_core() {
        return numero_core;
    }

    public void setNumero_core(int numero_core) {
        this.numero_core = numero_core;
    }

    public float getMemoria_interna_GB() {
        return memoria_interna_GB;
    }

    public void setMemoria_interna_GB(float memoria_interna_GB) {
        this.memoria_interna_GB = memoria_interna_GB;
    }

    public void setDimensione_schermo(double dimensione_schermo) {
        this.dimensione_schermo = dimensione_schermo;
    }

    public float getRAM_GB() {
        return RAM_GB;
    }

    public void setRAM_GB(float RAM_GB) {
        this.RAM_GB = RAM_GB;
    }

    public double getDimensione_schermo(){
        return this.dimensione_schermo;
    }

    public String getScheda_video() {
        return scheda_video;
    }

    public void setScheda_video(String scheda_video) {
        this.scheda_video = scheda_video;
    }
}
