package Esercizio2;

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

	public void executeOperation(Result r, OperationRequest operationRequest) {
		try {
			outs.writeObject(operationRequest);
		} catch (IOException e) {
			System.err.println("Proxy: operation not executed");
		}
		System.out.println("Proxy: sent request to server");
		new ClientSlave(ins, r);
	}

	public void quit() {
		try {
			outs.writeObject(new OperationRequest(-1, 0, "END"));
		} catch (IOException e) {
			System.err.println("I/O exception not being handled");
		}
	}

}
