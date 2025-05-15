package Esercizio2.SolCallback;

import java.rmi.RemoteException;

public class NewsUpdater extends Thread {
	NewsService theNewsServer;
	int count;

	public NewsUpdater(NewsService obj) {
		theNewsServer = obj;
		count = 0;
	}

	public void run() {
		while (true) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
			}
			try {
				theNewsServer.updateNews("notizia_" + count++);
			} catch (RemoteException e) {
			}
		}
	}
}