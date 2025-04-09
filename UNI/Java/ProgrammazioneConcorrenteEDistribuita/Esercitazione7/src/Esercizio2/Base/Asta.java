package Esercizio2.Base;

public class Asta {
	private int offertaCorrente;
	private int baseAsta;
	private double rialzo_min;
	private String titolareOfferta;
	private long latestActivityTime;

	Asta(int ba, double rialzmin) {
		this.offertaCorrente = ba;
		this.baseAsta = ba;
		this.rialzo_min = rialzmin;
		this.titolareOfferta = "nessuno";
		latestActivityTime = System.currentTimeMillis();
	}

	public synchronized int leggi_offerta() {
		return offertaCorrente;
	}

	public synchronized String leggi_titolare() {
		return titolareOfferta;
	}

	public synchronized boolean fai_offerta(int newOffer, String chi) {
		if (newOffer >= offertaCorrente * (1 + rialzo_min) && newOffer >= baseAsta) {
			titolareOfferta = chi;
			offertaCorrente = newOffer;
			System.out.println("Asta: new best offer by " + chi + ", " + newOffer + " soldi");
			latestActivityTime = System.currentTimeMillis();
			return (true);
		} else {
			return (false);
		}
	}

	public synchronized long latestChange() {
		return latestActivityTime;
	}
}
