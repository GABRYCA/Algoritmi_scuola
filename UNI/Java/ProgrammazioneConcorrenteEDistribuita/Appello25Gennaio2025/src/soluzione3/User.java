package soluzione3;

import java.rmi.RemoteException;
import java.util.concurrent.ThreadLocalRandom;

public class User implements Runnable {
	ResourceManagerInterface resources;
	Resource rA = null, rB = null;
	String mioNome;

	public User(ResourceManagerInterface resources) {
		this.resources = resources;
	}

	void acquisizioneA() {
		System.out.println(mioNome + " aquisisco risorsa A");
		try {
			rA = resources.getA();
		} catch (RemoteException e) {
		}
		System.out.println(mioNome + " acquisito risorsa " + rA.getType() + rA.getNum());
	}

	void acquisizioneB() {
		System.out.println(mioNome + " aquisisco risorsa B");
		try {
			rB = resources.getB();
		} catch (RemoteException e) {
		}
		System.out.println(mioNome + " acquisito risorsa " + rB.getType() + rB.getNum());
	}

	void rilascio(Resource r) {
		System.out.println(mioNome + " rilascio risorsa " + r.getType() + r.getNum());
		try {
			resources.put(r);
		} catch (RemoteException e) {
		}
		
		// Rilascio le risorse
		if (r.getType() == ResourceType.A) {
			rA = null;
		} else if (r.getType() == ResourceType.B) {
			rB = null;
		}
	}

	public void run() {
		mioNome = Thread.currentThread().getName();
		System.out.println("Utente " + mioNome + " sta iniziando le sue azioni...");
		try {
			for (int i = 0; i < 100; i++) {
				System.out.println("Iterazione: " + (i+1));
				if (ThreadLocalRandom.current().nextBoolean()) {
					if (ThreadLocalRandom.current().nextBoolean()) {
						System.out.println(mioNome + " acquisisco prima risorsa A ");
						acquisizioneA();
					} else {
						System.out.println(mioNome + " acquisisco prima risorsa B ");
						acquisizioneB();
					}
					Thread.sleep(ThreadLocalRandom.current().nextInt(100, 200));
					// vediamo se c'e` bisogno di una seconda risorsa
					if (ThreadLocalRandom.current().nextBoolean()) {
						// ho bisogno della seconda risorsa
						if (rA != null) {
							System.out.println(mioNome + " acquisisco risorsa B avendo A");
							acquisizioneB();
						} else {
							System.out.println(mioNome + " acquisisco risorsa A avendo B");
							System.out.println(mioNome + " prima di acquisire A avendo già B, rilascio B");
							
							try {
								resources.put(rB);
							} catch (RemoteException e) {

							}
							
							acquisizioneA();
							acquisizioneB();
						}
					}
				}
				// elaborazione
				Thread.sleep(ThreadLocalRandom.current().nextInt(200, 400));
				// rilascio  risorse
				if (rA != null) {
					rilascio(rA);
				}
				if (rB != null) {
					rilascio(rB);
				}
				rA = rB = null;
			}
			try {
			} catch (Exception e) {
			}
			System.out.println("Fine user.");
		} catch (InterruptedException e) {
		}
	}
}