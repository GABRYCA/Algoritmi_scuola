package Esercizio2.Base;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class ServerAsta {
	public static final int PORT = 9999;
	final static int MAXWAIT = 1000;
	final static int MAXINACTIVITY = 5000;

	public static void main(String[] args) throws IOException {
		Asta lAsta = new Asta(10000, 0.05);
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
				if (tNow - lAsta.latestChange() > MAXINACTIVITY) {
					System.out.println("Max inactivity detected");
					break;
				}
			}
		} // fine ciclo accettazioni
		System.out.println("Aggiudicato a " + lAsta.leggi_titolare() + " per " + lAsta.leggi_offerta() + " soldi");
		s.close();
	}
}
