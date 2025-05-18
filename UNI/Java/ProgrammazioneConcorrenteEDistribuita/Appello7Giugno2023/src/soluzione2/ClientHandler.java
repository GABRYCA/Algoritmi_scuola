package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ClientHandler implements Runnable {

	Socket socket;
	Dati dati;
	ObjectOutputStream out;
	ObjectInputStream in;

	public ClientHandler(Socket socket, Dati dati) {
		this.socket = socket;
		this.dati = dati;
		try {
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());
		} catch (IOException e) {
		}
	}

	@Override
	public void run() {
		String comando;
		try {
			while ((comando = (String) in.readObject()) != null) {

				switch (comando) {
				case "<aggiungidato>": {
					dati.aggiungiDato((String) in.readObject(), (String) in.readObject());
					break;
				}
				case "<esistedato>": {
					Boolean esiste = dati.esisteDato((String) in.readObject());
					out.writeObject(esiste);
					break;
				}
				case "<trovadato>": {
					String dato = dati.trovaDato((String) in.readObject());
					out.writeObject(dato);
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

}
