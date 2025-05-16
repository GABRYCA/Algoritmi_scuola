package dato;

public class Gestore {
	int numModificheAttive;
	int numLettori;
	Tavolo ilTavolo;

	public Gestore(Tavolo t) {
		numModificheAttive=0;
		numLettori=0;
		ilTavolo=t;
	}
	private void situazioneThread() {
		System.out.println(" [#modificanti="+numModificheAttive+", #leggenti="+numLettori+"]");
	}

	public String leggi() {
		numLettori++;
		System.out.print(Thread.currentThread().getName()+" legge situazione "+
				(numModificheAttive>0?" illegalmente ******":""));
		situazioneThread();
		numLettori--;
		return ilTavolo.leggi();
	}

	public void mossa(String m) {
		System.out.print(Thread.currentThread().getName()+" effettua mossa "+
				(numModificheAttive>1||numLettori>0?" illegalmente ******":""));
		situazioneThread();
		numModificheAttive++;
		// esecuzione della mossa
		ilTavolo.prendiPedina();
		// a questo punto la situazione del tavolo da gioco e` inconsistente
		ilTavolo.mettiPedina();
		numModificheAttive--;
	}
}
