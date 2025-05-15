package Esercizio3.SolNonBloccante;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.concurrent.ThreadLocalRandom;

public class WarnClientImpl extends UnicastRemoteObject implements WarnClient {
	private static final long serialVersionUID = 1L;

	protected WarnClientImpl(String name) throws RemoteException {
		super();
		Thread.currentThread().setName(name);
	}

	public void notifyMe() throws RemoteException {
		System.out.println("client " + Thread.currentThread().getName() + ": warning received from server!");
	}

	void exec() throws RemoteException {
		Registry reg = null;
		try {
			reg = LocateRegistry.getRegistry(1099);
		} catch (RemoteException e) {
			System.err.println(Thread.currentThread().getName() + " could not find the registry");
			System.exit(0);
		}
		WarnServer laSveglia = null;
		try {
			laSveglia = (WarnServer) reg.lookup("WarnAt");
		} catch (RemoteException | NotBoundException e) {
			System.err.println(Thread.currentThread().getName() + " could not find the service");
			System.exit(0);
		}
		for (int i = 0; i < 3; i++) {
			int waitTime = ThreadLocalRandom.current().nextInt(1, 5);
			System.out.println(Thread.currentThread().getName() + " calling warnAt ");
			laSveglia.warnAt(waitTime, this);
			for (int j = 0; j < (waitTime + 4); j++) {
				System.out.println(Thread.currentThread().getName() + " doing something");
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
				}
			}
		}
		System.out.println(Thread.currentThread().getName() + ": terminating");
		UnicastRemoteObject.unexportObject(this, true);
	}

	public static void main(String[] args) throws RemoteException {
		new WarnClientImpl("client_" + System.currentTimeMillis() % 1000).exec();
	}
}
