package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ClientHandler implements Runnable {

	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;
	Tavolo tavolo;

	public ClientHandler(Socket socket, Tavolo t) {
		this.socket = socket;
		this.tavolo = t;

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
				case "<iniziogioco>": {
					tavolo.iniziaGioco((String) in.readObject(), (int) in.readObject());
					break;
				}
				case "<cambiastato>": {
					tavolo.cambiaStato((String) in.readObject(), (int) in.readObject());
					break;
				}
				case "<promozione>": {
					boolean esito = tavolo.promozione((String) in.readObject());
					out.writeObject(esito);
					break;
				}
				default:
					throw new IllegalArgumentException("Comando sconosciuto: " + comando);
				}
			}
		} catch (ClassNotFoundException e) {
		} catch (IOException e) {
		} finally {
			try {
				if (socket != null && !socket.isClosed()) {
					socket.close();
				}
				if (out != null) {
					out.close();
				}
				if (in != null) {
					in.close();
				}

			} catch (IOException e) {
			}

		}
	}

}
