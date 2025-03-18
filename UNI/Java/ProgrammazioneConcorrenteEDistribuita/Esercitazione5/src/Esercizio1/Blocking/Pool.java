package Esercizio1.Blocking;

public class Pool {
	private int size;
	private Chopstick[] sticks;
	private int numFreeSticks = 0;

	Pool(int numSticks) {
		this.size = numSticks;
		sticks = new Chopstick[numSticks];
		for (int i = 0; i < numSticks; i++)
			sticks[i] = new Chopstick(i + 1);
		numFreeSticks = numSticks;
	}

	public synchronized Chopstick get_one(boolean second) {
		while (numFreeSticks == 0 || (numFreeSticks == 1 && !second)) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		
		for (int i = 0; i < size; i++) {
			if (sticks[i].isAvaliable()) {
				sticks[i].take();
				numFreeSticks--;
				return sticks[i];
			}
		}

		return null;
	}

	public synchronized void free(Chopstick c) {
		c.leave();
		numFreeSticks++;
		notifyAll();
	}
}