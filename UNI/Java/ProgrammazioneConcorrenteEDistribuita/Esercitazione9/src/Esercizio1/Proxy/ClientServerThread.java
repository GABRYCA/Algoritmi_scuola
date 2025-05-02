package Esercizio1.Proxy;

import java.io.IOException;
import java.net.InetAddress;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

class ClientThread extends Thread {

	// private static int counter = 0;
	private static int threadcount = 0;
	private int myID;
	BankProxy myBank;

	public static int threadCount() {
		return threadcount;
	}

	public ClientThread(InetAddress addr, int id) {
		System.out.println("Making client " + id);
		myID = id;
		synchronized (ClientThread.class) {
			threadcount++;
		}
		try {
			myBank = new BankProxy(addr);
			this.start();
		} catch (IOException e) {
			System.err.println("Client " + myID + ": proxy creation failed");
			synchronized (ClientThread.class) {
				threadcount--;
			}
		}
	}

	public void run() {
		Result res;
		Random rand = new Random();
		System.out.println("Client_" + myID + " running");
		int howMuch = 0;
		int times = (rand.nextInt(10)) + 2;
		try {
			for (int i = 0; i < times; i++) {
				howMuch = new Random().nextInt(1000);
				if (new Random().nextBoolean()) {
					res = myBank.executeOperation(new OperationRequest(myID, howMuch, "Deposit"));
				} else {
					res = myBank.executeOperation(new OperationRequest(myID, howMuch, "Withdraw"));
				}
				System.out.println(res);
				try {
					Thread.sleep(ThreadLocalRandom.current().nextInt(1, 4));
				} catch (InterruptedException e) {
				}
			}
			myBank.quit();
		} finally {
			synchronized (ClientThread.class) {
				threadcount--;
			}
		}
	}
}
