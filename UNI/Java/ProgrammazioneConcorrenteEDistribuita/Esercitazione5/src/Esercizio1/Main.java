package Esercizio1;

import Esercizio1.Blocking.TableBlocking;
import Esercizio1.Polling.TablePolling;

public class Main {

	public static void main(String[] args) {
		System.out.println("Avvio programma dei filosofi (Philosophers)...");
		System.out.println("Filosofi con Blocking: ");
		TableBlocking tBlocking = new TableBlocking();
		
		System.out.println("Filosofi con Polling: ");
		TablePolling tPolling = new TablePolling();
		
		System.out.println("Fine!");
	}

}
