package eu.anonymousgca.multi;

public class MainClient {
	
	private static final int NumClient = 5;
	

	public static void main(String[] args) {
		System.out.println("Avviando il client MultiClient con " + NumClient);
		Thread[] threads = new Thread[NumClient];
		
		for (int i = 0; i < NumClient; i++) {
			Client client = new Client("Client " + i); // Creo client
			
			threads[i] = new Thread(client, "Thread: " + i); // Creo Thread con client
			
			threads[i].start(); // Avvio thread
		}
		
		System.out.println("Creati e avviati tutti i client...");
		
		for (Thread t : threads) {
			try {
				t.join();
			} catch (InterruptedException e) {
				System.err.println("Errore durante il join del thread: " + t.getName());
				Thread.currentThread().interrupt();
			}
		}
		
		System.out.println("Chiusi tutti i client");
	}

}
