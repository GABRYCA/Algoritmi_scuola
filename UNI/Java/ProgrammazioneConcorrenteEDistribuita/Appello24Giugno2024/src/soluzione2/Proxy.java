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
			InetAddress address = InetAddress.getByName(null);
			try {
				this.socket = new Socket(address, 1099);
				this.out = new ObjectOutputStream(socket.getOutputStream());
				this.in = new ObjectInputStream(socket.getInputStream());
			} catch (IOException e) {
			}
		} catch (UnknownHostException e) {
		}
	}

	public String leggi() {
		try {
			out.writeObject("<leggi>");
			try {
				return (String) in.readObject();
			} catch (ClassNotFoundException e) {
			}
		} catch (IOException e) {
		}
		return null;
	}

	public void mossa(String miaMossa) {
		try {
			out.writeObject("<mossa>");
			out.writeObject(miaMossa);
		} catch (IOException e) {
		}
		
	}
}
