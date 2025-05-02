package eu.anonymousgca.multi;

import java.io.IOException;

public class Client implements Runnable {
	private String clientId;
	private int incrementi = 10;
	
	public Client(String id) {
		this.clientId = id;
		System.out.println("Client creato: " + clientId);
	}

	@Override
	public void run() {
		System.out.println("Client avviato: " + clientId);
		
		try {
			Proxy proxy = new Proxy();
			
			for (int i = 0; i < incrementi; i++) {
				System.out.println("Il client " + clientId + " sta eseguendo un incremento, il " + (i+1) + "/" + incrementi);
				int valore = proxy.increment();
				System.out.println("Incremento effettuato, nuovo valore: " + valore);
			}
			
			System.out.println("Finiti incrementi, chiusura...");
			proxy.close(); // Credo sia superfluo, AutoCloseable dovrebbe chiuderlo in automatico
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
