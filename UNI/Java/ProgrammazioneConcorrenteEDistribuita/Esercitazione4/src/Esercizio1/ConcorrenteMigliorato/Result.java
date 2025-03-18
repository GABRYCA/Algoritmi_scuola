package Esercizio1.ConcorrenteMigliorato;

/**
 * Questa classe registra lo stato dei calcoli, e viene modificata dai thread quando hanno completato il loro compito.
 * Viene letta dal main per verificare se tutti i thread hanno completato il loro compito.
 * */
public class Result {
	private int expectedSums;
	private int completedSums;
	int resultsRef[];
	
	public Result (int[] r, int exp) {
		this.expectedSums = exp;
		this.completedSums = 0;
		this.resultsRef = r;
	}
	
	/**
	 * Viene chiamato da ogni thread quando ha finito il suo compito
	 * */
	public synchronized void setNums(int i, int v) {
		resultsRef[i] = v;
		this.completedSums++;
		if (completedSums == expectedSums) notifyAll();
	}
	
	public synchronized void waitCompletion() {
		while (completedSums < expectedSums) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
	}
	
	/**
	 * Indica se i thread hanno tutti completato i loro compiti
	 * */
	public boolean isCompleted() {
		return completedSums == expectedSums;
	}
}