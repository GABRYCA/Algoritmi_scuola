package Esercizio4.ReadersWriterStub;

public class Writer extends Thread {
	Data theData;
	String myName;
	Writer(String s, Data d){
		myName=s;
		theData=d;
	}
	public void run() {
		for(int j=0;j<10;j++) {
          // scrive (mettendoci un po' di tempo)
          // per un po' fa altro
		}
	}

}
