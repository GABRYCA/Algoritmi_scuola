package Esercizio4.ReadersWriterStub;

public class Reader extends Thread{
	Data theData;
	String myName;
	Reader(String s, Data d){
		myName=s;
		theData=d;
	}
	public void run() {
		for(int j=0;j<10;j++) {
		   // per un po' legge
		   // per un po' fa altro
		}
	}
}
