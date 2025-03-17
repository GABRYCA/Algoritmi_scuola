package Esercizio1;

/**
 * Realizzare un sistema con un produttore e un consumatore usando i semafori (non i monitor)
 * Tutta la sincronizzazione viene fatta nella coda, realizzata usando base quella vista a lezione.
 * */
public class Main {

	final static int dimBuffer = 4;
	
	public static void main(String[] args) {
		Coda coda = new Coda(dimBuffer);
		new Producer("P1", coda).start();
		new Consumer("C1", coda).start();
		new Producer("P2", coda).start();
		new Consumer("C2", coda).start();
	}

}
