package Esercizio2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class BankServerThread extends Thread {
	private Socket socket;
	private ObjectInputStream in;
	private ObjectOutputStream out;
	private Bank bank;

	BankServerThread(Socket s, Bank b) {
		socket = s;
		bank = b;
		try {
			in = new ObjectInputStream(socket.getInputStream());
			out = new ObjectOutputStream(socket.getOutputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
		start();
	}

	public void run() {
		try {
			while (true) {
				OperationRequest op = (OperationRequest) in.readObject();
				if (op.getRequest().equals("END"))
					break;
				Result res = bank.executeOperation(op);
				out.writeObject(res);
			}
		} catch (IOException | ClassNotFoundException e) {
			System.err.println("Exception");
		} finally {
			try {
				socket.close();
			} catch (IOException e) {
				System.err.println("Socket not closed");
			}
		}
	}
}
