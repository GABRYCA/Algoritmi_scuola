package Esercizio2;

import java.io.IOException;
import java.io.ObjectInputStream;

public class ClientSlave extends Thread {
	ObjectInputStream ins;
	Result res;

	ClientSlave(ObjectInputStream in, Result r) {
		ins = in;
		res = r;
		start();
	}

	public void run() {
		System.out.println("listener started");
		try {
			Result r = (Result) ins.readObject();
			System.out.println("listener read from server");
			res.setComplete(r);
			System.out.println("listener res complete");
		} catch (ClassNotFoundException | IOException e) {
			e.printStackTrace();
		}
	}
}