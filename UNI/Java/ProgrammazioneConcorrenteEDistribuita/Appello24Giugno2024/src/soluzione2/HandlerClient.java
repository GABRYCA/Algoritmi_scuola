package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class HandlerClient implements Runnable, AutoCloseable {
	Socket socket;
	Gestore gestore;
	ObjectOutputStream out;
	ObjectInputStream in;
	
	public HandlerClient(Socket socket, Gestore gestore) {
		this.socket = socket;
		this.gestore = gestore;
		try {
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		String comando;
		try {
			while ((comando = (String) in.readObject()) != null && comando != "<fine>") {
				switch (comando) {
				case "<mossa>": {
					String mossa = (String) in.readObject();
					gestore.mossa(mossa);
					break;
				}
				case "<leggi>": {
					out.writeObject(gestore.leggi());
					break;
				}
				case "<fine>": {
					break;
				}
				default:
					throw new IllegalArgumentException("Comando sconosciuto: " + comando);
				}
			}
		} catch (ClassNotFoundException e) {
		} catch (IOException e) {
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
}
