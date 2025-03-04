package ThreadEs4;

public class ThreadRunNome implements Runnable {
	public void run() {
		for (int i = 0; i < 3; i++) System.out.println(Thread.currentThread().getName());
	}
	
	public ThreadRunNome() {}

}
