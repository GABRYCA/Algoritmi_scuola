package Esercizio1;

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
		Object o1 = null;
		Object o2 = null;
		try {
			out = new ObjectOutputStream(socket.getOutputStream());
			in = new ObjectInputStream(socket.getInputStream());
			while (!finito) {
				str = (String) in.readObject();
				System.out.println("Received: " + str);
				if (str.equals("END"))
					finito = true;
				else if (str.equals("NewSegment")) {
					o1 = in.readObject();
					o2 = in.readObject();
					String res = segmNew(o1, o2);
					out.writeObject(res);
				} else if (str.equals("Symmetric")) {
					o1 = in.readObject();
					out.writeObject(segSymmetric(o1));
				} else if (str.equals("MidPoint")) {
					out.writeObject(segMedian());
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

	private String segmNew(Object o1, Object o2) {
		try {
			seg = new Segment((Point) o1, (Point) o2);
			System.out.println("Server: segment created");
			return ("OK");
		} catch (PointCreationFailed e) {
			System.out.println("Server: segment creation failed");
			return ("KO");
		}
	}

	private Object segSymmetric(Object o) {
		return seg.symmetric((Point) o);
	}

	private Object segMedian() {
		return seg.midPoint();

	}
}
