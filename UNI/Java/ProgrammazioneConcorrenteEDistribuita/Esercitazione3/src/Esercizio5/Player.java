package Esercizio5;

import java.util.concurrent.ThreadLocalRandom;

public class Player extends Thread {
	
	int myId;
	Table myTable;
	
	public Player(int id, Table t){
		this.myId=id;
		this.myTable=t;
		this.start();
	}
	
	public void run(){
		boolean continuo=false;
		int dado1;
		int dado2;
		while(!myTable.finita()){
			continuo=true;
			while(continuo && !myTable.finita()){
				dado1=(int)(6*Math.random());
				dado2=(int)(6*Math.random());
				continuo=(dado1==dado2);
				myTable.mossa(myId, dado1, dado2);
				System.out.println("Giocatore "+myId+" ha mosso ["+dado1+","+dado2+"]");
			}
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(100, 300));
			} catch (InterruptedException e1) {	}
		}
	}
}
