package Esercizio4;

public class Main {

	public static final int NUM_PHIL = 5;
	static Philosopher[] phils = new Philosopher[NUM_PHIL];
	static Chopstick[] sticks = new Chopstick[NUM_PHIL];

	public static void main(String[] args) {
		
		for (int i = 0; i < NUM_PHIL; i++) sticks[i] = new Chopstick(i);
		
		System.out.println("Bacchette create");
		for (int i = 0; i < NUM_PHIL; i++) {
			int left = i - 1;
			if (left < 0) {
				left = NUM_PHIL - 1;
			}
			int right = i;
			System.out.println("Creando filosofo con " + left + " " + right);
			phils[i] = new Philosopher(i, sticks[left], sticks[right]);
		}
		
		System.out.println("Filosofo creato");
		for (int i = 0; i < NUM_PHIL; i++) sticks[i].setOwner((i + 1 == NUM_PHIL) ? 0 : i);
		
		System.out.println("Impostati i proprietari delle bacchette");
		for (int i = 0; i < NUM_PHIL; i++) phils[i].start();
	}

}
