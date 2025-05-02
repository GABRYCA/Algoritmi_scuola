package Esercizio0;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class SegmentSlave extends Thread {
	private Socket socket;
	private Segment seg;

	public SegmentSlave(Socket s) {
		socket = s;
		start();
	}

	public void run() {
		boolean finito = false;
		String str;
		ObjectInputStream in;
		ObjectOutputStream out;
		Point p1 = null;
		Point p2 = null;
		try {
			out = new ObjectOutputStream(socket.getOutputStream());
			in = new ObjectInputStream(socket.getInputStream());
			while (!finito) {
				str = (String) in.readObject();
				System.out.println("Received: " + str);
				if (str.equals("END"))
					finito = true;
				else if (str.equals("NewSegment")) {
					p1 = (Point) in.readObject();
					p2 = (Point) in.readObject();
					seg = new Segment();
					boolean res = seg.set(p1, p2);
					if (res) {
						out.writeObject("OK");
						System.out.println("Server: segment created");
					} else {
						out.writeObject("KO");
						System.out.println("Server: segment creation failed");
					}
				} else if (str.equals("Simmetric")) {
					System.out.println("Server: simmetric computation started");
					p1 = (Point) in.readObject();
					System.out.println("Server: simmetric argument" + " " + p1.getX() + " " + p1.getY());
					p2 = seg.simmetric(p1);
					System.out.println("Server: computed simmetric" + " " + p2.getX() + " " + p2.getY());
					out.writeObject(p2);
					System.out.println("Server: sent simmetric");
				}
			}
			System.out.println("closing...");
		} catch (IOException e) {
			System.err.println("IO Exception");
		} catch (ClassNotFoundException e) {
			System.err.println("Class Point non found");
		} finally {
			try {
				socket.close();
			} catch (IOException e) {
			}
		}
	}
}
