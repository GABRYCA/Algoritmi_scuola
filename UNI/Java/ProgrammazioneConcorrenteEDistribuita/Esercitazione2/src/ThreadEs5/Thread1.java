package ThreadEs5;

public class Thread1 extends Thread {
	public void run() {
		for (int i = 0; i < 3; i++) System.out.println("Thread");
	}

	public Thread1() {
		this.start();
	}
	
}
