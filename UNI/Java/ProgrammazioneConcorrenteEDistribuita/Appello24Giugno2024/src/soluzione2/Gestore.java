package soluzione2;

public class Gestore {
	int numModificheAttive;
	int numLettori;
	Tavolo ilTavolo;

	public Gestore(Tavolo t) {
		numModificheAttive = 0;
		numLettori = 0;
		ilTavolo = t;
	}

	private void situazioneThread() {
		System.out.println(" [#modificanti=" + numModificheAttive + ", #leggenti=" + numLettori + "]");
	}

	private synchronized void puoLeggere() {
		while (numModificheAttive > 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		numLettori++;
	}
	
	private synchronized void puoMossa() {
		while (numModificheAttive > 0 || numLettori > 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		numModificheAttive++;
	}

	private synchronized void uscendoLettura() {
		numLettori--;
		notifyAll();
	}
	
	private synchronized void uscendoMossa() {
		numModificheAttive--;
		notifyAll();
	}

	public String leggi() {
		puoLeggere();
		System.out.print(Thread.currentThread().getName() + " legge situazione "
				+ (numModificheAttive > 0 ? " illegalmente ******" : ""));
		situazioneThread();
		String stato = ilTavolo.leggi();
		uscendoLettura();
		return stato;
	}

	public void mossa(String m) {
		puoMossa();
		System.out.print(Thread.currentThread().getName() + " effettua mossa "
				+ (numModificheAttive > 1 || numLettori > 0 ? " illegalmente ******" : ""));
		situazioneThread();
		// esecuzione della mossa
		ilTavolo.prendiPedina();
		// a questo punto la situazione del tavolo da gioco e` inconsistente
		ilTavolo.mettiPedina();
		uscendoMossa();
	}
}
