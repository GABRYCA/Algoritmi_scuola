import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;



public class TestSet {
	public static void main(String[] args) {
 		Set<Integer> s1 = new HashSet<Integer>();
		s1.add(new Integer(1));
		s1.add(new Integer(2));
		System.out.println("s1 : "+s1);
		
		Set<Integer> s2 = new HashSet<Integer>();
		s2.add(new Integer(1));
		s2.add(new Integer(3));
		System.out.println("s2 : "+s2);
		
		
		
		Set<Integer> union = unione(s1,s2);
		System.out.println("unione : "+union);

		Set<Integer> intersection = intersezione(s1,s2);
		System.out.println("intersezione : "+intersection);
	
	
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < 3; i++) {
			set.add(i);
		}
		System.out.println("insieme : "+set);
		
		
		double media = calcolaMedia(set);
		System.out.println("media : "+media );		
		

		Set<Set<Integer>> insiemi = new HashSet<Set<Integer>>();
		insiemi.add(s1);
		insiemi.add(s2);
		insiemi.add(new HashSet<Integer>());
		System.out.println("insiemi : "+insiemi);
		Set<Integer> best = migliorMedia(insiemi );
		System.out.println("insieme con miglior media : "+best);

		Set<Set<Integer>> subsets = sottoinsiemi(set);
		System.out.println("sottoinsiemi : "+subsets);


		Set<Integer> empty = new HashSet<Integer>();
		System.out.println(calcolaMedia(empty));
		Set<Set<Integer>> sets = new HashSet<Set<Integer>>(subsets);
		System.out.println(migliorMedia(sets));
		
		
	}

	
	
	/**
	 * Calcola la media degli elementi dell'insieme di interi set. 
	 * Per convenzione l'insieme vuoto ha media pari al valore minimo per gli interi 
	 * 
	 * @param set insieme di interi di cui si vuole calcolare la media
	 * @return la media degli elementi che costituiscono l'insieme o Integer.MIN_VALUE se l'insieme e' vuoto  
	 * */
	private static double calcolaMedia(Set<Integer> set) {
		double media = 0;
		for (Iterator<Integer> iterator = set.iterator(); iterator.hasNext();) {
			Integer elem = iterator.next();
			media+=elem;
		}
		return set.size()>0?media/set.size():Integer.MIN_VALUE;
	}

	/**
	 * Calcola l'unione tra s1 ed s2, il metodo non modifica s1 ed s2
	 * 
	 * @param s1 primo insieme
	 * @param s2 secondo insieme
	 * @return l'insieme costituito dalla unione di s1 ed s2
	 * */
	private static Set<Integer> unione(Set<Integer> s1, Set<Integer> s2) {
		Set<Integer> res = new HashSet<Integer>(s1); 
		res.addAll(s2);
		return res;
	}


	/**
	 * Calcola l'insieme cha ha media piu' alta tra tutti 
	 * gli insiemi di interi passati come parametro
	 * 
	 * @param sets l'insieme di insiemi di interi
	 * @return l'insieme di interi con media piu' alta tra tutti gli insiemi in subsets
	 * */
	private static Set<Integer> migliorMedia(Set<Set<Integer>> sets) {
		System.out.println("metodo da implementare");
		return null;
	}


	
	/**
	 * Calcola l'intersezione di s1 ed s2, il metodo non modifica s1 ed s2
	 * 
	 * @param s1 primo insieme
	 * @param s2 secondo insieme
	 * @return l'insieme costituito dall'intersezione di s1 ed s2
	 * */
	private static Set<Integer> intersezione(Set<Integer> s1, Set<Integer> s2) {
		System.out.println("metodo da implementare");
		return null;
	}
	
	/**
	 * Calcola tutti i possibili sottoinsiemi di un insieme in maniera ricorsiva
	 * Il metodo non modifica l'insieme s
	 * 
	 * @param s insieme di cui si vogliono calcolare tutti i sottoinsiemi
	 * @return tutti i sottoinsiemi dell'insieme s  
	 * */
	private static Set<Set<Integer>> sottoinsiemi(Set<Integer> s) {
		System.out.println("metodo da implementare");
		return null;
	}




	
	
	
}