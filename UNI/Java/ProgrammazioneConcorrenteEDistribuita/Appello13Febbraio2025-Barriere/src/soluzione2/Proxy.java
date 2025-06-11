package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class Proxy {
	
	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;
	
	public Proxy() {
		try {
			this.socket = new Socket(InetAddress.getByName(null), 1099);
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void giocata(int mioId) {
		try {
			out.writeObject("<giocata>");
			out.writeObject(mioId);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	public void letturaEsito(int mioId) {

		try {
			out.writeObject("<letturaEsito>");
			out.writeObject(mioId);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	
	

}
