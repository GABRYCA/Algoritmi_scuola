package Esercizio3.fair;

public class Waiter extends Thread{
	Pool pool;
	
	Waiter(Pool p){
		pool=p;
		this.start();
	}
	
	public void run() {
		while(true) pool.scheduleNext();
	}
}

