package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ClientHandler implements Runnable {

	Socket socket;
	ObjectOutputStream out;
	ObjectInputStream in;
	Magazzino m;
	
	public ClientHandler(Socket s, Magazzino m) {
		this.socket = s;
		this.m = m;
		try {
			this.out = new ObjectOutputStream(s.getOutputStream());
			this.in = new ObjectInputStream(s.getInputStream());
		} catch (IOException e) {
		}
		
	}
	
	@Override
	public void run() {

		System.out.println("Handler creato e avviato con successo!");
		
		String comando;
		
		try {
			while ((comando = (String) in.readObject()) != null && comando != "<fine>") {
				
				switch (comando) {
				case "<preleva>": {
					out.writeObject(m.preleva());
					break;
				}
				case "<deposita>": {
					Prodotto p = (Prodotto) in.readObject();
					m.deposita(p);
					break;
				}
				default:
					System.out.println("Comando sconosciuto: " + comando);
					break;
				}
				
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
		} catch (IOException e) {
			// TODO Auto-generated catch block
		}
		
	}
	

}
