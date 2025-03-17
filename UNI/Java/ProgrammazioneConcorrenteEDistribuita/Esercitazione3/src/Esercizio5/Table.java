package Esercizio5;

public class Table {
	
	private boolean isFinita=false;
	private int numGiocatori;
	private int turno;
	
	Table(int n){
		isFinita=false;
		numGiocatori = n;
		turno = 0;
	}
	
	synchronized void mossa(int playerId, int dado1, int dado2){
		while (!isFinita && turno != playerId) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		
		if (!isFinita) {
			System.out.println("Giocatore " + playerId + " ha giocato [" + dado1 + " " + dado2 + "]");
		}
		
		isFinita=(Math.random()<0.2);
		
		if (isFinita){
			System.out.println("il giocatore "+playerId+" ha vinto!");
		}
		
		if (isFinita || dado1 != dado2) {
			turno = (turno + 1) % numGiocatori;
		}
		
		notifyAll();
	}
	
	boolean finita(){
		return isFinita;
	}
}
