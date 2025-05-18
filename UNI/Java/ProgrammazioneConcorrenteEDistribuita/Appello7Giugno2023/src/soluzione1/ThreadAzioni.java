package soluzione1;

import java.util.concurrent.ThreadLocalRandom;

public class ThreadAzioni extends Thread {
	
	Dati dati;
	int nome;
	
	public ThreadAzioni(Dati dati, int nome) {
		this.dati = dati;
		this.nome = nome;
	}
	
	public void run() {
		
		for (int i = 0; i < 10; i++) {
			if (ThreadLocalRandom.current().nextBoolean()) {
				String randomKey = "Chiave-" + ThreadLocalRandom.current().nextInt(10);
				String randomData = "Dato-" + ThreadLocalRandom.current().nextInt(10);
				System.out.println(nome + " sta scrivendo dato -> " + randomKey + ":" + randomData);
				dati.aggiungiDato(randomKey, randomData);
			} else {
				String randomKey = "Chiave-" + ThreadLocalRandom.current().nextInt(10);
				System.out.println(nome + " sta leggendo dato con chiave -> " + randomKey);
				if (dati.esisteDato(randomKey)) {
					System.out.println(nome + " trovato dato -> " + randomKey + ":" + dati.trovaDato(randomKey));
				} else {
					System.out.println(nome + " non ha trovato alcun dato con chiave -> " + randomKey);
				}
			}
		}
		
		return;
	}
	
}
