package ThreadEs4;

/**
 * Thread prints his name 3 times and implements Runnable. Main prints 3 times "Main".
 * */
public class Main {

	public static void main(String[] args) {
		Thread thread = new Thread(new ThreadRunNome(), "ThreadNome");
		thread.start();
		for (int i = 0; i < 3; i++) System.out.println("Main");
	}

}
