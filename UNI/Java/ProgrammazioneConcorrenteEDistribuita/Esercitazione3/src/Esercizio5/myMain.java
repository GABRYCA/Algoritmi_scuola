package Esercizio5;

/**
 * Tema d'esame del 22/06/2018.
 * Si vuole simulare una partita di un gioco da tavolo.
 * La partita coinvolge n giocatori (n > 1)
 * Ogni giocatore, finchè la partita non è finita, quando è il suo turno tira i dadi e muove.
 * Se in conseguenza della mossa vince la partita, termina. Se lanciando i dadi fa doppio, tira nuovamente.
 * Il codice dat implementa la logica descritta, ma è scorretto dal punto di vista della sincronizzazione.
 * Si modifichi il codice dato in modo che il sistema si comporti correttamente.
 * Turni: Il giocatore 1 gioca per primo, poi gioca il giocatore 2, ecc.
 * 
 * NB: Il codice qui rilasciato è già stato corretto da GCA e confrontato con la soluzione offerta.
 * */
public class myMain {
	
	final static int numGiocatori = 4;

	public static void main(String[] args) throws InterruptedException {
		Table tavolo = new Table(numGiocatori);
		Thread giocatori[] = new Thread[numGiocatori];
		for (int i = 0; i < numGiocatori; i++) giocatori[i] = new Player(i, tavolo);
		for (int i = 0; i < numGiocatori; i++) giocatori[i].join();
		System.out.println("Game over");
	}

}
