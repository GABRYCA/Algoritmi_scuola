package Esercizio2;

import java.io.Serializable;

public class Offerta implements Serializable {
	private static final long serialVersionUID = 1;
	private int value;
	private String proposer;
	private boolean finale = false;

	public Offerta(int v, String w) {
		this.value = v;
		this.proposer = w;
		finale = false;
	}

	public Offerta() {
		this.value = 0;
		this.proposer = "nessuno";
		finale = false;
	}

	public int getAmount() {
		return value;
	}

	public String getWho() {
		return proposer;
	}

	public void copy(Offerta o) {
		o.finale = this.finale;
		o.proposer = this.proposer;
		o.value = this.value;
	}

	public boolean isFinale() {
		return finale;
	}

	public void finalizza() {
		finale = true;
	}

	public String toString() {
		return ((finale ? "final " : "ongoing ") + "offer by " + proposer + " valued " + value);
	}
}
