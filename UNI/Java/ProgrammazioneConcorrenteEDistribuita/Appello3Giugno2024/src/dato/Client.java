package dato;

import java.util.concurrent.ThreadLocalRandom;

class Client extends Thread {
	String name;
	CasellePostali gestorePosta;
	Client(CasellePostali p) {
		this.gestorePosta=p;
	}
	public void run(){
		Messaggio msg;
		try {
			Thread.sleep(ThreadLocalRandom.current().nextInt(200,1000));
		} catch (InterruptedException e) { }
		name=gestorePosta.newClient();  // riceve il  nome dal gestore della posta
		for(int j=0; j<10; j++) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(200,300));
			} catch (InterruptedException e) { }
			if(ThreadLocalRandom.current().nextBoolean()) {
				// manda messaggio
				String dest="Client_"+ThreadLocalRandom.current().nextInt(1,1+gestorePosta.numClients());
				msg=new Messaggio(name, dest, "msg da "+name+" #"+j);
				gestorePosta.put(msg);
				System.out.println(name+" scrivo "+msg);
			} else {
				// legge messaggio
				msg=gestorePosta.read(name);
				if(msg==null) {
					System.out.println(name+" letto niente :-(");
				} else {
					System.out.println(name+" ho letto "+msg);					
				}
			}
		}
	}
}
