package Esercizio4;

/**
 * Realizzare un sistema con due Thread che condividono una risorsa.
 * I due Thread devono accedere alternativamente alla risorsa (Cioè non deve mai succedere che lo stesso Thread acceda due volte consecutive la risorsa).
 * Protocollo:
 * Un Thread richiede l'accesso alla risorsa quando gli serve
 * Usa la risorsa
 * Rilascia la risorsa
 * */
public class Main {

	public static void main(String[] args) {
		String carte[] = {"A", "B"};
		Tavolo tavolo = new Tavolo(0);
		new Scambio(0, carte[0], tavolo).start();
		new Scambio(1, carte[0], tavolo).start();
	}

}
