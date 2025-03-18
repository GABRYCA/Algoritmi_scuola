package Esercizio3.fair_no_waiter;

public class Pool {
	enum State {
		Idle, OnWait, Active
	};

	State[] philStates;
	int numSticks;
	int numPhilosophers;
	long lastPick[];

	Pool(int np, int ns) {
		numPhilosophers = np;
		philStates = new State[np];
		
		for (int i = 0; i < np; i++) philStates[i] = State.Idle;
		
		lastPick = new long[np];
		long t = System.currentTimeMillis();
		
		for (int j = 0; j < np; j++) lastPick[j] = t;
		
		numSticks = ns;
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
		long remotestPick = System.currentTimeMillis();
		int pickedOne = -1;
		
		printout();
		
		for (int i = 0; i < numPhilosophers; i++) {
			if (philStates[i] == State.OnWait && lastPick[i] < remotestPick) {
				remotestPick = lastPick[i];
				pickedOne = i;
			}
		}
		
		return pickedOne;
	}

	public synchronized void takeTwo(int philId) {
		System.out.println("Pool: filosofo ha chiamato taketwo " + philId);
		philStates[philId] = State.OnWait;
		scheduleNext();
		
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
		numSticks += 2;
		philStates[philId] = State.Idle;
		scheduleNext();
	}

	private void scheduleNext() {
		System.out.println("scheduleNext sta provando a schedulare un qualche filosofo");
		
		if (somePhilWaiting() && numSticks >= 2) {
			int idP = pickWaitingPhil();
			if (idP == -1) {
				System.out.println("scheduleNext: niente da fare ****************************");
			} else {
				System.out.println("scheduleNext sveglia filosofo " + idP);
				philStates[idP] = State.Active;
				numSticks -= 2;
				notifyAll();
			}
		}
		
	}
}
