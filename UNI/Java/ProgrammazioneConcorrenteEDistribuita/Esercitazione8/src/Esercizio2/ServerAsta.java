package Esercizio2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class ServerAsta {
	public static final int PORT = 9999;
	final static int MAXWAIT = 6000;
	final static int MAXINACTIVITY = 5000;

	public void exec() throws IOException {
		int slaveCounter = 0;
		Asta lAsta = new Asta(new Offerta(10000, "nessuno"), 0.05);
		ServerSocket s = new ServerSocket(PORT);
		System.out.println("Server asta pronto");
		s.setSoTimeout(MAXWAIT);
		while (true) {
			Socket cliSocket = null;
			try {
				cliSocket = s.accept();
				new ServerAstaThread(lAsta, cliSocket, slaveCounter++);
			} catch (SocketTimeoutException e) {
				long tNow = System.currentTimeMillis();
				if (tNow - lAsta.latestChange() > MAXINACTIVITY) {
					System.out.println("Max inactivity detected");
					lAsta.chiudi();
					break;
				}
			}
		}
		Offerta finalOffer = new Offerta();
		lAsta.leggi_copia_offerta(finalOffer);
		System.out.println("Aggiudicato a " + finalOffer);
		s.close();
	}

	public static void main(String[] args) throws IOException {
		new ServerAsta().exec();
	}
}
