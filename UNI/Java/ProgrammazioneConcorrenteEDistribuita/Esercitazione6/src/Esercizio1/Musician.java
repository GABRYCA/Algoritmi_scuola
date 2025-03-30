package Esercizio1;

public class Musician extends Thread {
	private BeerAwaiters thirstyList;
	private String myName;
	private ServedBeers freeBeers;

	public Musician(String name, BeerAwaiters ba, ServedBeers sb) {
		super(name);
		this.myName = name;
		this.thirstyList = ba;
		this.freeBeers = sb;
	}

	private void playMusic() {
		int num = 2 + (int) (Math.random() * 8);
		System.out.println(myName + ": I start playing");
		try {
			Thread.sleep(num * 100);
		} catch (InterruptedException e) {
		}
		System.out.println(myName + ": I stop playing");
	}

	public void run() {
		int numSessions = 2 + (int) (Math.random() * 8);
		boolean freeBeerServed = false;
		;
		for (int i = 0; i < numSessions; ++i) {
			playMusic();
			System.out.println(myName + ": I need a beer!");
			thirstyList.add(myName);
			freeBeerServed = freeBeers.fetch(myName);
			System.out.println(myName + (freeBeerServed ? ": I drink a free beer!" : ": no beer :-("));
		}
		System.out.println(myName + ": I go home!");
	}
}
