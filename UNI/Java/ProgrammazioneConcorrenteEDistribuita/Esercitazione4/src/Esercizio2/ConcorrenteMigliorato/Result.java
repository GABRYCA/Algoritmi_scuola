package Esercizio2.ConcorrenteMigliorato;

public class Result {
	private int expectedVisits;
	private BinTree node;
	private boolean success = false;
	private int completedVisits = 0;
	
	public Result(int exp) {
		this.expectedVisits = exp;
		this.node = null;
		this.success = false;
		this.completedVisits = 0;
	}
	
	public synchronized void incVisits() {
		this.completedVisits++;
	}
	
	public synchronized boolean isCompleted() {
		return completedVisits == expectedVisits;
	}
	
	public synchronized boolean isSuccess() {
		return this.success;
	}
	
	public synchronized void setNode(BinTree n) {
		this.node = n;
	}
	
	public synchronized BinTree getNode() {
		return this.node;
	}
	
	public synchronized void setSuccess() {
		this.success = true;
	}
}
