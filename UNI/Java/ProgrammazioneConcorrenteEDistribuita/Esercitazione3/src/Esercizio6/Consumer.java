package Esercizio6;

import java.util.NoSuchElementException;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ThreadLocalRandom;

public class Consumer extends Thread {
	
	private BlockingQueue<String> coda;
	String nome;
	String v;
	
	public Consumer(BlockingQueue<String> coda, int id) {
		this.coda = coda;
		this.nome = "Consumer " + id;
	}
	
	private void lettura() {
		boolean finito = false;
		while (!finito) {
			try {
				v = coda.remove();
				finito = true;
			} catch (NoSuchElementException e) {
				try {
					Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
				} catch (InterruptedException e1) {}
			}
		}
	}
	
	public void run() {
		while (true) {
			lettura();
			System.out.println("Il " + nome + " ha letto " + v);
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(100, 300));
			} catch (InterruptedException e) {}
		}
	}

}
