package Esercizio1;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

class ClientThread extends Thread {
	private Socket socket;
	private ObjectInputStream ins;
	private ObjectOutputStream outs;
	private static int threadcount = 0;
	private int myID;

	public static int threadCount() {
		return threadcount;
	}

	public ClientThread(InetAddress addr, int id) throws IOException {
		System.out.println("Making client " + id);
		myID = id;
		socket = new Socket(addr, Server.PORT);
		synchronized (ClientThread.class) {
			threadcount++;
		}
		try {
			outs = new ObjectOutputStream(socket.getOutputStream());
			ins = new ObjectInputStream(socket.getInputStream());
			start();
		} catch (IOException e) {
			try {
				System.out.println("Client_" + myID + " stream creation KO");
				synchronized (ClientThread.class) {
					threadcount--;
				}
				socket.close();
			} catch (IOException e2) {
				System.err.println("Socket not closed");
			}
		}
	}

	public void run() {
		Result res;
		Random rand = new Random();

		System.out.println("Client_" + myID + " running");
		try {
			for (int i = 0; i < 3; i++) {
				outs.writeObject(new OperationRequest(myID, rand.nextInt(50), "Deposit"));
				res = (Result) ins.readObject();
				if (res.isSuccessful()) {
					System.out.println("Client_" + myID + " operation succeeded; total is " + res.getAmount());
				} else {
					System.out.println("Client_" + myID + " operation failed");
				}
				Thread.sleep(ThreadLocalRandom.current().nextInt(1, 4));
				outs.writeObject(new OperationRequest(myID, rand.nextInt(50), "Withdraw"));
				res = (Result) ins.readObject();
				if (res.isSuccessful()) {
					System.out.println("Client_" + myID + " operation succeeded; total is " + res.getAmount());
				} else {
					System.out.println("Client_" + myID + " operation failed");
				}
				Thread.sleep(ThreadLocalRandom.current().nextInt(1, 4));
			}
			outs.writeObject(new OperationRequest(-1, 0, "END"));
		} catch (IOException e) {
			System.err.println("IO Exception, sorbole!");
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} finally {
			try {
				socket.close();
			} catch (IOException e) {
				System.err.println("Socket not closed");
			}
			synchronized (ClientThread.class) {
				threadcount--;
			}
		}
	}
}
