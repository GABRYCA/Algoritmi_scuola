package soluzione1;

import java.util.Random;

public class Giocatore extends Thread {
	String mioNome;
	Tavolo ilGioco;
	int mioStato;
	Random rnd;

	public Giocatore(int i, Tavolo t) {
		mioNome = "Giocatore_" + i;
		ilGioco = t;
		rnd = new Random();
	}

	void dormitina(int a) {
		int t = 200 + new Random().nextInt(a);
		try {
			Thread.sleep((long) t);
		} catch (InterruptedException e) {
		}
	}

	int prossimoStato(int statoCorrente) {
		int statoProssimo = statoCorrente;
		while (statoProssimo == statoCorrente) {
			statoProssimo = 1 + rnd.nextInt(Tavolo.MAXstati);
		}
		return statoProssimo;
	}

	public void run() {
		boolean esito = false;
		mioStato = prossimoStato(-1); // stato iniziale
		System.out.println(mioNome + " inizio in stato " + mioStato);
		ilGioco.iniziaGioco(mioNome, mioStato);
		for (int i = 0; i < 10; i++) {
			dormitina(200);
			if (rnd.nextBoolean()) { // decide cosa fare
				// cambia stato
				mioStato = prossimoStato(mioStato);
				System.out.println(mioNome + " vado in stato " + mioStato);
				ilGioco.cambiaStato(mioNome, mioStato);
				dormitina(500);
			} else {
				// promozione
				System.out.println(mioNome + " provo promozione ");
				esito = ilGioco.promozione(mioNome);
				if (esito) {
					dormitina(500);
					System.out.println(mioNome + " promozione OK!");
				} else {
					System.out.println(mioNome + " promozione fallita");
				}
			}
		}
	}
}
