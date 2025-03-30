package Esercizio1;

import java.util.ArrayList;
import java.util.List;

public class ServedBeers {
	private List<String> servedMusicians;

	ServedBeers() {
		servedMusicians = new ArrayList<String>();
	}

	synchronized void printout() {
		System.out.print("[");
		for (String s : servedMusicians) System.out.print(s + " ");
		System.out.println("]");
	}

	public synchronized void serve(String s) {
		servedMusicians.add(s);
		notifyAll();
	}

	public synchronized boolean fetch(String s) {
		long startTime = System.currentTimeMillis();
		long waitTime = 400;
		while (!servedMusicians.contains(s) && waitTime > 0) {
			try {
				wait(waitTime);
			} catch (InterruptedException e) {}
			waitTime = Math.max(0, waitTime - (System.currentTimeMillis() - startTime));
		}
		if (servedMusicians.contains(s)) {
			servedMusicians.remove(s);
			return true;
		} else {
			return false;
		}
	}
}