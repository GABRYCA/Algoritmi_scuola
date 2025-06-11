package soluzione2;

public class MainClient {

	static final int numGiocatori = 3;

	public static void main(String[] args) {
		for (int i = 0; i < numGiocatori; i++) {
			new Giocatore(i).start();
		}
	}
	
}
