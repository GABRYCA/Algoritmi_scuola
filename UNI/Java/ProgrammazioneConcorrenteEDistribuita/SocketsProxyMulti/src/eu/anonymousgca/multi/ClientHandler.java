package eu.anonymousgca.multi;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

// Anche noto come "Skeleton" del server per gestire il client
public class ClientHandler implements Runnable {
	private final Socket socket;
	private final Counter counterCondiviso;

	public ClientHandler(Socket socket, Counter counter) {
		this.socket = socket;
		this.counterCondiviso = counter;

		System.out.println("Creato un nuovo handler sul thread: " + Thread.currentThread().getName()
				+ " per il client: " + socket.getRemoteSocketAddress());
	}

	@Override
	public void run() {
		System.out.println("Avviato handler sul thread: " + Thread.currentThread().getName() + " per il client: "
				+ socket.getRemoteSocketAddress());

		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),
					true);

			String operazione;
			while ((operazione = in.readLine()) != null) {
				System.out.println("L'handler " + Thread.currentThread().getName() + " ha ricevuto il comando: "
						+ operazione + " da " + socket.getRemoteSocketAddress());

				int risultato = -1;
				switch (operazione) {
				case "<RESET>": {
					risultato = counterCondiviso.reset();
					break;
				}
				case "<INCREMENT>": {
					risultato = counterCondiviso.increment();
					break;
				}
				default:
					System.out.println("Operazione " + operazione + " non riconsciuta!");
				}

				if (risultato != -1) {
					out.println(risultato);
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (socket != null && !socket.isClosed()) {
				try {
					socket.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			
			System.out.println("Connessione dell'handler: " + Thread.currentThread().getName() + " con il client " + socket.getRemoteSocketAddress() + " chiusa con successo!");
		}

	}

}
