package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ClientHandler implements Runnable {

	CasellePostali caselle;
	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;

	public ClientHandler(Socket socket, CasellePostali caselle) {
		this.socket = socket;
		this.caselle = caselle;

		try {
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());

			System.out.println("Creato ClientHandler con successo!");
		} catch (IOException e) {
		}
	}

	@Override
	public void run() {
		String comando;
		try {
			while ((comando = (String) in.readObject()) != null) {
				boolean fine = false;
				switch (comando) {
				case "<put>": {
					Messaggio msg = (Messaggio) in.readObject();
					System.out.println("Ricevuto messaggio: " + msg);
					caselle.put(msg);
					break;
				}
				case "<read>": {
					out.writeObject(caselle.read((String) in.readObject(), 400));
					break;
				}
				case "<newclient>": {
					out.writeObject(caselle.newClient());
					break;
				}
				case "<numclients>": {
					out.writeObject(caselle.numClients());
					break;
				}
				case "<fine>": {
					fine = true;
					break;
				}
				default:
					throw new IllegalArgumentException("Comando sconosciuto: " + comando);
				}
				
				if (fine) break;
			}
		} catch (ClassNotFoundException | IOException e) {
		} finally {
			try {
				if (in != null)
					in.close();
				if (out != null)
					out.close();
				if (socket != null && !socket.isClosed())
					socket.close();
				System.out.println("ClientHandler: Connessione chiusa.");
			} catch (IOException e) {
			}
		}

	}

}
