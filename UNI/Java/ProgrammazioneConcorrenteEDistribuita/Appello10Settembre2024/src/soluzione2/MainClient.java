package soluzione2;

public class MainClient {

	final static int numGiocatori = 6;

	public static void main(String[] args) {

		for (int i = 0; i < numGiocatori; i++) {
			new Giocatore(i + 1).start();
		}
	}

}
