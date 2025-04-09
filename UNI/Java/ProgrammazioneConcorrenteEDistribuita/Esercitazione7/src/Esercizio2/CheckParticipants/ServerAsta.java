package Esercizio2.CheckParticipants;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class ServerAsta {
	public static final int PORT = 9999;
	final static int MAXWAIT = 1000;
	final static int MAXINACTIVITY = 5000;

	public static void main(String[] args) throws IOException {
		Asta lAsta = new Asta(10000, 0.04);
		ServerSocket s = new ServerSocket(PORT);
		System.out.println("Server asta pronto");
		s.setSoTimeout(MAXWAIT);
		while (true) {
			Socket cliSocket = null;
			try {
				cliSocket = s.accept();
				new ServerAstaThread(lAsta, cliSocket);
			} catch (SocketTimeoutException e) {
				long tNow = System.currentTimeMillis();
				long delay = tNow - lAsta.latestChange();
				System.out.println("Server: inattivita` =" + delay + "; partecipanti:" + lAsta.howManyParticipants());
				if (delay > MAXINACTIVITY && lAsta.howManyParticipants() == 0) {
					System.out.println("No participants detected");
					break;
				}
			}
		} // fine ciclo accettazioni
		System.out.println("Aggiudicato all'" + lAsta.leggi_offerta());
		s.close();
	}
}
