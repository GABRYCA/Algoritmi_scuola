package Esercizio3.basic;

import java.util.concurrent.ThreadLocalRandom;

public class Philosopher extends Thread {
	private int id;
	private Pool thePool;
	private int numLunches;

	public Philosopher(int id, Pool p) {
		this.id = id;
		this.thePool = p;
		numLunches = 0;
	}

	void printout(String s1) {
		System.out.println("Phil " + id + s1);
	}

	void doActivity(String s, int minTime, int maxTime) {
		printout(s);
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(minTime, maxTime));
		} catch (InterruptedException e) {}
	}

	public void run() {
		while (true) {
			doActivity(" sta pensando ", 200, 400);
			printout(" ha fame");
			thePool.takeTwo(id);
			doActivity(" sta mangiando [" + (++numLunches) + "]", 100, 200);
			printout(" sta lasciando le bacchette");
			thePool.leaveTwo(id);
		}
	}
}
