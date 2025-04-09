package Esercizio2.CheckParticipants;

public class Asta {
	private Offerta offertaCorrente;
	private int baseAsta;
	private double rialzo_min;
	private long latestActivityTime;
	private int participants;

	Asta(int ba, double rialzmin) {
		this.offertaCorrente = new Offerta(ba, "nessuno");
		this.baseAsta = ba;
		this.rialzo_min = rialzmin;
		participants = 0;
		latestActivityTime = System.currentTimeMillis();
	}

	public synchronized void updateParticipants(int delta) {
		participants += delta;
	}

	public synchronized int howManyParticipants() {
		return participants;
	}

	public synchronized Offerta leggi_offerta() {
		System.out.println("Asta replies to read request: " + offertaCorrente);
		return offertaCorrente;
	}

	public synchronized boolean fai_offerta(Offerta newOffer) {
		System.out.println("Asta riceve " + newOffer);
		if (newOffer.getAmount() >= offertaCorrente.getAmount() * (1 + rialzo_min)
				&& newOffer.getAmount() >= baseAsta) {
			offertaCorrente = newOffer;
			latestActivityTime = System.currentTimeMillis();
			System.out.println("Asta accetta: nuova offerta corrente e` " + offertaCorrente);
			return (true);
		} else {
			System.out.println("Asta rifiuta " + newOffer);
			return (false);
		}
	}

	public synchronized long latestChange() {
		return latestActivityTime;
	}
}
