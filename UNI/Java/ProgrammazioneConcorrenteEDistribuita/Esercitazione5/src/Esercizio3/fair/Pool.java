package Esercizio3.fair;

public class Pool {
	enum State {
		Idle, OnWait, Active
	};

	State[] philStates;
	int numFreeSticks;
	int numPhilosophers;
	long lastPick[];

	Pool(int np, int ns) {
		numPhilosophers = np;
		philStates = new State[np];
		for (int i = 0; i < np; i++) philStates[i] = State.Idle;
		lastPick = new long[np];
		long t = System.currentTimeMillis();
		for (int j = 0; j < np; j++) lastPick[j] = t;
		numFreeSticks = ns;
	}

	private void printout() {
		System.out.print("[");
		for (int i = 0; i < numPhilosophers; i++) {
			System.out.print(i);
			switch (philStates[i]) {
			case Idle:
				System.out.print("-I ");
				break;
			case OnWait:
				System.out.print("-W(" + lastPick[i] % 10000 + ") ");
				break;
			case Active:
				System.out.print("-A ");
				break;
			}

		}
		System.out.println("]");
	}

	private boolean somePhilWaiting() {
		boolean anybodyWaiting = false;
		
		for (int i = 0; i < numPhilosophers; i++) {
			if (philStates[i] == State.OnWait) {
				anybodyWaiting = true;
				break;
			}
		}
		
		return anybodyWaiting;
	}

	private int pickWaitingPhil() {
		int p = -1;
		long oldestPick = -1;
		printout();
		
		for (int i = 0; i < numPhilosophers; i++) {
			if (philStates[i] == State.OnWait) {
				if (p == -1) {
					p = i;
					oldestPick = lastPick[i];
				} else {
					if (lastPick[i] < oldestPick) {
						oldestPick = lastPick[i];
						p = i;
					}
				}
			}
		}
		
		return p;
	}

	public synchronized void takeTwo(int philId) {
		System.out.println("Pool: filosofo ha chiamato taketwo " + philId);
		philStates[philId] = State.OnWait;
		notifyAll();
		
		while (philStates[philId] == State.OnWait) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		
		lastPick[philId] = System.currentTimeMillis();
		System.out.println("Pool: due prese dal filosofo " + philId);
	}

	public synchronized void leaveTwo(int philId) {
		System.out.println("Pool: due lasciate dal filosofo " + philId);
		numFreeSticks += 2;
		philStates[philId] = State.Idle;
		notifyAll();
	}

	public synchronized void scheduleNext() {
		System.out.println("Pool: waiter prova a schedulare un qualche filosofo");
		while (numFreeSticks < 2 || !somePhilWaiting()) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		int idP = pickWaitingPhil();
		if (idP == -1) {
			System.out.println("Waiter: niente da fare");
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {}
		} else {
			System.out.println("Pool: waiter sveglia filosofo " + idP);
			philStates[idP] = State.Active;
			numFreeSticks -= 2;
			notifyAll();
		}
	}
}
