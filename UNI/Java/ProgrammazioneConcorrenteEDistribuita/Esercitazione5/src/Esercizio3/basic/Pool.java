package Esercizio3.basic;

public class Pool {
	enum State {
		Idle, OnWait, Active
	};

	State[] philStates;
	int numFreeSticks;

	Pool(int np, int ns) {
		philStates = new State[np];
		numFreeSticks = ns;
		for (int i = 0; i < TableBasic.NUM_PHIL; i++) {
			philStates[i] = State.Idle;
		}
	}

	private boolean somePhilWaiting() {
		boolean anybodyWaiting = false;
		for (int i = 0; i < TableBasic.NUM_PHIL; i++) {
			if (philStates[i] == State.OnWait) {
				anybodyWaiting = true;
				break;
			}
		}
		return anybodyWaiting;
	}

	private int pickWaitingPhil() {
		for (int i = 0; i < TableBasic.NUM_PHIL; i++) {
			if (philStates[i] == State.OnWait) {
				return i;
			}
		}
		return -1;
	}

	public synchronized void takeTwo(int philId) {
		System.out.println("Pool: filosofo ha chiamato taketwo " + philId);
		philStates[philId] = State.OnWait;
		notifyAll();
		while (philStates[philId] == State.OnWait) {
			try {
				wait();
			} catch (InterruptedException e) {
			}
		}
		System.out.println("Pool: due prese da filosofo " + philId);
	}

	public synchronized void leaveTwo(int philId) {
		System.out.println("Pool: due rilasciate da filosofo " + philId);
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
			System.out.println("Waiter: niente da fare *****************************************");
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