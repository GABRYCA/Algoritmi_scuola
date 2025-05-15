package Esercizio2.Dato;

import java.rmi.RemoteException;

public class ServerMain {
	public static void main(String args[]) {
		NewsServiceImpl obj;
		try {
			obj = new NewsServiceImpl();
			obj.exec();
			new NewsUpdater(obj).start();
		} catch (RemoteException e) {
			System.err.println("Lancio server fallito!");
		}

	}

}
