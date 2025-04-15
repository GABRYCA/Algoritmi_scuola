package Esercizio1;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.concurrent.ThreadLocalRandom;

class ClientThread extends Thread {
	private static int threadcount = 0;
	private int myID;
	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;

	public static int threadCount() {
		return threadcount;
	}

	public ClientThread(InetAddress addr, int portNum, int id) throws IOException {
		System.out.println("Making client " + id);
		myID = id;
		synchronized (ClientThread.class) {
			threadcount++;
		}
		setConnection(addr, portNum);
		this.start();
	}

	void mySleep(int t1, int t2) {
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(t1, t2));
		} catch (InterruptedException e) {
		}
	}

	public void run() {
		System.out.println("Client " + myID + " running");
		try {
			for (int i = 0; i < 5; i++) {
				mySleep(100, 200);
				boolean segmentOK = false;
				while (!segmentOK) {
					System.out.println("Client_" + myID + ": asking for segment creation");
					Point p1 = new Point(100 * Math.random(), 100 * Math.random());
					System.out.println("Client_" + myID + " point 1: (" + p1.getX() + " " + p1.getY() + ")");
					Point p2 = new Point(100 * Math.random(), 100 * Math.random());
					System.out.println("Client_" + myID + " point 2: (" + p2.getX() + " " + p2.getY() + ")");
					segmentOK = newPoint(p1, p2);
					mySleep(2, 8);
				}
				System.out.println("Client_" + myID + ": segment created");
				mySleep(10, 20);
				Point px = new Point(100 * Math.random(), 100 * Math.random());
				System.out.println("Client_" + myID + " given point: (" + px.getX() + " " + px.getY() + ")");
				Point ps = symmetric(px);
				System.out.println("Client_" + myID + " simmetric point: (" + ps.getX() + " " + ps.getY() + ")");
			}
			finish();
		} catch (ClassNotFoundException | IOException e) {
			e.printStackTrace();
		}
		synchronized (ClientThread.class) {
			threadcount--;
		}
	}

	void setConnection(InetAddress addr, int portNum) throws IOException {
		socket = new Socket(addr, portNum);
		out = new ObjectOutputStream(socket.getOutputStream());
		in = new ObjectInputStream(socket.getInputStream());
	}

	void finish() throws IOException {
		System.out.println("Client_" + myID + ": closing");
		out.writeObject("END");
	}

	private boolean newPoint(Point p1, Point p2) throws IOException, ClassNotFoundException {
		out.writeObject("NewSegment");
		out.writeObject(p1);
		out.writeObject(p2);
		String str = (String) in.readObject();
		return (str.equals("OK"));
	}

	private Point symmetric(Point p) throws IOException, ClassNotFoundException {
		out.writeObject("Symmetric");
		out.writeObject(p);
		return ((Point) in.readObject());
	}
}
