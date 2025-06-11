package soluzione1;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class Gioco {
	private int numGiocatori = 0;
	FasiGioco faseCorrente; // la fase corrente: gioco o lettura risultati
	CyclicBarrier bG, bL;

	public Gioco(int ng) {
		numGiocatori = ng;
		bG = new CyclicBarrier(ng);
		bL = new CyclicBarrier(ng);
		faseCorrente = FasiGioco.Gioco;
	}

	public void giocata(int idGiocatore) {

		try {
			bG.await();
		} catch (InterruptedException | BrokenBarrierException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		faseCorrente = FasiGioco.LetturaRisultati;
	}

	public void letturaEsito(int idGiocatore) {

		try {
			bL.await();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (BrokenBarrierException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		faseCorrente = FasiGioco.Gioco;
	}
}
