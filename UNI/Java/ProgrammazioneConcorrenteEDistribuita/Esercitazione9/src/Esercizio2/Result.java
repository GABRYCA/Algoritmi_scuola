package Esercizio2;

import java.io.Serializable;

public class Result implements Serializable {
	private static final long serialVersionUID = 1l;
	int CCnumber;
	int amount;
	String opType;
	boolean successful;
	boolean completed;

	Result(int cc, int val, String ot, boolean ok) {
		CCnumber = cc;
		amount = val;
		opType = ot;
		successful = ok;
		completed = false;
	}

	public synchronized void setComplete(Result r) {
		this.CCnumber = r.getCCnumber();
		this.amount = r.getAmount();
		this.opType = r.getType();
		this.successful = r.isSuccessful();
		completed = true;
	}

	public int getCCnumber() {
		return CCnumber;
	}

	public int getAmount() {
		return amount;
	}

	public boolean isCompleted() {
		return completed;
	}

	public boolean isSuccessful() {
		return successful;
	}

	public String getType() {
		return opType;
	}

	public String toString() {
		return "op. " + opType + " on CC num. " + CCnumber + (successful ? " OK" : " KO") + " resulting amount="
				+ amount;
	}
}
