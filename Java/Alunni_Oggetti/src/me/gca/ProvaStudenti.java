package me.gca;

public class ProvaStudenti {

    // Creo l'oggetto privato di tipo Studente, vettore di 5 elementi.
    private Studente[] studenti = new Studente[5];

    /**
     * Genera 5 studenti con voti casuali ma nomi prefissati, e ritorna il nome e la media di quello maggiore.
     * */
    public ProvaStudenti(){
        // Inizializzo con dei valori di default usando il costrutto in Studente.
        studenti[0] = new Studente("Pinco");
        studenti[1] = new Studente("Pallino");
        studenti[2] = new Studente("Tonino");
        studenti[3] = new Studente("Mario");
        studenti[4] = new Studente("Cesare");

        // Calcolo medie.
        int[] medie = {media(studenti[0]), media(studenti[1]), media(studenti[2]), media(studenti[3]), media(studenti[4])};

        // Cerco la media massima.
        int max = 0;
        String nomeStudente = null;
        for (int i = 0; i < studenti.length; i++){
            if (max < medie[i]){
                max = medie[i];
                nomeStudente = studenti[i].getNome();
            }
        }

        // Ritorno sotto forma di messaggio, come richiesto, il nome e la media dello studente migliore.
        Util.printfn(nomeStudente + " Media: " + max);
    }

    /**
     * Calcolo media.
     * @param studente - Studente.
     * @return int - media.
     * */
    private int media(Studente studente){
        return (studente.getVoto1() + studente.getVoto2() + studente.getVoto3()) / 3;
    }

}