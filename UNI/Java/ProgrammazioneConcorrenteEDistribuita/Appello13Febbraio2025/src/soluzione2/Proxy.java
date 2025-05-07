package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Proxy implements AutoCloseable {

	Socket socket;
	ObjectInputStream in;
	ObjectOutputStream out;
	int id = 0;

	public Proxy(int id) {
		this.id = id;
		try {
			InetAddress address = InetAddress.getByName(null);
			try {
				Socket socket = new Socket(address, 1069);
				
				this.out = new ObjectOutputStream(socket.getOutputStream());
				this.in = new ObjectInputStream(socket.getInputStream());

				this.socket = socket;
			} catch (IOException e) {
			}
		} catch (UnknownHostException e) {
		}
	}

	public void giocata() {
		try {
			out.writeObject("<GIOCATA> " + id);
		} catch (IOException e) {
		}
	}

	public void letturaEsito() {
		try {
			out.writeObject("<ESITO> " + id);
			try {
				String esito = (String) in.readObject();
				System.out.println("Esito: " + esito);
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (IOException e) {
		}
	}

	@Override
	public void close() throws Exception {
		if (socket != null) {
			if (out != null) {
				out.writeObject("<CLOSE>");
			}
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
