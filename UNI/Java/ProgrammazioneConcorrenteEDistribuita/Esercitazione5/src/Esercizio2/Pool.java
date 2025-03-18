package Esercizio2;

public class Pool {
	private int size;
	private Chopstick[] sticks;
	private int numFreeSticks;
	private int numPhilosophers;
	private int[] philSticks;

	Pool(int numSticks, int numPhil) {
		this.size = numSticks;
		this.numPhilosophers = numPhil;
		sticks = new Chopstick[numSticks];

		for (int i = 0; i < numSticks; i++) sticks[i] = new Chopstick(i + 1);

		numFreeSticks = numSticks;
		philSticks = new int[numPhil];

		for (int i = 0; i < numPhil; i++) philSticks[i] = 0;
	}

	private boolean someoneEating() {
		for (int i = 0; i < numPhilosophers; i++) {
			if (philSticks[i] == 2)
				return true;
		}
		return false;
	}

	public synchronized Chopstick get(int philId) {

		while (numFreeSticks == 0 || (numFreeSticks == 1 && philSticks[philId] == 0 && !someoneEating())) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}

		for (int i = 0; i < size; i++) {
			if (sticks[i].isAvaliable()) {
				sticks[i].take();
				philSticks[philId]++;
				numFreeSticks--;
				return sticks[i];
			}
		}

		return null;
	}

	public synchronized void free(int philId, Chopstick c) {
		c.leave();
		philSticks[philId]--;
		numFreeSticks++;
		notifyAll();
	}
}
