package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Proxy {
	
	Socket s;
	ObjectOutputStream out;
	ObjectInputStream in;
	
	Proxy() {
		try {
			this.s = new Socket(InetAddress.getByName(null), 1099);
			this.out = new ObjectOutputStream(s.getOutputStream());
			this.in = new ObjectInputStream(s.getInputStream());
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void aspettaTurno(int identificatore) {
		try {
			System.out.println("Sto aspettando il turno: " + identificatore);
			out.writeObject("<aspettaturno>");
			out.writeObject(identificatore);
		} catch (IOException e) {
			e.printStackTrace();
		};
	}

	public void mossa(int identificatore, String string) {
		try {
			System.out.println("Sto provando a fare una mossa: " + identificatore);
			out.writeObject("<mossa>");
			out.writeObject(identificatore);
			out.writeObject(string);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	

}
