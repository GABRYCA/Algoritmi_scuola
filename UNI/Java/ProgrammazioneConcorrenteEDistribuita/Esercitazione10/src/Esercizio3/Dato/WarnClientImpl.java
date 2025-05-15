package Esercizio3.Dato;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class WarnClientImpl extends UnicastRemoteObject implements WarnClient {
	private static final long serialVersionUID = 1L;

	WarnClientImpl() throws RemoteException {
		super();
	}

	public void notifyWarn() throws RemoteException {
		System.out.println("client " + Thread.currentThread().getName() + " riceve notifica a "
				+ System.currentTimeMillis() / 1000);
	}

	public static void main(String[] Args) throws RemoteException, NotBoundException {
		WarnClient c = new WarnClientImpl();
		Registry reg = LocateRegistry.getRegistry();
		WarnServer stub = (WarnServer) reg.lookup("WARNAT");
		for (int i = 0; i < 3; i++) {
			System.out.println("client " + Thread.currentThread().getName() + " manda richiesta warnAt a "
					+ System.currentTimeMillis() / 1000);
			stub.WarnAt(3, c);
			try {
				Thread.sleep(6000);
			} catch (InterruptedException e) {
			}
		}
		UnicastRemoteObject.unexportObject(c, true);
		System.out.println("client termina");
	}
}
