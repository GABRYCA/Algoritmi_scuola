import java.util.ArrayList;

public class BucketBuckSort {

    private int numeroParole;
    private int lunghezzaParole;
    private String[] parole;

    public BucketBuckSort(int numeroParole, int lunghezzaParole){
        this.numeroParole = numeroParole;
        this.lunghezzaParole = lunghezzaParole;
        this.parole = new String[numeroParole];

        // Genera numeroParole parole di lunghezzaParole caratteri
        System.out.println("Creazione di " + numeroParole + " parole di " + lunghezzaParole + " caratteri...");
        for (int i = 0; i < numeroParole; i++){
            String parola = "";
            for (int j = 0; j < lunghezzaParole; j++){
                parola += (char) (Math.random() * 26 + 'a');
            }
            parole[i] = parola;
        }
        System.out.println("Parole generate con successo!");
    }

    public void sort(){
        // Il BucketBuckSort crea un vettore per ogni lettera, e rioridina selezionando carattere per carattere
        // partendo dall'ultimo, le parole, inserendole nel vettore corrispondente alla lettera.
        // Dopo ricostruisce il vettore originale mettendo le parole in ordine dai vettori delle lettere.
        // Ripete il passaggio per ogni lettera all'indietro, ripetendo il processo per ogni lettera.
        System.out.println("BucketBuckSort avviato...");


        for (int i = 0; i < lunghezzaParole; i++){
            ArrayList<String>[] buckets = new ArrayList[26]; // 26 lettere dell'alfabeto

            for (String p : parole) {
                char lettera = p.charAt(lunghezzaParole - 1 - i); // Prendo la lettera i-esima dalla fine
                int bucketIndex = lettera - 'a'; // Ottengo l'indice del bucket
                if (buckets[bucketIndex] == null) {
                    buckets[bucketIndex] = new ArrayList<>();
                }
                buckets[bucketIndex].add(p);
            }

            // Ricostruisco il vettore originale
            int posInserimento = 0;
            for (int j = 0; j < 26; j++){
                if (buckets[j] != null){
                    for (String p : buckets[j]){
                        parole[posInserimento++] = p;
                    }
                }
            }
        }

        System.out.println("BucketBuckSort completato!");
    }

    public void print(){
        System.out.println("Vettore delle parole: ");
        for (int i = 0; i < numeroParole; i++){
            System.out.println((i + 1) + " -> " + parole[i]);
        }
    }

}
