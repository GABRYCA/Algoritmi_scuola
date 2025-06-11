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
			// TODO Auto-generated catch block
		} catch (IOException e) {
			// TODO Auto-generated catch block
		}
	
	}

	public Prodotto preleva() {

		try {
			out.writeObject("<preleva>");
			return (Prodotto) in.readObject();
		} catch (IOException | ClassNotFoundException e) {
		}
		
		return null;
	}

	public void deposita(Prodotto p) {
		try {
			out.writeObject("<deposita>");
			out.writeObject(p);
		} catch (IOException e) {
			// TODO Auto-generated catch block
		}
		
		
	}
}
