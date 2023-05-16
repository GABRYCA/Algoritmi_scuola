package eu.anonymousgca.webservicesglassfish;

import java.io.File;

/**
 * Classe per la gestione delle immagini (archiviazione, recupero, ecc.)
 * */
public class ImgUtility {

    private String percorsoUltimaImmagine = "";

    public ImgUtility() {}

    /**
     * Metodo per salvare una immagine nella cartella immagini accessibili tramite URL.
     *
     * @param img byte[] immagine da salvare
     * @param nome String nome dell'immagine da salvare
     */
    public boolean salvaImmagine(byte[] img, String nome) {
        // Creo cartella immagini se non esiste in webapp.
        File dir = new File("immagini");

        if (!dir.exists()) {
            dir.mkdir();
        }

        // Creo il file con il nome dell'immagine.
        File file = new File("immagini/" + nome);
        // Salvo l'immagine.
        try {
            java.io.FileOutputStream fos = new java.io.FileOutputStream(file);
            fos.write(img);
            fos.close();
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

        // Salvo il percorso dell'ultima immagine salvata.
        percorsoUltimaImmagine = "immagini/" + nome;

        return true;
    }

    /**
     * Metodo per recuperare il percorso dell'ultima immagine salvata.
     *
     * @return String percorso dell'ultima immagine salvata
     */
    public String getPercorsoUltimaImmagine() {
        return percorsoUltimaImmagine;
    }

}
