package dato;


//classe passiva che contiene i metodi per accedere ai dati
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Random;

public class Tavolo {
	static final int MAXstati=3;
	Random rnd;
	Hashtable<String, Integer> iGiocatori;

	Tavolo(){
		iGiocatori=new Hashtable<String, Integer>();
	}

	public void iniziaGioco(String nome, int stato) {	
		// bisognerebbe controllare che non sia gia` presente, ma lasciamo stare
		iGiocatori.put(nome, stato);
	}

	public void cambiaStato(String nome, int stato) {
		if(iGiocatori.containsKey(nome)) {
			iGiocatori.put(nome, stato);
		}
	}

	private int quantiInStato(int stato) {
		List<Integer> gliStati=new ArrayList<>(iGiocatori.values());
		int count=0;
		for(int n : gliStati) {
			if(n==stato) {
				count++;
			}
		}
		return count;
	}

	private boolean condizioneProgressioneOK(int count, int stato) {
		// la condizione specifica e` irrilevante
		return count==stato;
	}

	public boolean promozione(String nome) {
		if(iGiocatori.containsKey(nome)) {
			int stato=iGiocatori.get(nome);
			int count;
			count=quantiInStato(stato);
			System.out.println("Tavolo: trovati "+count+" giocatori in stato "+stato+" per "+nome);
			if(condizioneProgressioneOK(count, stato)) {
				return true;
			}
		}
		return false;
	}
}
