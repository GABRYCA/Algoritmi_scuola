package Esercizio2.Restaurant;

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

	public synchronized void putOrder(String order) {
		System.out.println("Kitchen takes order " + order);
		ordersToServe.add(order);
		notifyAll();
	}

	public synchronized boolean isOrderReady(String order) {
		System.out.println("checking if " + order + " is ready");
		while (!ordersReady.contains(order)) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		ordersReady.remove(order);
		return true;
	}

	public synchronized String getNextOrder() throws InterruptedException {
		String orderToServe = null;
		while (ordersToServe.size() == 0) {
			System.out.println("getNextOrder: no orders, thus waiting");
			wait();
		}
		orderToServe = ordersToServe.removeFirst();
		return orderToServe;
	}

	public synchronized void finished(String o) {
		ordersReady.add(o);
		ongoingCookingActivities--;
		notifyAll();
	}

	public synchronized void prepare(String orderToServe) {
		while (ongoingCookingActivities >= MAX_ACTIVITIES) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		ongoingCookingActivities++;
		new CookingActivity(this, orderToServe);
	}
}
