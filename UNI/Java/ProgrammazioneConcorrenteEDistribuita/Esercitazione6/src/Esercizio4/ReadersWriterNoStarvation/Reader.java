package Esercizio4.ReadersWriterNoStarvation;

import java.util.concurrent.ThreadLocalRandom;

public class Reader extends Thread {
	Data theData;
	String myName;

	Reader(String s, Data d) {
		super(s);
		myName = s;
		theData = d;
	}

	public void run() {
		for (int j = 0; j < 10; j++) {
			theData.startReading();
			System.out.println(myName + " starts reading");
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(5, 100));
			} catch (InterruptedException e) {}
			System.out.println(myName + " stops reading");
			theData.finishedReading();
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(50, 120));
			} catch (InterruptedException e) {}
		}
	}
}
