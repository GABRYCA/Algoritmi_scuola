package Esercizio3.fair_no_waiter;

public class TableFairNoWaiter {
	
	   public static final int NUM_PHIL = 5;
	   public static final int NUM_STICKS = 5;
	   
	   public TableFairNoWaiter() {
		   Pool p = new Pool(NUM_PHIL, NUM_STICKS);
		   for(int i=0; i<NUM_PHIL; i++) new Philosopher(i, p).start();
	   }

}
