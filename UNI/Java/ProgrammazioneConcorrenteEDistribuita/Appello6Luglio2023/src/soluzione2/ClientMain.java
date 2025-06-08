package soluzione2;

public class ClientMain {
	
	public static void main(String[] args) {
		Thread g1 = new Giocatore(0); 
		Thread g2 = new Giocatore(1); 
		g1.start();
		g2.start();
	}

}
