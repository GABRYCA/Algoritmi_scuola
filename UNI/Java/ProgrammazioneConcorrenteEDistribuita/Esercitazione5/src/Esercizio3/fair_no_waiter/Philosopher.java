package Esercizio3.fair_no_waiter;

import java.util.concurrent.ThreadLocalRandom;

public class Philosopher extends Thread {
	private int id ;
	private Pool thePool;
	private int numLunches;
	public Philosopher(int id, Pool w) {
		this.id=id;
		this.thePool=w;
		numLunches=0;
	}
	void printout(String s1) {
		System.out.println("Phil "+id+s1);
	}
	void doActivity(String s, int minTime, int maxTime) {
		printout(s);
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(minTime, maxTime));
		} catch (InterruptedException e) {}		
	}
	public void run() {
		while(true) {
			doActivity(" thinking ", 400, 500);
			printout(" hungry") ;
			thePool.takeTwo(id);
			doActivity(" eating ["+(++numLunches)+"]", 300, 400);
			printout(" is going to free resources");
			thePool.leaveTwo(id);
		}
	}
}