package soluzione1;

public class IlMain {
	private void exec() {
		TavoloGioco tavolo = new TavoloGioco();
		Giocatore g0 = new Giocatore(0, tavolo);
		Giocatore g1 = new Giocatore(1, tavolo);
		g0.setAvversario(g1);
		g1.setAvversario(g0);
		g0.start();
		g1.start();
	}

	public static void main(String[] args) {
		new IlMain().exec();
	}
}
