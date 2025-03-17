package Esercizio6;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

/**
 * Realizzare produttore-consumatore, usando BlockingQueue e facendo polling, ossia:
 * Produttore e consumatori provano ad accedere.
 * Se non è possibile, riprovano dopo un po'.
 * */
public class Main {
	
	public final static int dimBuffer = 6;
	public final static int nCons = 3;
	public final static int nProd = 3;
	
	public static void main(String[] args) {
		BlockingQueue<String> coda = new ArrayBlockingQueue<String>(dimBuffer);
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
