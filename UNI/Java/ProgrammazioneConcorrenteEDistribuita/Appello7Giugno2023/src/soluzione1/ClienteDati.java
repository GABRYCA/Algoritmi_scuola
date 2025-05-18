package soluzione1;

public class ClienteDati {
	
	static final int numClient = 10;

	public static void main(String[] args) {
		Dati iDati = new Dati();
		for (int i = 0; i < numClient; i++) {
			Thread thread = new ThreadAzioni(iDati, i);
			thread.start();
		}
	}
}
