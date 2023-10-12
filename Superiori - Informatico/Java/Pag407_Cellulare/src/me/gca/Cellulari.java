package me.gca;

public class Cellulari extends Elettrodomestici {

    private String processore;
    private int numero_core;
    private float memoria_interna_GB;
    private float RAM_GB;

    public Cellulari(){}

    /**
     * @param tipo
     * @param nome
     * @param marca
     * @param prezzo
     * @param processore
     * @param numero_core
     * @param memoria_interna_GB
     * @param RAM_GB
     */
    public Cellulari(String tipo, String nome, String marca, double prezzo, String processore, int numero_core, float memoria_interna_GB, float RAM_GB){
        setTipo(tipo);
        setNome(nome);
        setPrezzo(prezzo);
        setMarca(marca);
        this.processore = processore;
        this.numero_core = numero_core;
        this.memoria_interna_GB = memoria_interna_GB;
        this.RAM_GB = RAM_GB;
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

    public float getRAM_GB() {
        return RAM_GB;
    }

    public void setRAM_GB(float RAM_GB) {
        this.RAM_GB = RAM_GB;
    }
}
