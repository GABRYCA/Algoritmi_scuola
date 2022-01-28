import java.util.*;
public class ListaLinked2 extends LinkedList{
 public void put(String stringa) {
  int x=0; boolean trovato=false, esiste=false;
  while (x < size() && ! trovato && !esiste){
   String dato = (String) get(x);
   if (dato.compareTo(stringa)>0)
    trovato=true;
   else
    if (dato.compareTo(stringa)==0)
      esiste=true;
    else
      x++;
    }
   add(x,stringa);
  }

  public static void main(String args[]){
   ListaLinked2 ll2=new ListaLinked2();
   String nomi[]={"Mario","Gio","Ali","Tom","Peo","Pina"};
   for (int x=0; x<nomi.length; x++) // crea lista di nomi
    ll2.put(nomi[x]);
   System.out.println("\nLista di "+ll2.size()+" nomi:");

   ListIterator lit=ll2.listIterator();
   System.out.print("Lettura diretta: []");
   while (lit.hasNext())
    System.out.print("->" + lit.next());
   System.out.println("->null");

   System.out.print("Lettura inversa: []");
   while (lit.hasPrevious())
    System.out.print("->" + lit.previous());
   System.out.println("->null");
  }
}

