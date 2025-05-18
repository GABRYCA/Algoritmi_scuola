package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Proxy {

	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;

	public Proxy() {
		try {
			this.socket = new Socket(InetAddress.getByName(null), 1099);
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());
		} catch (UnknownHostException e) {
		} catch (IOException e) {
		}
	}

	public void put(Messaggio msg) {
		try {
			out.writeObject("<put>");
			out.writeObject(msg);
		} catch (IOException e) {
		}
	}

	public Messaggio read(String name) {
		try {
			out.writeObject("<read>");
			out.writeObject(name);
			try {
				return (Messaggio) in.readObject();
			} catch (ClassNotFoundException e) {
			}
		} catch (IOException e) {
		}
		return null;
	}

	public String newClient() {
		try {
			out.writeObject("<newclient>");
			try {
				return (String) in.readObject();
			} catch (ClassNotFoundException e) {
			}
		} catch (IOException e) {
		}
		return null;
	}

	public int numClients() {
		try {
			out.writeObject("<numclients>");
			try {
				return (int) in.readObject();
			} catch (ClassNotFoundException e) {
			}
		} catch (IOException e) {
		}
		return 0;
	}

}
