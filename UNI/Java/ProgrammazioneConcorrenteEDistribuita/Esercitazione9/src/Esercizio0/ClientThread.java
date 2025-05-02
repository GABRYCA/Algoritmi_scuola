package Esercizio0;

import java.io.IOException;
import java.net.InetAddress;
import java.util.concurrent.ThreadLocalRandom;

class ClientThread extends Thread {
	private static int threadcount = 0;
	private int myID;
	SegmentProxy sps;

	public static int threadCount() {
		return threadcount;
	}

	public ClientThread(InetAddress addr, int portNum, int id) throws IOException {
		System.out.println("Making client " + id);
		myID = id;
		synchronized (ClientThread.class) {
			threadcount++;
		}
		sps = new SegmentProxy(addr, portNum);
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
		for (int i = 0; i < 5; i++) {
			mySleep(100, 200);
			boolean segmentOK = false;
			while (!segmentOK) {
				System.out.println("Client_" + myID + ": asking for segment creation");
				Point p1 = new Point(100 * Math.random(), 100 * Math.random());
				System.out.println("Client_" + myID + " point 1: (" + p1.getX() + " " + p1.getY() + ")");
				Point p2 = new Point(100 * Math.random(), 100 * Math.random());
				System.out.println("Client_" + myID + " point 2: (" + p2.getX() + " " + p2.getY() + ")");
				segmentOK = sps.set(p1, p2);
				mySleep(2, 8);
			}
			System.out.println("Client_" + myID + ": segment created");
			mySleep(10, 20);
			Point px = new Point(100 * Math.random(), 100 * Math.random());
			System.out.println("Client_" + myID + " given point: (" + px.getX() + " " + px.getY() + ")");
			Point ps = sps.simmetric(px);
			System.out.println("Client_" + myID + " simmetric point: (" + ps.getX() + " " + ps.getY() + ")");
		}
		sps.quit();
		synchronized (ClientThread.class) {
			threadcount--;
		}
	}
}
