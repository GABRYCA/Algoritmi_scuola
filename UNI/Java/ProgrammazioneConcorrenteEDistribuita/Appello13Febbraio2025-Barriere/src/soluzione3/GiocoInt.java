package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface GiocoInt extends Remote {

	void giocata(int mioId) throws RemoteException;

	void letturaEsito(int mioId) throws RemoteException;
}
