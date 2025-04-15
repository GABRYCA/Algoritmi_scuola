package Esercizio2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.concurrent.ThreadLocalRandom;

public class ClienteAstaThread extends Thread {
	private int maxTries = 3 + (int) (Math.random() * 4);
	private int numTries = 0;
	private Offerta currentOffer;
	private String myName;
	private Socket mySocket;
	private ObjectInputStream obj_in_s;
	private ObjectOutputStream obj_out_s;

	public ClienteAstaThread(InetAddress addr, int port, String n) throws IOException {
		this.mySocket = new Socket(addr, port);
		this.myName = n;
		this.currentOffer = null; // new Offerta(0, myName);
		this.obj_in_s = new ObjectInputStream(mySocket.getInputStream());
		this.obj_out_s = new ObjectOutputStream(mySocket.getOutputStream());
		start();
	}

	private void refreshCurrentOffer() throws IOException, ClassNotFoundException {
		obj_out_s.writeObject("read");
		obj_out_s.flush();
		currentOffer = (Offerta) obj_in_s.readObject();
		System.out.println(myName + " read " + currentOffer);
	}

	public void run() {
		boolean finito = false;
		Offerta newOff = null;
		boolean result;
		double myIncrease = 1;
		while (!finito) {
			try {
				if (numTries < maxTries) {
					refreshCurrentOffer();
					if (currentOffer.isFinale()) {
						finito = true;
					} else {
						if (!currentOffer.getWho().equals(myName)) { // rilancia
							obj_out_s.writeObject("offer");
							obj_out_s.flush();
							myIncrease = 1 + ThreadLocalRandom.current().nextDouble(0, 0.9);
							newOff = new Offerta((int) (currentOffer.getAmount() * myIncrease), myName);
							obj_out_s.writeObject(newOff);
							obj_out_s.flush();
							result = (boolean) obj_in_s.readObject();
							if (result) {
								numTries++;
							} else {
								Thread.sleep(10);
							}
						} else {
							Thread.sleep(1000);
						}
					}
				} else {
					while (currentOffer.getWho().equals(myName) && !currentOffer.isFinale()) {
						Thread.sleep(500);
						refreshCurrentOffer();
					}
					finito = true;
				}
			} catch (IOException | InterruptedException | ClassNotFoundException e1) {
				break;
			}
		} // fine ciclo
		System.out.println(
				myName + (currentOffer.getWho().equals(myName) ? " " : " non ") + " ho vinto: " + currentOffer);
		try {
			obj_out_s.writeObject("END");
			obj_out_s.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(myName + " exits");
	}
}
