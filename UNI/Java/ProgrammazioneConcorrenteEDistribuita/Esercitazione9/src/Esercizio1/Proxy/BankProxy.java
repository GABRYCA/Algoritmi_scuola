package Esercizio1.Proxy;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class BankProxy {
	private Socket socket;
	private ObjectInputStream ins;
	private ObjectOutputStream outs;

	BankProxy(InetAddress addr) throws IOException {
		socket = new Socket(addr, Server.PORT);
		outs = new ObjectOutputStream(socket.getOutputStream());
		ins = new ObjectInputStream(socket.getInputStream());
	}

	// in questo caso il proxy non e` molto utile, perche' la logica e` banale:
	// passa le richieste al server, riceve le risposte e restituisce al client
	public Result executeOperation(OperationRequest operationRequest) {
		Result res = null;
		try {
			outs.writeObject(operationRequest);
			res = (Result) ins.readObject();
		} catch (IOException | ClassNotFoundException e) {
			System.err.println("Proxy: operation not executed");
		}
		return res;
	}

	public void quit() {
		try {
			outs.writeObject(new OperationRequest(-1, 0, "END"));
		} catch (IOException e) {
			System.err.println("I/O exception not being handled");
		}
	}

}
