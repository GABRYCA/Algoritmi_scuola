package Esercizio1.Blocking;

public class TableBlocking {
	private static final int NUM_PHIL = 5;
	private static final int NUM_STICKS = 5;
	private static Pool pool = new Pool(NUM_STICKS);

	public TableBlocking() {
		for (int i = 0; i < NUM_PHIL; i++) new Philosopher("F" + (i + 1), pool).start();
	}
}
