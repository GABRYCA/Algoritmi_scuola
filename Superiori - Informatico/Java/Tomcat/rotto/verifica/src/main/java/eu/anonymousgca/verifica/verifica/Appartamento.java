package eu.anonymousgca.verifica.verifica;

public class Appartamento {

    private String citta;
    private double prezzo;
    private String tipoAnnuncio;
    private boolean archiviato;

    private String proprietario;

    public Appartamento(String citta, double prezzo){
        this.citta = citta;
        this.prezzo = prezzo;
        this.archiviato = false;
    }

    public void mettiInAffitto(){
        this.tipoAnnuncio = "affitto";
    }

    public void mettiInVendesi(){
        this.tipoAnnuncio = "vendesi";
    }

    public boolean isArchiviato(){
        return this.archiviato;
    }

    public void archivia(){
        this.archiviato = true;
    }

    public void deArchivia(){
        this.archiviato = false;
    }

    public void setArchiviato(boolean archiviato){
        this.archiviato = archiviato;
    }

    public String getCitta(){
        return this.citta;
    }

    public double getPrezzo(){
        return this.prezzo;
    }

    public String getTipoAnnuncio(){
        return this.tipoAnnuncio;
    }

    public boolean isVendesi(){
        return this.tipoAnnuncio.equals("vendesi");
    }

    public boolean isAffitto(){
        return this.tipoAnnuncio.equals("affitto");
    }

    public boolean affitta(){
        if(this.isAffitto()){
            this.archivia();
            return true;
        }
        return false;
    }

    public boolean vendi(){
        if(this.isVendesi()){
            this.archivia();
            return true;
        }
        return false;
    }

    public void setProprietario(String proprietario){
        this.proprietario = proprietario;
    }

    public String getProprietario(){
        return this.proprietario;
    }
}
