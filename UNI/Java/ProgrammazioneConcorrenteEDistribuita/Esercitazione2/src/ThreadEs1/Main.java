package ThreadEs1;

/**
 * Thread prints 3 times "Thread", and main prints 3 times "Main".
 * */
public class Main {

	public static void main(String[] args) {
		Thread thread = new Thread1();
		thread.start();
		for(int i = 0; i < 3; i++) {
			System.out.println("Main");
		}
	}

}
