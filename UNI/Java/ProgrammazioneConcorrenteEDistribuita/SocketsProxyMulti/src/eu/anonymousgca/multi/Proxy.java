package eu.anonymousgca.multi;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class Proxy implements ServerInterface, AutoCloseable {
	private Socket socket = null;
	private BufferedReader in = null;
	private PrintWriter out = null;

	public Proxy() throws IOException {
		try {
			InetAddress address = InetAddress.getByName(null);
			this.socket = new Socket(address, ServerInterface.PORT);
			this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			this.out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
		} catch (IOException e) {
			System.err.println("Errore durante la creazione della connessione del Proxy: " + e.getMessage());
			close();
		}

	}

	@Override
	public void close() {
		System.out.println("Chiusura del proxy...");
		if (out != null)
			out.close();
		if (in != null)
			try {
				in.close();
			} catch (IOException ignore) {}
		if (socket != null && !socket.isClosed()) {
			try {
				socket.close();
			} catch (IOException ignore) {}
		}
	}

	@Override
	public int reset() throws IOException {
		System.out.println("Invio comando di reset: ");
		out.println("<RESET>");
		return risposta();
	}

	@Override
	public int increment() throws IOException {
		System.out.println("Invio comando di increment");
		out.println("<INCREMENT>");
		return risposta();
	}

	private int risposta() throws IOException {
		try {
			String risposta = in.readLine();
			System.out.println("Risposta: " + risposta);
			if (risposta == null)
				throw new IOException("Persa connessione con il server o chiusa (nel proxy)");
			try {
				return Integer.parseInt(risposta);
			} catch (NumberFormatException e) {
				System.out.println("Risposta del server non valida (Proxy).");
			}
		} catch (IOException e) {
			System.out.println("Errore durante la lettura della risposta: " + e.getMessage());
		}

		return 0;
	}

}
