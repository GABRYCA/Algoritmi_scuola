package soluzione1;

public class IlMain {
	public static void main(String args[]) {
		Tavolo tavolo= new Tavolo();
		Gestore ilGestore=new Gestore(tavolo);
		for(int i=1; i<4; i++) {
			new Giocatore(i,  ilGestore).start();
		}		
	}
}
