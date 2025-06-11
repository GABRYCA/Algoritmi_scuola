package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class GiocatoreHandler implements Runnable {

	Gioco g;

	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;

	public GiocatoreHandler(Socket s, Gioco g) {
		this.g = g;
		this.socket = s;
		try {
			this.out = new ObjectOutputStream(s.getOutputStream());
			this.in = new ObjectInputStream(s.getInputStream());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public void run() {

		String comando;

		try {
			while ((comando = (String) in.readObject()) != null && comando != "<fine>") {
				switch (comando) {
				case "<giocata>": {
					
					int id = (int) in.readObject();
					g.giocata(id);
					
					break;
				}
				case "<letturaEsito>": {

					int id = (int) in.readObject();
					g.letturaEsito(id);
					
					break;
				}
				default: {
					System.out.println("Comando sconosciuto: " + comando);
					break;
				}
				}
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
