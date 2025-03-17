package Esercizio6;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ThreadLocalRandom;

public class Producer extends Thread {
	
	private BlockingQueue<String> coda;
	private String nome;
	private String v;
	
	public Producer(BlockingQueue<String> coda, int id) {
		this.coda = coda;
		this.nome = "Producer " + id;
	}
	
	private void scrittura() {
		boolean finito = false;
		while (!finito) {
			try {
				coda.add(v);
				finito = true;
			} catch (IllegalArgumentException e) {
				try {
					Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
				} catch (InterruptedException e1) {}
			}
		}
	}
	
	public void run() {
		int i = 0;
		while (true) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(100, 300));
			} catch (InterruptedException e) {}
			v = "Sono " + nome + " " + (i++);
			scrittura();
			System.out.println("Il " + nome + " ha scritto " + v);
		}
	}
}
