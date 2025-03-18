package Esercizio1.Polling;

public class Pool {
	private int size;
	private Chopstick[] sticks;
	private int numFreeSticks;

	Pool(int numSticks) {
		this.size = numSticks;
		sticks = new Chopstick[numSticks];
		numFreeSticks = numSticks;
		for (int i = 0; i < numSticks; i++) sticks[i] = new Chopstick(i + 1);
	}

	public synchronized Chopstick get_one(boolean second) {
		if (numFreeSticks > 1 || second) {
			
			for (int i = 0; i < size; i++) {
				if (sticks[i].isAvaliable()) {
					sticks[i].take();
					numFreeSticks--;
					return sticks[i];
				}
			}
		}
		
		return null;
	}

	public void free(Chopstick c) {
		numFreeSticks++;
		c.leave();
	}
}