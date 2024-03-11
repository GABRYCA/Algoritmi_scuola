import java.util.LinkedList;
import java.util.Scanner;

public class ProvaLinkedLists {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		//creazione lista di stringhe
		LinkedList<String> lista = new LinkedList<String>();
		
		System.out.print("Inserire una stringa (vuota per terminare) > ");
		String s = in.nextLine();
		while(!s.equals("")) {
			lista.add(s);
			//lista.addFirst(s); //come vengono inseriti gli elementi?
			System.out.print("Inserire una stringa (vuota per terminare) > ");
			s = in.nextLine();
		}
		
		System.out.println("Lista inserita for-each > "+stampaLista(lista));

		LinkedList<String> listaReverse = new LinkedList<String>();
		for(int i=lista.size()-1; i>=0; i--)
			listaReverse.add(lista.get(i)); //provare a usare addFirst e metodo reversed()
		
		System.out.println("\nLista inserita al contrario (for) > "+stampaLista(listaReverse));
	}
	
	private static String stampaLista(LinkedList<String> l){
		String ris = "";
		for(String tmp: lista)
			ris += tmp + " ";
		return ris;
	}
}