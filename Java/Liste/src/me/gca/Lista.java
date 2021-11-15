package me.gca;

public class Lista {

    int dimMaxVet = 100;
    private Elemento[] lista = new Elemento[dimMaxVet];
    int posizionePrimoElemento;
    int valBandieraVuotoPuntato = -1;
    int valBandieraEliminato = -2;

    /**
     * Crea una nuova lista vuota.
     * */
    public Lista(){
        posizionePrimoElemento = 0;
        setDefault();
    }

    /**
     * Imposta valori di default.
     * */
    public void setDefault(){

        for (int i = 0; i < dimMaxVet; i++){
            lista[i] = new Elemento("null", -2);
        }

        lista[0] = new Elemento("Caretti", 1);
        lista[1] = new Elemento("Cardillo", 2);
        lista[2] = new Elemento("Castiglioni", 3);
        lista[3] = new Elemento("Ferraro", 4);
        lista[4] = new Elemento("Linzas", 5);
        lista[5] = new Elemento("Martinetti", 6);
        lista[6] = new Elemento("Moschella", 7);
        lista[7] = new Elemento("Renella", 8);
        lista[8] = new Elemento("Sinacori", 9);
        lista[9] = new Elemento("Vellone", -1);
    }

    /**
     * Ritorna l'intera lista FISICA sotto forma di vettore.
     * */
    public void visualizza(){
        int posizioneLogica = posizionePrimoElemento;

        while (posizioneLogica != valBandieraVuotoPuntato){
            Util.printf("\n\nPos. Logica " + posizioneLogica + ":" +
                    "\n - Contenuto: " + lista[posizioneLogica].contenuto +
                    "\n - Posizione Puntata: " +
                    lista[posizioneLogica].pos_suc);
            posizioneLogica = lista[posizioneLogica].pos_suc;
        }
    }

    /**
     * Ritorna true se l'elemento e' presente, false se non viene trovato.
     * */
    public boolean cerca(String nome){
        int posizioneLogica = posizionePrimoElemento;
        while (posizioneLogica != valBandieraVuotoPuntato){
            if (lista[posizioneLogica].contenuto.equals(nome)){
                Util.printf("\n\nTrovato! Pos. Logica " + posizioneLogica + ":" +
                        "\n - Contenuto: " + lista[posizioneLogica].contenuto +
                        "\n - Posizione Puntata: " +
                        lista[posizioneLogica].pos_suc);
                return true;
            }
            posizioneLogica = lista[posizioneLogica].pos_suc;
        }

        Util.printf("\nIl nome inserito non e' stato trovato " + nome + "!");
        return false;
    }

    /**
     * Rimuove il nome, se presento, inserito come input.
     * */
    public void rimuovi(String nome){
        int posizioneLogica = posizionePrimoElemento;

        // Verifico se il nome da modificare coincide con quello presente alla prima posizione, e in caso affermativo
        // Vado a modificare la posizione del valore minimo presente (il primo letto nella lettura logica) con quello a cui
        // puntava il valore che sta venendo rimosso.
        if (lista[posizioneLogica].contenuto.equals(nome)){
            //V[posizioneLogica].contenuto = stringaBandieraVuoto;
            if (lista[posizioneLogica].pos_suc != valBandieraVuotoPuntato) {
                this.posizionePrimoElemento = lista[posizioneLogica].pos_suc;
            } else {
                // Resetto posizione iniziale, alla prima in cui si trovera' il primo valore aggiunto in futuro (primo spazio vuoto).
                this.posizionePrimoElemento = 0;
            }
            lista[posizioneLogica].pos_suc = valBandieraEliminato;
            Util.printf("\n" + nome + " rimosso con successo!");
            return;
        }

        while (lista[posizioneLogica].pos_suc != valBandieraVuotoPuntato){

            // In condizioni normali, eseguo una lettura tramite posizione logica dal primo elemento fino a quando:
            // a) Trovo il valore precedente a quello da eliminare ed eseguo le opportune modifiche ai puntatori.
            // b) Non trovo il valore precedente a quello da eliminare (posizione successiva = -1) e quindi comunico l'errore.

            // Valore stringa del valore successivo, ho controllato prima che non sia nullo.
            String valoreSuccessivo = lista[lista[posizioneLogica].pos_suc].contenuto;

            // Confronto valore stringa successivo con quello da cercare.
            if (valoreSuccessivo.equals(nome)){
                // Memorizzo il valore della posizione del nome da rimuovere, perche' nel passaggio successivo sara' modificato.
                int posizioneNomeSuccessivo = lista[posizioneLogica].pos_suc;
                // Valore trovato, ora setto la posizione del puntatore precedente a quella a cui puntava il valore da rimuovere.
                lista[posizioneLogica].pos_suc = lista[posizioneNomeSuccessivo].pos_suc;
                // E setto ai valori di default vuoti il valore da rimuovere.
                lista[posizioneNomeSuccessivo].pos_suc = valBandieraEliminato;
                //V[posizioneNomeSuccessivo].contenuto = valBandieraEliminato;
                Util.printf("\n" + nome + " rimosso con successo!");
                return;
            }
            posizioneLogica = lista[posizioneLogica].pos_suc;
        }
        // Valore non trovato.
        Util.printf("\n" + nome + " non trovato!");
    }

