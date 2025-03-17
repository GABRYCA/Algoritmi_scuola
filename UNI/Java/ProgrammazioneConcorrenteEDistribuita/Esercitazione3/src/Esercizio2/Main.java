package Esercizio2;

/**
 * Realizzare un sistema con un produttore e un consumatore, dove tutta la sincronizzazione viene fatta nella coda
 * e usando wait e notify.
 * NB: (Simile se non uguale al precedente esercizio 1).
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
