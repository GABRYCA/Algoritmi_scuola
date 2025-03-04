package ThreadEs1;

public class Thread1 extends Thread {
	public void run() {
		for (int i = 0; i < 3; i++) {
			System.out.println("thread");
		}
	}
	
	public Thread1() {
		
	}
}
