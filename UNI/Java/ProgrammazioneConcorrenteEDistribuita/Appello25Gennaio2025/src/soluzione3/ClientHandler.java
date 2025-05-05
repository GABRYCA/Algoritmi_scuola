package soluzione3;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ClientHandler implements Runnable {
	
	private Socket socket = null;
	private ResourceManager risorseCondivise = null;

	public ClientHandler(Socket socket, ResourceManager risorse) {
		System.out.println("Ricevuto nuovo client: " + socket.getRemoteSocketAddress() + ":" + socket.getPort());
		this.socket = socket;
		this.risorseCondivise = risorse;
	}
	
	@Override
	public void run() {
		try {
			ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
			ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
			
			try {
				String comando;
				Boolean fine = false;
				while ((comando = (String) in.readObject()) != null && !fine) {
					switch (comando) {
					case "<getA>": {
						System.out.println("Richiesta una risorsa A...");
						out.writeObject(risorseCondivise.getA());;
						break;
					}
					case "<getB>": {
						System.out.println("Richiesta una risorsa B...");
						out.writeObject(risorseCondivise.getB());
						break;
					}
					case "<put>": {
						System.out.println("Richiesto un rilasio...");
						Resource r = (Resource) in.readObject();
						risorseCondivise.put(r);
						System.out.println("Rilasciato una risorsa: " + r.getType());
						break;
					}
					case "<end>": {
						fine = true;
						break;
					}
					default: {
						 System.out.println("Comando non trovato: " + comando);
						break;
					}
					}
				}
				
				System.out.println("Ricevuto comando di chiusura dal client. Chiuso: " + socket.getRemoteSocketAddress() + ":" + socket.getPort());
			} catch (ClassNotFoundException e) {
			}
		} catch (IOException e) {
		}
	}

}
