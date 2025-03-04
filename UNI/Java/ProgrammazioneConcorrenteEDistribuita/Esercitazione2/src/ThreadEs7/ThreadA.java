package ThreadEs7;

public class ThreadA extends Thread {
	public void run() {
		while (true) {
			System.out.println("Ciao");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				System.out.println("Termino");
				break;
			}
		}
	}
	
	public ThreadA() {
		this.start();
	}
}
