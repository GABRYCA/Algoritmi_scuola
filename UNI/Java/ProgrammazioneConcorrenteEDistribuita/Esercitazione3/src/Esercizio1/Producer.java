package Esercizio1;

import java.util.concurrent.ThreadLocalRandom;

public class Producer extends Thread {
	Coda buffer;
	
	public Producer(String s, Coda c) {
		super(s);
		buffer = c;
	}
	
	public void run() {
		int i = 0;
		while (true) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
			} catch (InterruptedException e) {}
			buffer.setElemento(i++);
		}
	}
}
