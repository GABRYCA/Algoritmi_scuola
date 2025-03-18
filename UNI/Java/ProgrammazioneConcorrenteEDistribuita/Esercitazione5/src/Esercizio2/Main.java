package Esercizio2;

public class Main {
	private static final int NUM_PHIL = 5;
	private static final int NUM_STICKS = 5;
	private static Pool pool = new Pool(NUM_STICKS, NUM_PHIL);

	public static void main(String[] args) {
		for (int i = 0; i < NUM_PHIL; i++) new Philosopher(i, pool).start();
	}

}
