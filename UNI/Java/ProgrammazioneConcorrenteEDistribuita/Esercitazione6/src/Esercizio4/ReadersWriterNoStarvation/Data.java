package Esercizio4.ReadersWriterNoStarvation;

public class Data {
	String theData;
	int numReaders;
	int numWriters;
	boolean writePending;

	Data() {
		theData = "boh";
		numReaders = numWriters = 0;
		writePending = false;
	}

	public synchronized void startReading() {
		while (numWriters > 0 || writePending) {
			if (writePending) {
				System.out.println(Thread.currentThread().getName() + " waiting on pending write *********** ");
			}
			try {
				wait();
			} catch (InterruptedException e) {
			}
		}
		numReaders++;
	}

	public synchronized void finishedReading() {
		numReaders--;
		if (numReaders == 0) {
			notifyAll();
		}
	}

	public synchronized void startWriting() {
		writePending = true;
		while (numWriters + numReaders > 0) {
			try {
				System.out.println("Writer starts waiting *********** ");
				wait();
			} catch (InterruptedException e) {}
		}
		writePending = false; // NB: funziona quando c'e` un solo scrittore!
		numWriters++;
	}

	public synchronized void finishedWriting() {
		numWriters--;
		if (numWriters == 0) {
			notifyAll();
		}
	}
}
