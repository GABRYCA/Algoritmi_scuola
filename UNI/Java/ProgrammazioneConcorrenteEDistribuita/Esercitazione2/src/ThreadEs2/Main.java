package ThreadEs2;

/**
 * Thread implements Runnable and prints 3 times "Thread". Main prints 3 times "Main".
 * */
public class Main {

	public static void main(String[] args) {
		Thread threadRunnable = new Thread(new ThreadRunnable());
		threadRunnable.start();
		for (int i = 0; i < 3; i++) System.out.println("Main");
	}

}
