package soluzione1;

import java.util.concurrent.ThreadLocalRandom;

public class User extends Thread {
	ResourceManager repository;
	Resource rA = null, rB = null;
	String mioNome;

	public User(ResourceManager r) {
		repository = r;
	}

	void acquisizioneA() {
		System.out.println(mioNome + " aquisisco risorsa A");
		rA = repository.getA();
		System.out.println(mioNome + " acquisito risorsa " + rA.getType() + rA.getNum());
	}

	void acquisizioneB() {
		System.out.println(mioNome + " aquisisco risorsa B");
		rB = repository.getB();
		System.out.println(mioNome + " acquisito risorsa " + rB.getType() + rB.getNum());
	}

	void rilascio(Resource r) {
		System.out.println(mioNome + " rilascio risorsa " + r.getType() + r.getNum());
		repository.put(r);
		
		// Rilascio le risorse
		if (r.getType() == ResourceType.A) {
			rA = null;
		} else if (r.getType() == ResourceType.B) {
			rB = null;
		}
	}

	public void run() {
		mioNome = getName();
		try {
			for (;;) {
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
							
							repository.put(rB);
							
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
		} catch (InterruptedException e) {
		}
	}
}