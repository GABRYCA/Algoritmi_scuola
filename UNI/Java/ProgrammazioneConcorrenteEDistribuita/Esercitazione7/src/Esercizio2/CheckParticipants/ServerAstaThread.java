package Esercizio2.CheckParticipants;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ServerAstaThread extends Thread {
	private Asta lAsta;
	private Socket cliSocket;
	private ObjectInputStream in;
	private ObjectOutputStream out;

	public ServerAstaThread(Asta a, Socket s) throws IOException {
		this.lAsta = a;
		this.cliSocket = s;
		this.out = new ObjectOutputStream(cliSocket.getOutputStream());
		this.in = new ObjectInputStream(cliSocket.getInputStream());
		start();
	}

	public void run() {
		Offerta off;
		lAsta.updateParticipants(+1);
		while (true) {
			String str;
			try {
				str = (String) in.readObject();
				System.out.println("Server received " + str);
				if (str.equals("END")) {
					lAsta.updateParticipants(-1);
					break;
				}
				if (str.equals("read")) {
					off = lAsta.leggi_offerta();
					System.out.println("Server: ho letto " + off);
					out.writeObject(off);
				}
				if (str.equals("offer")) {
					off = (Offerta) in.readObject();
					out.writeObject(lAsta.fai_offerta(off));
				}
			} catch (IOException | ClassNotFoundException e) {
				str = "END";
			}
		}
		try {
			cliSocket.close();
		} catch (IOException e) {
		}
	}
}
