package Esercizio3.Barbiere;

public class Cliente extends Thread {
	private String myName;
	private Negozio barberia;

	public Cliente(String name, Negozio n) {
		myName = name;
		this.setName(myName);
		barberia = n;
		start();
	}

	public void run() {
		if (barberia.possoEntrare(myName)) {
			barberia.attesaTurno(myName);
			barberia.miAccomodo();
			try {
				barberia.attesaFineTaglio(myName);
			} catch (InterruptedException e) {}
		}
	}
}
