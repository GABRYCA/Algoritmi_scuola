package Esercizio1.SolProxy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class SegmentSlave extends Thread {
	private Socket socket;
	private BufferedReader in;
	private PrintWriter out;
	private Segment seg;

	public SegmentSlave(Socket s) {
		socket = s;
		start();
	}

	public void run() {
		boolean finito = false;
		String str, s1, s2;
		try {
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
			while (!finito) {
				str = in.readLine();
				System.out.println("Received: " + str);
				if (str.equals("END"))
					finito = true;
				else if (str.equals("NewSegment")) {
					// legge le coordinate di due Point
					s1 = in.readLine();
					s2 = in.readLine();
					Point p1 = new Point(Double.parseDouble(s1), Double.parseDouble(s2));
					s1 = in.readLine();
					s2 = in.readLine();
					Point p2 = new Point(Double.parseDouble(s1), Double.parseDouble(s2));
					seg = new Segment();
					boolean res = seg.set(p1, p2);
					if (res) {
						out.println("OK");
						System.out.println("Server: segment created");
					} else {
						out.println("KO");
						System.out.println("Server: segment creation failed");
					}
				} else if (str.equals("Simmetric")) {
					// legge un oggetto di classe Point
					System.out.println("Server: simmetric computation started");
					s1 = in.readLine();
					s2 = in.readLine();
					Point p = new Point(Double.parseDouble(s1), Double.parseDouble(s2));
					System.out.println("Server: simmetric argument" + " " + p.getX() + " " + p.getY());
					Point ps = seg.symmetric(p);
					System.out.println("Server: computed simmetric" + " " + ps.getX() + " " + ps.getY());
					out.println(Double.toString(ps.getX()));
					out.println(Double.toString(ps.getY()));
					System.out.println("Server: sent simmetric");
				}
			}
			System.out.println("closing...");
		} catch (IOException e) {
			System.err.println("IO Exception");
		} finally {
			try {
				socket.close();
			} catch (IOException e) {
			}
		}
	}
}
