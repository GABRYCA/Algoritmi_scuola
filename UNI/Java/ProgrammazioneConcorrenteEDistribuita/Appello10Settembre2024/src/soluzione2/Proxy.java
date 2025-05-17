package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Proxy implements AutoCloseable {
	
	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;
	
	public Proxy() {
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

	@Override
	public void close() throws Exception {
		if (socket != null && !socket.isClosed()) {
			socket.close();
		}
		
		if (out != null) {
			out.close();
		}
		
		if (in != null) {
			in.close();
		}
	}

	public void iniziaGioco(String mioNome, int mioStato) {
		try {
			out.writeObject("<iniziogioco>");
			out.writeObject(mioNome);
			out.writeObject(mioStato);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void cambiaStato(String mioNome, int mioStato) {
		try {
			out.writeObject("<cambiastato>");
			out.writeObject(mioNome);
			out.writeObject(mioStato);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public boolean promozione(String mioNome) {
		try {
			out.writeObject("<promozione>");
			out.writeObject(mioNome);
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

}
