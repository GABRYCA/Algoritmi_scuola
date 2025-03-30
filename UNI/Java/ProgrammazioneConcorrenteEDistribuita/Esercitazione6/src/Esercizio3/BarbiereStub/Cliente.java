package Esercizio3.BarbiereStub;

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
		// se la barberia non e` piena, entra
		// aspetta il proprio turno
		// si accomoda sulla poltrona
		// aspetta che il barbiere finisca il taglio
	}
}
