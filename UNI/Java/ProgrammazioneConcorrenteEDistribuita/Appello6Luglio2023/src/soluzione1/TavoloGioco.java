package soluzione1;

public class TavoloGioco {
	TavoloGioco() {
	}

	public synchronized void mossa(int chi, String m) {
		System.out.println("Giocatore " + chi + " ha fatto mossa " + m);
	}
}
