package Esercizio4;

import java.util.concurrent.ThreadLocalRandom;

public class Scambio extends Thread {
	int id;
	String nome;
	Tavolo tavolo;
	
	public Scambio(int id, String nome, Tavolo t) {
		this.id = id;
		this.nome = nome;
		this.tavolo = t;
	}
	
	public void run() {
		while (true) {
			tavolo.scambioInCorso(id); // Aspetto che lo scambio sia completato
			System.out.println(nome + " sta scambiando");
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(300, 800));
			} catch (InterruptedException e) {}
			tavolo.scambioCompletato();
		}
	}

}
