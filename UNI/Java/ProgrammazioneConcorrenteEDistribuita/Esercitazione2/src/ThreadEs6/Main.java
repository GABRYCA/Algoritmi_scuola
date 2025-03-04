package ThreadEs6;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws InterruptedException {
		int numeroThread;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("Inserire numero Thread, tra 1 e 5 (estremi compresi):");
		try {
			numeroThread = Integer.parseInt(reader.readLine());
		} catch (Exception e) {
			System.out.println("Input non valido, per favore riprovare!");
			return;
		}
		
		if (numeroThread < 1 || numeroThread > 5) {
			System.out.println("Il numero " + numeroThread + " non è compreso tra 1 e 5");
			return;
		}
		
		Thread[] threads = new Thread[numeroThread];
		for (int i = 0; i < numeroThread; i++) {
			threads[i] = new ThreadNumero(i);
			threads[i].start();
		}
		for(int i = 0; i < numeroThread; i++) {
			threads[i].join();
		}
		
		System.out.println("Fine!");
	}

}
