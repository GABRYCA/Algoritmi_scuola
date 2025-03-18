package Esercizio1.Polling;

import java.util.concurrent.ThreadLocalRandom;

public class Philosopher extends Thread {
	private Pool pool;
	private String name;

	public Philosopher(String id, Pool p) {
		this.name = id;
		this.pool = p;
	}

	void printout(String s1) {
		System.out.println("Philosopher " + name + s1);
	}

	void doActivity(String s, int minTime, int maxTime) {
		printout(s);
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(minTime, maxTime));
		} catch (InterruptedException e) {}
	}

	public void run() {
		Chopstick c1, c2;
		int numPasti = 0;
		while (true) {
			doActivity(" sta pensando ", 400, 600);
			printout(" ha fame");
			while ((c1 = pool.get_one(false)) == null) {
				doActivity(" è impegnato ", 30, 35);
			}
			printout(" ha preso la prima bacchetta");
			while ((c2 = pool.get_one(true)) == null) {
				doActivity(" è impegnato ", 30, 35);
			}
			printout(" ha preso la seconda bacchetta");
			doActivity(" sta mangiando [" + (++numPasti) + "]", 100, 300);
			printout(" sta per lasciare le bacchette ");
			pool.free(c2);
			pool.free(c1);
		}
	}
}
