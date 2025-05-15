package Esercizio2.Dato;

import java.rmi.RemoteException;
import java.util.concurrent.ThreadLocalRandom;

public class NewsClientThread extends Thread {
	private static int threadcount = 0;
	final int N = 20;
	String name;
	NewsService mioNewsServer;

	public NewsClientThread(int id, NewsService news) {
		name = "client_" + id;
		mioNewsServer = news;
		synchronized (NewsClientThread.class) {
			threadcount++;
		}
		start();
	}

	public void run() {
		String st = "";
		for (int i = 0; i < N; i++) {
			try {
				st = mioNewsServer.readNews();
			} catch (RemoteException e) {
				st = "non pervenuta";
			}
			System.out.println(name + " : " + st);
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(300, 800));
			} catch (InterruptedException e) {
			}
		}
		System.out.println(name + ": finito ");
		synchronized (NewsClientThread.class) {
			threadcount--;
		}
	}

	public static int threadCount() {
		return threadcount;
	}
}
