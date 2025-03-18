package Esercizio4;

import java.util.concurrent.ThreadLocalRandom;

public class Philosopher extends Thread {
	enum PhilosopherState {
		Thinking, Hungry, Eating
	};

	private int id;
	PhilosopherState myState;
	Chopstick left, right;

	public Philosopher(int id, Chopstick l, Chopstick r) {
		this.id = id;
		myState = PhilosopherState.Thinking;
		left = l;
		right = r;
		printout(" creato con sinistra " + left.getId() + " destra " + right.getId());
	}

	public int getID() {
		return this.id;
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
			myState = PhilosopherState.Thinking;
			doActivity(" sta pensando ", 100, 500);
			myState = PhilosopherState.Hungry;
			printout(" ha fame");
			left.get(id);
			right.get(id);
			myState = PhilosopherState.Eating;
			doActivity(" sta mangiando ****************** ", 50, 200);
			left.leave();
			right.leave();
		}

	}

}
