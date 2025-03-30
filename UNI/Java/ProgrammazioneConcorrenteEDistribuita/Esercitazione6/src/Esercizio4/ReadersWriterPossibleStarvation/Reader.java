package Esercizio4.ReadersWriterPossibleStarvation;

import java.util.concurrent.ThreadLocalRandom;

public class Reader extends Thread {
	Data theData;
	String myName;

	Reader(String s, Data d) {
		myName = s;
		theData = d;
	}

	public void run() {
		for (int j = 0; j < 10; j++) {
			theData.startReading();
			System.out.println(myName + " starts reading");
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(90, 300));
			} catch (InterruptedException e) {}
			System.out.println(myName + " stops reading");
			theData.finishedReading();
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(20, 80));
			} catch (InterruptedException e) {}
		}
	}
}
