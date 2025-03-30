package Esercizio2.RestaurantStub;

import java.util.HashSet;
import java.util.LinkedList;

public class Kitchen {
	private final int MAX_ACTIVITIES = 4;
	private LinkedList<String> ordersToServe;
	public HashSet<String> ordersReady;
	int ongoingCookingActivities = 0;

	public Kitchen() {
		ordersToServe = new LinkedList<String>();
		ordersReady = new HashSet<String>();
		ongoingCookingActivities = 0;
	}

	private synchronized void printReadyOrders() {
		System.out.print("ready: [");
		for (String ol : ordersReady) {
			System.out.print(ol.toString() + " ");
		}
		System.out.println("]");
	}

	private synchronized void printPendingOrders() {
		System.out.print("to be prepared: [");
		for (String ol : ordersToServe) {
			System.out.print(ol.toString() + " ");
		}
		System.out.println("]");
	}

}