package mieiBean;

import java.util.ArrayList;

public class LibriBean {

    String categoria;
    // Elenco libri
    ArrayList<String> elenco = new ArrayList<String>();

    public LibriBean() {
        categoria = "Informatica";
        elenco.add("Java");
        elenco.add("C++");
        elenco.add("C#");
        elenco.add("PHP");
        elenco.add("Python");
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public ArrayList<String> getElenco() {
        return elenco;
    }

    public void setElenco(ArrayList<String> elenco) {
        this.elenco = elenco;
    }
}
