import java.util.*;
public class ListeLinked {
    public static void main(String args[]){
    LinkedList lista =new LinkedList(); // creo la lista
    Integer I =new Integer(69);
    lista.add(I);			// aggiungo un intero
    String S = new String ("pizza");
    lista.add(S);			// aggiungo una stringa
    Boolean B = new Boolean(true);
    lista.add(B);			// aggiungo una booleano
    S = new String ("Margherita");
    lista.add(S);           // aggiungo un double
    Double D =new Double(16.61);
    lista.add(D);
    System.out.println("Lista di "+lista.size()+" Oggetti:");
    ListIterator lit=lista.listIterator();
    System.out.print("Lettura diretta: []");
    while (lit.hasNext())
      System.out.print("->"+lit.next());
    System.out.println("->null");
    System.out.print("Lettura inversa: []");
    while (lit.hasPrevious())
      System.out.print("->"+lit.previous());
    System.out.println("->null");
  }
}
