package dato;

public class IlMain {
	private void exec() {
		TavoloGioco tavolo = new TavoloGioco();
		Thread g1 = new Giocatore(0, tavolo);
		Thread g2 = new Giocatore(1, tavolo);
		g1.start();
		g2.start();
	}

	public static void main(String[] args) {
		new IlMain().exec();
	}
}
