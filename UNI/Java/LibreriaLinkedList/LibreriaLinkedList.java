import java.util.LinkedList;
import java.util.Scanner;

public class LibreriaLinkedList {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		LinkedList<String> lista = new LinkedList<String>();
		
		System.out.print("Inserire un genere (A = Azione, C = Commedia, G = Giallo, END per terminare) > ");
		String scelta = in.nextLine().toUpperCase();
		while(!scelta.equals("END")) {
			lista.add(scelta);
			System.out.print("Inserire un genere (A = Azione, C = Commedia, G = Giallo, END per terminare) > ");
			scelta = in.nextLine().toUpperCase();;
		}
		
		int numA=0, numC=0, numG=0;
		for(int i=0; i<lista.size(); i++) {
			switch(lista.get(i)){
				case "A": numA++;
						  System.out.println("Inserito libro genere "+Genere.AZIONE);
						  break;
				case "C": numC++;
						  System.out.println("Inserito libro genere "+Genere.COMMEDIA);
						  break;
				case "G": numG++;
						  System.out.println("Inserito libro genere "+Genere.GIALLO);
						  break;
				default: System.out.println("Genere inserito NON valido");
			}
		}
		
		System.out.println("Numero libri inseriti genere "+Genere.AZIONE.ordinal()+" "+Genere.AZIONE.name()+" > "+numA);
		System.out.println("Numero libri inseriti genere "+Genere.COMMEDIA.ordinal()+" "+Genere.COMMEDIA.name()+" > "+numC);
		System.out.println("Numero libri inseriti genere "+Genere.GIALLO.ordinal()+" "+Genere.GIALLO.name()+" > "+numG);
	}
}