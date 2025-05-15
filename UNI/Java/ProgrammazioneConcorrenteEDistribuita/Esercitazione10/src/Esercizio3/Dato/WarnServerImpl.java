package Esercizio3.Dato;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class WarnServerImpl extends UnicastRemoteObject implements WarnServer {
	private static final long serialVersionUID = 1L;

	WarnServerImpl() throws RemoteException {
	}

	public void WarnAt(int X, WarnClient c) throws RemoteException {
		System.out.println("server " + Thread.currentThread().getName() + " riceve richiesta a "
				+ System.currentTimeMillis() / 1000);
		// DA IMPLEMENTARE
	}

	public static void main(String[] Args) throws RemoteException {
		WarnServer s = new WarnServerImpl();
		Registry reg = LocateRegistry.createRegistry(1099);
		reg.rebind("WARNAT", s);
		System.out.println("server ready");
	}
}
