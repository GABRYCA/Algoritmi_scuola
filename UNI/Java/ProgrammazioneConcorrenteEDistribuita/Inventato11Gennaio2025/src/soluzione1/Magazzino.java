package soluzione1;

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
	
	public synchronized void pieno() {
		while (count == capacita) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public synchronized void vuoto() {
		while (count == 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public synchronized void sblocca() {
		notifyAll();
	}

	// Metodo per depositare un prodotto
	public synchronized void deposita(Prodotto prodotto) {
		
		pieno();

		// PROBLEMA: Sezione Critica non protetta (Corsa Critica / Race Condition)
		prodotti[in] = prodotto;
		System.out.println("DEPOSITATO: " + prodotto + " in posizione " + in);
		in = (in + 1) % capacita;
		count++;
		sblocca();
	}

	// Metodo per prelevare un prodotto
	public synchronized Prodotto preleva() {
		
		vuoto();

		// PROBLEMA: Sezione Critica non protetta (Corsa Critica / Race Condition)
		Prodotto prodotto = prodotti[out];
		System.out.println("PRELEVATO: " + prodotto + " da posizione " + out);
		out = (out + 1) % capacita;
		count--;
		sblocca();
		return prodotto;
	}
}