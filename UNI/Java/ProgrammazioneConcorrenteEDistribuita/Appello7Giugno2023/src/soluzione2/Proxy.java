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

	Proxy() {
		try {
			this.socket = new Socket(InetAddress.getByName(null), 1099);
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void aggiungiDato(String randomKey, String randomData) {
		try {
			out.writeObject("<aggiungidato>");
			out.writeObject(randomKey);
			out.writeObject(randomData);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

	public boolean esisteDato(String randomKey) {
		try {
			out.writeObject("<esistedato>");
			out.writeObject(randomKey);
			try {
				return (boolean) in.readObject();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return false;
	}

	public String trovaDato(String randomKey) {
		try {
			out.writeObject("<trovadato>");
			out.writeObject(randomKey);
			try {
				return (String) in.readObject();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return "";
	}

}
