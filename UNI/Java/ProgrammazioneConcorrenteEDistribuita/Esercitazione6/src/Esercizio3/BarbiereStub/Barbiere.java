package Esercizio3.BarbiereStub;

public class Barbiere extends Thread {
	private Negozio ilMioNegozio;

	public Barbiere(Negozio n) {
		this.setName("Barber");
		ilMioNegozio = n;
	}

	public void run() {
		while (true) {
			// TBD
		}
	}
}
