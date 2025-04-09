package Esercizio2.CheckParticipants;

import java.io.Serializable;

public class Offerta implements Serializable {
	private static final long serialVersionUID = 1;
	private int value;
	private String proposer;

	public Offerta(int v, String w) {
		this.value = v;
		this.proposer = w;
	}

	public int getAmount() {
		return value;
	}

	public String getWho() {
		return proposer;
	}

	public String toString() {
		return "offer of " + value + " from " + proposer;
	}
}