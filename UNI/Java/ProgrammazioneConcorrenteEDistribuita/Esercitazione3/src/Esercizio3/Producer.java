package Esercizio3;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;

public class Producer extends Thread {
	private BlockingQueue<String> coda;
	int id;
	String v;
	
	public Producer(BlockingQueue<String> c, int id) {
		coda = c;
		this.id = id;
	}
	
	private void scrittura() {
		boolean finito = false;
		while (!finito) {
			try {
				if (coda.offer(v, 70, TimeUnit.MILLISECONDS)) {
					finito = true;
				} else {
					System.out.println("Producer " + id + " attende...");
					Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
				}
			} catch (InterruptedException e) {}
		}
	}
	
	public void run() {
		int i = 0;
		while (true) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
			} catch (InterruptedException e) {}
			v = "val " + id + " " + i++;
			scrittura();
			System.out.println("Il producer " + id + " ha scritto " + v);
		}
	}
}
