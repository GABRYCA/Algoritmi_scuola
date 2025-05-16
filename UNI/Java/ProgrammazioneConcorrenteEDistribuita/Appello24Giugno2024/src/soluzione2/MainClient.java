package soluzione2;

public class MainClient {
	public static void main(String[] args) {
		for (int i = 1; i < 4; i++) {
			new Giocatore(i).start();
		}
	}
}
