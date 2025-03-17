package Esercizio2;

import java.util.concurrent.ThreadLocalRandom;

public class Consumer extends Thread{

	Coda buffer;
	int v;
	
	public Consumer(String s, Coda c) {
		super(s);
		buffer = c;
	}
	
	public void run() {
		while(true) {
			v = buffer.getElemento();
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(10, 100));
			} catch (InterruptedException e) {}
		}
	}
	
}
