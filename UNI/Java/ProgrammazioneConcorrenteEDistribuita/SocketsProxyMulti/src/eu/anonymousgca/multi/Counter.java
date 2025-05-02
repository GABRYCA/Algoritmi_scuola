package eu.anonymousgca.multi;

import java.io.IOException;

public class Counter implements ServerInterface {
	private int valore = 0;

	public Counter() {
		System.out.println("Inizializzato il contatore, valore: " + valore);
	}

	@Override
	public synchronized int reset() throws IOException {
		return valore = 0;
	}

	@Override
	public synchronized int increment() throws IOException {
		return ++valore;
	}

	public synchronized int getValore() {
		return valore;
	}
}
