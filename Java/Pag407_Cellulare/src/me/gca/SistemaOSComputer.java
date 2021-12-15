package me.gca;

public class SistemaOSComputer extends Computer {

    private String sistema_operativo;
    private String versione;

    public SistemaOSComputer(){}

    public SistemaOSComputer(String tipo, String nome, String marca, double prezzo, String processore, int numero_core, float memoria_interna_GB, float RAM_GB, String sistema_operativo, String versione, double dimensione_schermo, String scheda_video){
        setTipo(tipo);
        setNome(nome);
        setPrezzo(prezzo);
        setMarca(marca);
        setProcessore(processore);
        setNumero_core(numero_core);
        setMemoria_interna_GB(memoria_interna_GB);
        setRAM_GB(RAM_GB);
        this.sistema_operativo = sistema_operativo;
        this.versione = versione;
        setDimensione_schermo(dimensione_schermo);
        setScheda_video(scheda_video);
    }

    public String getSistema_operativo() {
        return sistema_operativo;
    }

    public void setSistema_operativo(String sistema_operativo) {
        this.sistema_operativo = sistema_operativo;
    }

    public String getVersione() {
        return versione;
    }

    public void setVersione(String versione) {
        this.versione = versione;
    }

    public void stampa(){
        Util.printfn("\nNome: " + getNome() +
                "\nMarca: " + getMarca() +
                "\nPrezzo: €" + getPrezzo() +
                "\nProcessore: " + getProcessore() +
                "\nSistema operativo: " + sistema_operativo +
                "\nVersione: " + versione +
                "\nNumero core: " + getNumero_core() +
                "\nMemoria interna: " + getMemoria_interna_GB() + "GB" +
                "\nRAM: " + getRAM_GB() + "GB" +
                "\nDimensione schermo: " + getDimensione_schermo() + '"' +
                "\nScheda video: " + getScheda_video());
    }
}
