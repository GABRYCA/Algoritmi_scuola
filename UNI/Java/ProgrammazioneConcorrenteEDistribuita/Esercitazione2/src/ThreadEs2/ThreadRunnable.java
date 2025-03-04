package ThreadEs2;

public class ThreadRunnable implements Runnable {
	public void run() {
		for (int i = 0; i < 3; i++) System.out.println("Thread");
	}
	
	public ThreadRunnable() {}

}
