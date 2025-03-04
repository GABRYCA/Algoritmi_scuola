package ThreadEs5;

/**
 * Thread runs as soon as is created. It prints 3 times "Thread" while the main prints "Main".
 * */
public class Main {

	public static void main(String[] args) {
		//Thread thread = new Thread1();
		new Thread1();
		for (int i = 0; i < 3; i++) System.out.println("Main");
	}

}
