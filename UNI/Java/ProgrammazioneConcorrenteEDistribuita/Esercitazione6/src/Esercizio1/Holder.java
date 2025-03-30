package Esercizio1;

public class Holder extends Thread {
	private BeerAwaiters drinkers;
	private int freeBeersServed;
	private final int MAX_BEERS = 22;
	private ServedBeers deliveredBeers;

	public Holder(BeerAwaiters ba, ServedBeers sb) {
		this.drinkers = ba;
		this.freeBeersServed = 0;
		this.deliveredBeers = sb;
	}

	public void run() {
		String toServe;
		for (int i = 1; i <= MAX_BEERS; ++i) {
			toServe = drinkers.get();
			System.out.println("Holder" + ": serving beer (" + ++freeBeersServed + ") to " + toServe);
			deliveredBeers.serve(toServe);
		}
		System.out.println("Holder" + ": no more free beer! ");
	}
}
