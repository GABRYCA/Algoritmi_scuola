import java.util.ArrayList;
import java.util.List;


public class TestGenerics {
	public static void main(String[] args) {

		//DICHIARAZIONE LISTA NON TYPE SAFE
		List lista = new ArrayList(); //compila ma genera warning
		Studente s1 = new Studente("0001");
		s1.setMedia(25);
		Studente s2 = new Studente("0002");
		s2.setMedia(27);
		lista.add(s1); //compila ma genera warning
		lista.add(s2); //compila ma genera warning
		System.out.println("media " + calcolaMedia(lista)); //cosa succede a tempo di esecuzione ? 
		
		
		lista.add(new Integer(3)); //compila ma genera warning
		System.out.println("media " + calcolaMedia(lista));  //cosa succede a tempo di esecuzione ? 		
	
		//DICHIARAZIONE LISTA TYPE SAFE (GENERICS)
		List<Studente> listaStudenti = new ArrayList<Studente>();
		listaStudenti.add(s1);
		listaStudenti.add(s2);
		//listaStudenti.add(new Integer(3)); //non compila
	
		List<Integer> listaInteri = new ArrayList<Integer>();
		
		calcolaMedia(listaStudenti); //compila senza warning
		calcolaMediaStudenti(lista); //compila ma genera warning
		//calcolaMediaStudenti(listaInteri); //non compila
		
		
	}

	//METODO NON TYPE SAFE
	private static double calcolaMedia(List lista) { //compila ma genera warning
		double media = 0.;
		for (int i = 0; i < lista.size(); i++) {
			Studente s = (Studente) lista.get(i);
			media+=s.getMedia(); //necessita il downcasting
		}
		return (media/lista.size());
	}

	//METODO TYPE SAFE
	private static double calcolaMediaStudenti(List<Studente> listaStudenti) {
		double media = 0.;
		for (int i = 0; i < listaStudenti.size(); i++) {
			Studente s = listaStudenti.get(i);
			media+=s.getMedia(); //non necessita il downcasting
		}
		return (media/listaStudenti.size());
	}



}