package Esercizio1.Blocking;

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
			doActivity(" sta pensando ", 400, 500);
			printout(" ha fame");
			c1 = pool.get_one(false);
			printout(" ha preso la prima bacchetta (" + c1 + ")");
			c2 = pool.get_one(true);
			printout(" ha preso la seconda bacchetta (" + c2 + ")");
			doActivity(" eating [" + (++numPasti) + "]", 100, 200);
			printout(" libererà le risorse (" + c1 + "," + c2 + ")");
			pool.free(c2);
			pool.free(c1);
		}
	}
}
