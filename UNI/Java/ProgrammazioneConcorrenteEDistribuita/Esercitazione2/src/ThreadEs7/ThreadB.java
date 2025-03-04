package ThreadEs7;

public class ThreadB extends Thread {

	public void run() {
		int x = 2;
		while(true) {
			System.out.println("Ciao");
			for(int i = 0; i < 1000; i++) {
				for (int j = 0; j < 1000; j++) {
					for (int k = 0; k < 1000; k++) {
						x = 2 - x;
					}
				}
			}
			if (this.isInterrupted()) {
				System.out.println("Termino");
				break;
			}
		}
	}
	
	public ThreadB() {
		this.start();
	}
}
