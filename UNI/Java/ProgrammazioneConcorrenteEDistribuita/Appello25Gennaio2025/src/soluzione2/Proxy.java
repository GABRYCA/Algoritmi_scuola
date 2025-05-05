package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class Proxy implements AutoCloseable {

	private Socket socket = null;
	private ObjectOutputStream out = null;
	private ObjectInputStream in = null;

	public Proxy() {
		System.out.println("Creando nuovo proxy.");
		try {
			InetAddress address = InetAddress.getByName(null);
			this.socket = new Socket(address, 8888);
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());
		} catch (IOException e) {

		}

		System.out.println("Creato nuovo proxy.");
	}

	public Resource getA() {
		System.out.println("Cercando di prendere risorsa A: " + socket.getRemoteSocketAddress());
		try {
			out.writeObject("<getA>");
			try {
				return (Resource) in.readObject();
			} catch (ClassNotFoundException e) {
			}
		} catch (IOException e) {
		}

		return null;
	}

	public Resource getB() {
		System.out.println("Cercando di prendere risorsa B: " + socket.getRemoteSocketAddress());
		try {
			out.writeObject("<getB>");
			try {
				return (Resource) in.readObject();
			} catch (ClassNotFoundException e) {
			}
		} catch (IOException e) {
		}

		return null;
	}

	public void put(Resource r) {
		System.out.println("Cercando di rilasciare la risorsa: " + r.getType());

		try {
			out.writeObject("<put>");
			out.writeObject(r);
		} catch (IOException e) {
		}
	}

	@Override
	public void close() throws Exception {
		if (socket != null) {
			out.writeObject("<end>");
			socket.close();
		}

		if (in != null) {
			in.close();
		}

		if (out != null) {
			out.close();
		}

	}

}
