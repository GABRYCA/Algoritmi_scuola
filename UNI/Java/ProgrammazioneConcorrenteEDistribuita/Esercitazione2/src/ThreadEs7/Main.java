package ThreadEs7;

import java.util.Scanner;

/**
 * Three types of threads, edit "tipo" to choose.
 * Threads print "Ciao" until "fine" input command.
 * */
public class Main {

	/**
	 * Choose types (tipo):
	 * 0 - Sleep
	 * 1 - Cycle
	 * 2 - Cycle followed by Sleep
	 * */
	public static void main(String[] args) {
		int tipo = 2;
		Thread thread;
		switch (tipo) {
			case 0: {
				thread = new ThreadA();
				break;
			}
			case 1: {
				thread = new ThreadB();
				break;
			}
			case 2: {
				thread = new ThreadC();
				break;
			}
			default: {
				System.out.println("Tipo non valido!");
				return;
			}
		}
		
		String input;
		Scanner in = new Scanner(System.in);
		while (true) {
			System.out.println("inserire comando ('fine' per terminare): ");
			input = in.next();
			if (input.equalsIgnoreCase("Fine")) {
				thread.interrupt();
				System.out.println("Letto " + input + ", termino!");
				break;
			} else {
				System.out.println("Letto: " + input);
			}
		}
		in.close();
	}
}
