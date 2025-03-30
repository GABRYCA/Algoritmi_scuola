package Esercizio3.Barbiere;

public class Barbiere extends Thread {
	private Negozio ilMioNegozio;

	public Barbiere(Negozio n) {
		this.setName("Barber");
		ilMioNegozio = n;
	}

	public void run() {
		while (true) {
			try {
				ilMioNegozio.attesaDormiente();
			} catch (InterruptedException e) {
				System.out.println("il barbiere chiude e va a casa");
				return;
			}
			while (ilMioNegozio.ciSonoClientiInAttesa()) {
				String clienteDaServire = ilMioNegozio.primoClienteDaServire();
				ilMioNegozio.servizioCliente(clienteDaServire);
				try {
					ilMioNegozio.esecuzioneTaglio(200);
				} catch (InterruptedException e) {}
				ilMioNegozio.servito(clienteDaServire);
				if (Thread.interrupted()) {
					System.out.println("il barbiere chiude e va a casa");
					return;
				}
			}
		}
	}
}