    /**
     * Inserisce in modo da mantenere un ordine alfabetico, il nome specificato.
     * */
    public void inserisci(String nome){

        int vuoto = posizioneVuota();
        Util.printf("\nSono qui!");

        if (vuoto == valBandieraVuotoPuntato){
            Util.printf("\nNessuno spazio libero trovato!");
            return;
        }

        // Inserisco le primo spazio vuoto trovato il valore nuovo.
        lista[vuoto].contenuto = nome;

        // Verifico subito se l'elemento da inserire e' minore del primo.
        if (nome.compareTo(lista[posizionePrimoElemento].contenuto) < 0){
            // Inserisco l'elemento nel primo spazio libero e aggiorno la posizione dell'elemento piu' piccolo
            // A quella nuova (essendo quello inserito il nuovo minore e primo).
            // Poi questo nuovo minore appena inserito puntera' a quello che prima era il minore.

            lista[vuoto].pos_suc = posizionePrimoElemento;
            posizionePrimoElemento = vuoto;
        } else {

            // Dichiaro la variabile temporanea logica da cui iniziare a leggere i valori, e quella a cui punterà l'elemento
            // da inserire con il valore bandiera nullo, che se nel ciclo viene modificata, allora sarà diversa dal valore nullo.
            int posizioneLogica = posizionePrimoElemento, posizioneElementoPrecedente = -1, posElementoDaPuntare = valBandieraVuotoPuntato;
            // Eseguo il ciclo per ogni valore logico disponibili oppure fino a quando non raggiungo uno maggiore di quello
            // da inserire. Tramite questo ciclo ottengo la posizione a cui deve puntare l'elemento inserito e chi punta a lui.
            // Verifico anche il caso speciale in cui sia l'ultimo elemento, semplicemente senza trovare l'elemento da puntare
            // E quindi lasciando quello bandiera nullo, mentre quello che punta al valore inserito sara' sempre disponibile
            // dal momento che la condizione particolare del primo elemento minore e' gia' stata verificata prima.
            while (posizioneLogica != valBandieraVuotoPuntato){
                if (lista[posizioneLogica].contenuto.compareTo(nome) > 0){
                    posElementoDaPuntare = posizioneLogica;
                    break;
                } else {
                    posizioneElementoPrecedente = posizioneLogica;
                }
                posizioneLogica = lista[posizioneLogica].pos_suc;
            }
            lista[posizioneElementoPrecedente].pos_suc = vuoto;
            lista[vuoto].pos_suc = posElementoDaPuntare;
        }

        // Messaggio di successo.
        Util.printf("\nValore nuovo " + nome + " inserito nella posizione " + vuoto + ":" +
                "\nContenuto: " + lista[vuoto].contenuto +
                "\nPunta a: " + lista[vuoto].pos_suc);

    }

    /**
     * Trova la prima posizione vuota sovrascrivibile.
     * */
    private int posizioneVuota() {
        int posRicerca = 0;
        while (posRicerca < dimMaxVet){
            if (lista[posRicerca].contenuto.equals("null") || lista[posRicerca].contenuto.isEmpty() || lista[posRicerca].pos_suc == valBandieraEliminato){
                return posRicerca;
            }
            posRicerca++;
        }
        return valBandieraVuotoPuntato;
    }

}
