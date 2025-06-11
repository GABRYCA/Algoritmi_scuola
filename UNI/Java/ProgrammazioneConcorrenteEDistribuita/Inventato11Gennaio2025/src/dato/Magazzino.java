package dato;

//Risorsa condivisa con problemi di concorrenza.
public class Magazzino {
	private final Prodotto[] prodotti;
	private final int capacita;
	private int count;
	private int in; // Indice per depositare
	private int out; // Indice per prelevare

	public Magazzino(int capacita) {
		this.capacita = capacita;
		this.prodotti = new Prodotto[capacita];
		this.count = 0;
		this.in = 0;
		this.out = 0;
	}

	// Metodo per depositare un prodotto
	public void deposita(Prodotto prodotto) {
		// PROBLEMA: Busy-waiting e nessuna gestione della condizione "magazzino pieno"
		while (count == capacita) {
			// Attesa attiva: spreca CPU e non è una soluzione valida
			// System.out.println("Magazzino pieno, produttore in attesa...");
		}

		// PROBLEMA: Sezione Critica non protetta (Corsa Critica / Race Condition)
		prodotti[in] = prodotto;
		System.out.println("DEPOSITATO: " + prodotto + " in posizione " + in);
		in = (in + 1) % capacita;
		count++;
	}

	// Metodo per prelevare un prodotto
	public Prodotto preleva() {
		// PROBLEMA: Busy-waiting e nessuna gestione della condizione "magazzino vuoto"
		while (count == 0) {
			// Attesa attiva
			// System.out.println("Magazzino vuoto, consumatore in attesa...");
		}

		// PROBLEMA: Sezione Critica non protetta (Corsa Critica / Race Condition)
		Prodotto prodotto = prodotti[out];
		System.out.println("PRELEVATO: " + prodotto + " da posizione " + out);
		out = (out + 1) % capacita;
		count--;
		return prodotto;
	}
}