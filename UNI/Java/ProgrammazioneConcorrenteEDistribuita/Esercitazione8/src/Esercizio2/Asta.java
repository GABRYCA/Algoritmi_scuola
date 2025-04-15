package Esercizio2;

public class Asta {
	private Offerta offertaCorrente;
	private int baseAsta;
	private double rialzo_min;
	private long latestActivityTime;

	Asta(Offerta ba, double rialzmin) {
		this.offertaCorrente = ba;
		this.baseAsta = ba.getAmount();
		this.rialzo_min = rialzmin;
		latestActivityTime = System.currentTimeMillis();
	}

	public synchronized long latestChange() {
		return latestActivityTime;
	}

	public synchronized void leggi_copia_offerta(Offerta off) {
		offertaCorrente.copy(off);
	}

	public synchronized boolean nuova_offerta(Offerta o) {
		int newOffer = o.getAmount();
		if (newOffer >= offertaCorrente.getAmount() * (1 + rialzo_min)
				|| (offertaCorrente.getWho().equals("nessuno")) && newOffer >= baseAsta) {
			o.copy(offertaCorrente);
			latestActivityTime = System.currentTimeMillis();
			return (true);
		} else {
			return (false);
		}
	}

	public synchronized void chiudi() {
		offertaCorrente.finalizza();
		System.out.println("Asta chiude ********************************* " + offertaCorrente);
	}
}
