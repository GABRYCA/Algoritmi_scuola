package ThreadEs3;

/**
 * Thread prints 3 times his own name, and main prints 3 times "Main".
 * */
public class Main {

	public static void main(String[] args) {
		Thread thread = new ThreadNome("NomeThread");
		thread.start();
		for (int i = 0; i < 3; i++) System.out.println("Main");
	}

}
