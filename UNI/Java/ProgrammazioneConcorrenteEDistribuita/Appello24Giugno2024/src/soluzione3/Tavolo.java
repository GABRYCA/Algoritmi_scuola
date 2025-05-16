package soluzione3;

import java.util.concurrent.ThreadLocalRandom;

public class Tavolo {
	Tavolo() {
		// inizializzazione (irrilevante)
	}

	private void attivita() {
		int a = 300;
		int b = 700;
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(a, b));
		} catch (InterruptedException e) {
		}
	}

	public void prendiPedina() {
		// prima parte della mossa
		// qui si modifica la situazione del tavolo: come avviene e` irrilevante
		attivita();
	}

	public void mettiPedina() {
		// seconda parte della mossa
		// qui si modifica la situazione del tavolo: come avviene e` irrilevante
		attivita();
	}

	public String leggi() {
		// codifica la situazione del tavolo in una stringa, mettendoci un po' di tempo
		attivita();
		return "codifica della situazione";
	}
}
