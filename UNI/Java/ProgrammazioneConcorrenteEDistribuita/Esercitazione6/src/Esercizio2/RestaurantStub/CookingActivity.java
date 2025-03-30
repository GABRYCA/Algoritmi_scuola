package Esercizio2.RestaurantStub;

public class CookingActivity extends Thread {
	private Kitchen myKitchen;
	private String servedOrder;

	public CookingActivity(Kitchen k, String o) {
		myKitchen = k;
		servedOrder = o;
		start();
	}

	public void run() {
		// esegue la preparazione dell'ordine (mettendoci un po' di tempo)
		// informa di aver terminato
	}
}
