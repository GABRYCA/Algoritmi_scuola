package Esercizio3.basic;

public class TableBasic {
	public static final int NUM_PHIL = 5;
	public static final int NUM_STICKS = 5;

	public TableBasic() {
		Pool p = new Pool(NUM_PHIL, NUM_STICKS);
		new Waiter(p);
		for (int i = 0; i < NUM_PHIL; i++) new Philosopher(i, p).start();

	}

}
