package Esercizio2;

import java.io.IOException;
import java.net.InetAddress;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

class ClientThread extends Thread {

	private static int threadcount = 0;
	private int myID;
	BankProxy myBank;
	public Result res;

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

	// method simulating some activity
	private void doSometing() {
		boolean finished = false;
		while (!finished) {
			System.out.println("client working");
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(1000, 1500));
			} catch (InterruptedException e) {
			}
			finished = res.isCompleted();
		}
		System.out.println("Client thread " + myID + " exiting doSomething *********");
	}

	public void run() {
		String opType = null;
		Random rand = new Random();
		System.out.println("Client_" + myID + " running");
		int howMuch = 0;
		int times = (rand.nextInt(10)) + 2;
		try {
			for (int i = 0; i < times; i++) {
				howMuch = new Random().nextInt(1000);
				opType = rand.nextBoolean() ? "Deposit" : "Withdraw";
				res = new Result(myID, howMuch, opType, false);
				System.out.println("Client " + myID + " requests " + opType + " " + howMuch);
				myBank.executeOperation(res, new OperationRequest(myID, howMuch, opType));
				doSometing();
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
