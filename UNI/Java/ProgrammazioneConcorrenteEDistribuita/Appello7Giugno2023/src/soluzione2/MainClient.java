package soluzione2;

public class MainClient {

	static final int numClient = 10;

	public static void main(String[] args) {
		for (int i = 0; i < numClient; i++) {
			Thread thread = new ThreadAzioni(i);
			thread.start();
		}
	}

}
