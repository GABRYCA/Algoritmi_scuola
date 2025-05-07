package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class GiocatoreHandler implements Runnable, AutoCloseable {
	
	Socket socket = null;
	Gioco gioco = null;
	int numero = 0;
	ObjectInputStream in;
	ObjectOutputStream out;
	
	public GiocatoreHandler(Socket socket, Gioco gioco, int numero) {
		System.out.println("Creato un nuovo handler per il giocatore: " + numero);
		
		try {
			this.out = new ObjectOutputStream(socket.getOutputStream());
			this.in = new ObjectInputStream(socket.getInputStream());
		} catch (IOException e) {
		}
		
		this.socket = socket;
		this.gioco = gioco;
		this.numero = numero;
	}

	@Override
	public void run() {
		System.out.println("Avviato handler giocatore: " + numero);
		
		String input;
		try {
			while ((input = (String) in.readObject()) != null) {
				String[] parti = input.split(" ");
				if (parti.length == 1) {
					if (parti[0].equalsIgnoreCase("<CLOSE>")) {
						System.out.println("Ricevuto comando di chiusura, chiudendo...");
						socket.close();
						in.close();
						out.close();
						break;
					}
				}
				
				switch (parti[0]) {
				case "<GIOCATA>": {
					gioco.giocata(Integer.parseInt(parti[1]));
					break;
				}
				case "<ESITO>": {
					String esito = gioco.letturaEsito(Integer.parseInt(parti[1]));
					out.writeObject(esito);
					break;
				}
				default:
					System.out.println("Comando non riconosciuto: " + parti[0]);
					break;
				}
			}
		} catch (ClassNotFoundException e) {
		} catch (IOException e) {
		}
	}

	@Override
	public void close() throws Exception {
		if (socket != null) {
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
