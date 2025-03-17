package Esercizio3;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

/**
 * Realizzare un sistem con un produttore e un consumatore usando BlockingQueue e con time out (l'ha scritto così il professore).
 * */
public class Main {
	
	public final static int dimBuffer = 4;
	public final static int nCons = 2;
	public final static int nProd = 2;
	
	public static void main(String[] args) {
		BlockingQueue<String> coda = new ArrayBlockingQueue<>(dimBuffer);
		Thread produttori[] = new Producer[nProd];
		Thread consumatori[] = new Consumer[nCons];
		for (int i = 0; i < nProd; i++) {
			produttori[i] = new Producer(coda, i);
			produttori[i].start();
		}
		for (int i = 0; i < nCons; i++) {
			consumatori[i] = new Consumer(coda, i);
			consumatori[i].start();
		}
	}

}
