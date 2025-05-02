package Esercizio1.MultiClient;

public class MultiClient {
	public static void main(String[] args) {
		Bank theBank = new Bank(3);
		new ClientThread(0, theBank).start();
		new ClientThread(1, theBank).start();
		new ClientThread(2, theBank).start();
	}
}
