package Esercizio3;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;

public class Consumer extends Thread {
	private BlockingQueue<String> coda;
	int id;
	String v;
	
	public Consumer(BlockingQueue<String> coda, int id) {
		this.id = id;
		this.coda = coda;
	}

	private void lettura() {
		boolean finito = false;
		while (!finito) {
			try {
				v = coda.poll(55, TimeUnit.MICROSECONDS);
				if (v != null) {
					finito = true;
				} else {
					System.out.println("Producer " + id + " attende...");
					Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
				}
			} catch (InterruptedException e) {}
		}
	}
	
	public void run() {
		while (true) {
			lettura();
			System.out.println("Consumer " + id + " ha letto " + v);
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
			} catch (InterruptedException e) {}
		}
	}
}
