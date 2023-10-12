package me.gca;

public class SistemaOSCellulare extends Cellulari {

    private String sistema_operativo;
    private String versione;

    public SistemaOSCellulare(){}

    public SistemaOSCellulare(String tipo, String nome, String marca, double prezzo, String processore, int numero_core, float memoria_interna_GB, float RAM_GB, String sistema_operativo, String versione){
        setTipo(tipo);
        setNome(nome);
        setPrezzo(prezzo);
        setMarca(marca);
        setProcessore(processore);
        setNumero_core(numero_core);
        setMemoria_interna_GB(memoria_interna_GB);
        setRAM_GB(RAM_GB);
        setSistema_operativo(sistema_operativo);
        setVersione(versione);
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
                "\nRAM: " + getRAM_GB() + "GB");
    }
}
