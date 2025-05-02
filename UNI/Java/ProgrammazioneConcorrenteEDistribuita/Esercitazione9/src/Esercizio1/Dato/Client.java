package Esercizio1.Dato;

import java.util.Random;

public class Client {
	Bank myBank;
	int myAccountNum;

	Client(int accNum, Bank b) {
		myBank = b;
		myAccountNum = accNum;
	}

	public void exec() {
		Result r;
		int howMuch = 0;
		int times = new Random().nextInt(10);
		for (int i = 0; i < times; i++) {
			howMuch = new Random().nextInt(1000);
			if (new Random().nextBoolean()) {
				r = myBank.executeOperation(new OperationRequest(1, howMuch, "Deposit"));
			} else {
				r = myBank.executeOperation(new OperationRequest(1, howMuch, "Withdraw"));
			}
			System.out.println(r);
		}
		r = myBank.executeOperation(new OperationRequest(1, 2, "Double"));
		System.out.println(r);
	}

	public static void main(String[] args) {
		Client c = new Client(1, new Bank());
		c.exec();
	}
}
