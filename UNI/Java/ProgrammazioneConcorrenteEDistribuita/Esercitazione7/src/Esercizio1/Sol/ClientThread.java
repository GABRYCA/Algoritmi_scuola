package Esercizio1.Sol;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.concurrent.ThreadLocalRandom;

class ClientThread extends Thread {
	private Socket socket;
	private BufferedReader in;
	private PrintWriter out;
	private static int threadcount = 0;
	private int myID;

	public static int threadCount() {
		return threadcount;
	}

	public ClientThread(InetAddress addr, int id) {
		System.out.println("Making client " + id);
		myID = id;
		threadcount++;
		try {
			socket = new Socket(addr, 8080);
		} catch (IOException e) {
			System.err.println("Socket failed");
		}
		try {
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
			start();
		} catch (IOException e) {
			try {
				threadcount--;
				socket.close();
			} catch (IOException e2) {
				System.err.println("Socket not closed");
			}
		}
	}

	void mySleep(int t1, int t2) {
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(t1, t2));
		} catch (InterruptedException e) {
		}
	}

	public void run() {
		try {
			for (int i = 0; i < 5; i++) {
				mySleep(100, 200);
				boolean segmentOK = false;
				while (!segmentOK) {
					System.out.println("Client_" + myID + ": asking for segment creation");
					out.println("NewSegment");
					Point p1 = new Point(100 * Math.random(), 100 * Math.random());
					System.out.println("Client_" + myID + " point 1: (" + p1.getX() + " " + p1.getY() + ")");
					out.println(p1.getX());
					out.println(p1.getY());
					Point p2 = new Point(100 * Math.random(), 100 * Math.random());
					System.out.println("Client_" + myID + " point 2: (" + p2.getX() + " " + p2.getY() + ")");
					out.println(p2.getX());
					out.println(p2.getY());
					String str = in.readLine();
					if (str.equals("OK")) {
						segmentOK = true;
					}
					mySleep(2, 8);
					System.out.println("Client_" + myID + ": segment creation response received: " + str);
				}
				mySleep(10, 20);
				out.println("Simmetric");
				Point px = new Point(100 * Math.random(), 100 * Math.random());
				System.out.println("Client_" + myID + " given point: (" + px.getX() + " " + px.getY() + ")");
				out.println(px.getX());
				out.println(px.getY());
				String s1 = in.readLine();
				String s2 = in.readLine();
				Point ps = new Point(Double.parseDouble(s1), Double.parseDouble(s2));
				System.out.println("Client_" + myID + " received point: (" + ps.getX() + " " + ps.getY() + ")");
			}
			out.println("END");
		} catch (IOException e) {
			System.err.println("IO Exception");
		} finally { // Always close it:
			try {
				socket.close();
			} catch (IOException e) {
				System.err.println("Socket not closed");
			}
			threadcount--; // Ending this thread
		}
	}
}
