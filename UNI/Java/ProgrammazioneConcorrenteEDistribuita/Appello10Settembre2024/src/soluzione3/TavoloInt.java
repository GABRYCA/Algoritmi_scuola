package soluzione3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface TavoloInt extends Remote {

	void iniziaGioco(String mioNome, int mioStato) throws RemoteException;

	void cambiaStato(String mioNome, int mioStato) throws RemoteException;

	boolean promozione(String mioNome) throws RemoteException;

}
