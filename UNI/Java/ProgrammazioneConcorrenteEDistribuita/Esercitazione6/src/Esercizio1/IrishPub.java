package Esercizio1;

public class IrishPub {
	
	public final static int NUM_MUSICIANS=8;

	public static void main(String[] args) {
		BeerAwaiters thirstyMusicians = new BeerAwaiters(NUM_MUSICIANS + 1);
		ServedBeers servedBeers = new ServedBeers();
		Holder holder = new Holder(thirstyMusicians, servedBeers);
		holder.start();
		Musician musicians[] = new Musician[NUM_MUSICIANS];
		for (int i = 0; i < NUM_MUSICIANS; i++) {
			musicians[i] = new Musician("Musician_" + i, thirstyMusicians, servedBeers);
			musicians[i].start();
		}
		for (int i = 0; i < NUM_MUSICIANS; i++) {
			try {
				musicians[i].join();
			} catch (InterruptedException e) {}
		}
		System.out.println("The pub closes.");
	}

}
