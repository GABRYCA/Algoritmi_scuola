package Esercizio1.SolProxy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class SegmentProxy implements SegmentInterface {
	Socket socket;
	private BufferedReader in;
	private PrintWriter out;

	SegmentProxy(InetAddress addr, int portNum) {
		try {
			socket = new Socket(addr, portNum);
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
		} catch (IOException e) {
			System.err.println("Socket failed");
		}
	}

	public boolean set(Point p1, Point p2) {
		out.println("NewSegment");
		out.println(p1.getX());
		out.println(p1.getY());
		out.println(p2.getX());
		out.println(p2.getY());
		String str;
		try {
			str = in.readLine();
		} catch (IOException e) {
			return false;
		}
		return (str.equals("OK"));
	}

	public Point symmetric(Point px) {
		String s1;
		String s2;
		out.println("Simmetric");
		out.println(px.getX());
		out.println(px.getY());
		try {
			s1 = in.readLine();
			s2 = in.readLine();
		} catch (IOException e) {
			return null;
		}
		return new Point(Double.parseDouble(s1), Double.parseDouble(s2));
	}

	public void quit() {
		out.println("END");
	}
}
