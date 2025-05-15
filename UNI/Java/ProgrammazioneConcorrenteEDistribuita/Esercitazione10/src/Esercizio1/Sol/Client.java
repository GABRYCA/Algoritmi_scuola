package Esercizio1.Sol;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {

	public static void main(String[] args) throws RemoteException, NotBoundException {
		Registry reg = LocateRegistry.getRegistry(1099);
		MCD euclMCD = (MCD) reg.lookup("MCD");
		int x, y;
		x = 18;
		y = 3;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
		x = 18;
		y = 6;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
		x = 18;
		y = 7;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
		x = 18765;
		y = 345435;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
	}
}
