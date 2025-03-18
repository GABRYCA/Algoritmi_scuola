package Esercizio4;

public class Chopstick {
	enum ChopstickState {
		Clean, Dirty
	};

	int id;
	ChopstickState state;
	int ownerId;

	Chopstick(int x) {
		id = x;
		state = ChopstickState.Dirty;
		ownerId = -1;
	}

	public int getId() {
		return id;
	}

	public synchronized void setOwner(int philId) {
		ownerId = philId;
	}

	public synchronized void get(int philId) {
		
		while (ownerId != philId && (state == ChopstickState.Clean)) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		
		state = ChopstickState.Clean;
		ownerId = philId;
		notifyAll();
	}

	public synchronized void leave() {
		state = ChopstickState.Dirty;
		notifyAll();
	}

}
