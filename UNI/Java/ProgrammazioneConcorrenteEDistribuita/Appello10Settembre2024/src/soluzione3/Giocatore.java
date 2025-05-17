package soluzione3;

import java.rmi.RemoteException;
import java.util.Random;

public class Giocatore extends Thread {
	String mioNome;
	TavoloInt ilGioco;
	int mioStato;
	Random rnd;

	public Giocatore(int i, TavoloInt t) {
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
		try {
			ilGioco.iniziaGioco(mioNome, mioStato);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for (int i = 0; i < 10; i++) {
			dormitina(200);
			if (rnd.nextBoolean()) { // decide cosa fare
				// cambia stato
				mioStato = prossimoStato(mioStato);
				System.out.println(mioNome + " vado in stato " + mioStato);
				try {
					ilGioco.cambiaStato(mioNome, mioStato);
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				dormitina(500);
			} else {
				// promozione
				System.out.println(mioNome + " provo promozione ");
				try {
					esito = ilGioco.promozione(mioNome);
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				if (esito) {
					dormitina(500);
					System.out.println(mioNome + " promozione OK!");
				} else {
					System.out.println(mioNome + " promozione fallita");
				}
			}
		}
		System.out.println(mioNome + " ha terminato!");
	}
}
