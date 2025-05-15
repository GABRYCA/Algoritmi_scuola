package Esercizio3.SolNonBloccante;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class WarnServerImpl extends UnicastRemoteObject implements WarnServer {
	private static final long serialVersionUID = 1L;

	protected WarnServerImpl() throws RemoteException {
		super();
	}

	public void warnAt(int X, WarnClient c) throws RemoteException {
		new TimerSlave(X, c).start();
	}

	public static void main(String args[]) throws RemoteException {
		WarnServerImpl obj = new WarnServerImpl();
		Registry reg = LocateRegistry.createRegistry(1099);
		reg.rebind("WarnAt", obj);
		System.out.println("server ready");
	}
}
