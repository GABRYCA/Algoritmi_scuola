package Esercizio1.MultiClient;

import java.util.Random;

public class ClientThread extends Thread {
	Bank myBank;
	int myAccountNum;

	ClientThread(int accNum, Bank b) {
		myBank = b;
		myAccountNum = accNum;
	}

	public void run() {
		Result r;
		int howMuch = 0;
		int times = (new Random().nextInt(10)) + 2;
		for (int i = 0; i < times; i++) {
			howMuch = new Random().nextInt(1000);
			if (new Random().nextBoolean()) {
				r = myBank.executeOperation(new OperationRequest(myAccountNum, howMuch, "Deposit"));
			} else {
				r = myBank.executeOperation(new OperationRequest(myAccountNum, howMuch, "Withdraw"));
			}
			System.out.println(r);
		}
		r = myBank.executeOperation(new OperationRequest(myAccountNum, 2, "Double"));
		System.out.println(r);
	}
}
