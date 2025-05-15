package Esercizio2.Dato;

import java.util.concurrent.ThreadLocalRandom;

public class NewsUpdater extends Thread {
	NewsServiceImpl theNewsServer;
	int count;

	public NewsUpdater(NewsServiceImpl obj) {
		theNewsServer = obj;
		count = 0;
	}

	public void run() {
		String theNews = "";
		while (true) {
			if (ThreadLocalRandom.current().nextBoolean()) {
				theNews = "notizia_" + count++;
				theNewsServer.updateNews(theNews);
				System.out.println("Server: updated news: " + theNews);
			}
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(100, 2000));
			} catch (InterruptedException e) {
			}
		}
	}
}
