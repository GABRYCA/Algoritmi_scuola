package soluzione1;


public class IlMain {
	final int numGiocatori=6;
	Tavolo gestore;

	private void exec() {
		gestore=new Tavolo();
		for(int i=0; i<numGiocatori; i++) {
			new Giocatore(i+1, gestore).start();
		}
	}
	public static void main(String[] args) {
		new IlMain().exec();
	}

}
