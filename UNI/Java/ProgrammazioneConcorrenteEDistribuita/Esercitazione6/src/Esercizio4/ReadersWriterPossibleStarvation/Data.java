package Esercizio4.ReadersWriterPossibleStarvation;

public class Data {
	String theData;
	int numReaders;
	int numWriters;
	Data(){
		theData="boh";
		numReaders=numWriters=0;
	}
	public synchronized void startReading() {
		while(numWriters>0) {
			try {
				wait();
			} catch (InterruptedException e) { }
		}
		numReaders++;
	}
	public synchronized void finishedReading() {
		numReaders--;
		if(numReaders==0) {
			notifyAll();
		}
	}
	public synchronized void startWriting() {
		while(numWriters+numReaders>0) {
			try {
				wait();
			} catch (InterruptedException e) { }
		}
		numWriters++;
	}
	public synchronized void finishedWriting() {
		numWriters--;
		if(numWriters==0) {
			notifyAll();
		}
	}
}
