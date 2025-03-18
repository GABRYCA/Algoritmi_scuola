package Esercizio2;

import java.util.concurrent.ThreadLocalRandom;

public class Philosopher extends Thread {
	private Pool pool;
	private int myId;
	private int numPasti;

	public Philosopher(int id, Pool p) {
		this.myId = id;
		this.pool = p;
		numPasti = 0;
	}

	void printout(String s1) {
		System.out.println("Philosopher " + myId + s1);
	}

	void doActivity(String s, int minTime, int maxTime) {
		printout(s);
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(minTime, maxTime));
		} catch (InterruptedException e) {}
	}

	public void run() {
		Chopstick c1, c2;
		while (true) {
			doActivity(" sta pensando ", 400, 500);
			printout(" ha fame");
			c1 = pool.get(myId);
			printout(" ha preso la prima bacchetta (" + c1 + ")");
			c2 = pool.get(myId);
			printout(" ha preso la seconda bacchetta (" + c2 + ")");
			doActivity(" sta mangiando [" + (++numPasti) + "]", 100, 200);
			printout(" sta per lasciare le bacchette (" + c1 + "," + c2 + ")");
			pool.free(myId, c2);
			pool.free(myId, c1);
		}
	}
}
