package Esercizio4;

public class Tavolo {
	private int turno;
	
	public Tavolo(int inizio) {
		this.turno = inizio;
	}
	
	public synchronized void scambioInCorso(int ab) {
		while (turno != ab) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
	}
	
	public synchronized void scambioCompletato() {
		turno = 1 - turno;
		notifyAll();
	}

}
