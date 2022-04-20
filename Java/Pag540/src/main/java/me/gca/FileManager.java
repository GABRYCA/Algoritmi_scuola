package me.gca;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

public class FileManager {

    String nomeFile = "config.json";
    File file = new File(nomeFile);

    // Dati di default.
    int defEta = 70; // 70 Anni di default.
    int defNCassaConEta = 3; // Terza cassa.
    String[] defNomiCasse = {"Prima cassa", "Seconda cassa", "Terza cassa"};
    int defMaxPersonePerCassa = 100; // Oltre a questo numero le persone saranno rifiutate dalla cassa.

    int defNCasse = 3; // Numero casse.
    int defNPersoneAttiva = 15; // Numero di persone a cui si attiva la successiva cassa.

    // Dati caricati dal file.
    List<Cassa> casse = new ArrayList<>();
    int nCasse;
    int nPersoneAttiva;

    public FileManager() {
        caricaFile();
    }

    private void caricaFile(){
        if (!file.exists()) {
            salvaDefault();
        }

        caricaDati();
    }

    private void caricaDati() {
        FileReader reader;
        try {
            reader = new FileReader(nomeFile);
        } catch (FileNotFoundException e) {
            Util.printfn("Errore durante il caricamento del file! (Non trovato)");
            return;
        }

        JSONParser parser = new JSONParser();
        JSONArray jsonObject;
        try {
            jsonObject = (JSONArray) parser.parse(reader);
        } catch (IOException e) {
            Util.printfn("Errore durante il caricamento del file! (IOException)");
            return;
        } catch (ParseException e) {
            Util.printfn("Errore durante il caricamento del file! (RuntimeException)");
            return;
        }

        int contatore = 0;
        for (Object o : jsonObject) {
            JSONObject jsonObject1 = (JSONObject) o;

            if (contatore == 0) { // Dati globali.
                nCasse = (int) (long) jsonObject1.get("nCasse");
                nPersoneAttiva = (int) (long) jsonObject1.get("nPersoneAttiva");
            } else {
                int eta = (int) (long) jsonObject1.get("eta");
                int maxPersone = (int) (long) jsonObject1.get("maxPersone");
                String nome = (String) jsonObject1.get("nome");
                boolean attiva = (boolean) jsonObject1.get("attiva");
                casse.add(new Cassa(nome, eta, attiva, maxPersone));
            }

            contatore++;
        }
    }

    private void salvaDefault(){
        JSONArray casse = new JSONArray();
        JSONObject impostazioni = new JSONObject();
        impostazioni.put("nCasse", defNCasse);
        impostazioni.put("nPersoneAttiva", defNPersoneAttiva);
        casse.add(impostazioni);
        for (int i = 0; i < defNCasse; i++) {
            JSONObject cassa = new JSONObject();
            cassa.put("nome", defNomiCasse[i]);
            cassa.put("eta", defEta);
            cassa.put("maxPersone", defMaxPersonePerCassa);
            if (i == defNCassaConEta) {
                cassa.put("attiva", true);
            } else {
                cassa.put("attiva", false);
            }
            casse.add(cassa);
        }
        try {
            Files.write(file.toPath(), casse.toJSONString().getBytes());
        } catch (IOException e) {
            Util.printfn("Errore durante il salvataggio del file di default!");
        }
    }

    public void salvaFile(){
        JSONArray casse = new JSONArray();
        JSONObject impostazioni = new JSONObject();
        impostazioni.put("nCasse", nCasse);
        impostazioni.put("nPersoneAttiva", nPersoneAttiva);
        casse.add(impostazioni);
        for (Cassa c : this.casse) {
            JSONObject cassa = new JSONObject();
            cassa.put("nome", c.getNomeLista());
            cassa.put("eta", c.getEta());
            cassa.put("maxPersone", c.getMaxLista());
            cassa.put("attiva", c.isAttiva());
            casse.add(cassa);
        }
        try {
            Files.write(file.toPath(), casse.toJSONString().getBytes());
        } catch (IOException e) {
            Util.printfn("Errore durante il salvataggio del file!");
        }
    }

    public void reload(){
        this.caricaFile();
    }

    /**
     * Ritorna lista di casse.
     * */
    public List<Cassa> getCasse() {
        return casse;
    }

    public void setnCasse(int n){
        this.nCasse = n;
    }

    public void setnPersoneAttiva(int n){
        this.nPersoneAttiva = n;
    }

    public void setCasse(List<Cassa> casse) {
        this.casse = casse;
    }
}
