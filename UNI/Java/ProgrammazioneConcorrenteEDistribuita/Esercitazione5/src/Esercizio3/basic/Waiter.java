package Esercizio3.basic;

public class Waiter extends Thread {
	Pool thePool;

	Waiter(Pool p) {
		thePool = p;
		this.start();
	}

	public void run() {
		while (true) thePool.scheduleNext();
	}
}