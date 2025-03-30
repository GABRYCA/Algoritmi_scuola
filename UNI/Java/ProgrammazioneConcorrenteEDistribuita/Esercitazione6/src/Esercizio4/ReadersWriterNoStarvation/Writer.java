package Esercizio4.ReadersWriterNoStarvation;

import java.util.concurrent.ThreadLocalRandom;

public class Writer extends Thread {
	Data theData;
	String myName;
	Writer(String s, Data d){
		super(s);
		myName=s;
		theData=d;
	}
	public void run() {
		for(int j=0;j<10;j++) {
			theData.startWriting();
			System.out.println(myName+" starts writing");
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(50,120));
			} catch (InterruptedException e) { }
			theData.finishedWriting();
			System.out.println(myName+" stops writing");
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(30,50));
			} catch (InterruptedException e) { }
		}
	}

}
