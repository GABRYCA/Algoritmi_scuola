import java.util.*;
import java.util.Random;

public class ProvaVector{
  public static int somma(Vector a){
    int somma=0;
    Iterator i=a.iterator(); // con iteratori
    while (i.hasNext()){
      Integer val=(Integer)i.next();
      somma=somma+val.intValue();
    }
    return somma;
  }

  public static void main(String[] args){
   System.out.println("\n");
   Dado d1 = new Dado();
   Dado d2 = new Dado();
   Dado d3 = new Dado();
   Dado d4 = new Dado();
   Dado d5 = new Dado();
   Dado d6 = new Dado();

   Vector vetDim1 = new Vector();    // vettore vuoto
   vetDim1.addElement(d1);           // aggiunge un dado
   vetDim1.addElement("banana");     // aggiunge una stringa
   System.out.println(" vetDim1 : " + vetDim1);
   System.out.println("\n");
   
   Vector vetDim2 = new Vector(4);   // vettore di 4 elementi
   vetDim2.addElement("umano");      // nome giocatore 1
   vetDim2.addElement(d1);           // aggiunge un dado
   vetDim2.addElement("robot");      // nome giocatore 2
   vetDim2.addElement(d2);           // aggiunge un dado
   System.out.println(" vetDim2 : " + vetDim2);
   System.out.println("\n");


   Vector vetDim3 = new Vector(4,2); // vettore di 4 elementi
   vetDim3.addElement(d1);           // aggiunge un oggetto al vettore
   vetDim3.addElement(d2);           // aggiunge un oggetto al vettore
   vetDim3.addElement(d3);           // aggiunge un oggetto al vettore
   vetDim3.addElement(d4);           // aggiunge un oggetto al vettore
   vetDim3.addElement(d5);           // aggiunge un oggetto al vettore
   vetDim3.addElement(d6);           // aggiunge un oggetto al vettore
   System.out.println(" vetDim3 : " + vetDim3);
   System.out.println("\n");

   // rimuove elemento al posto 3
   vetDim3.removeElementAt(3);
   System.out.println("\n vetDim3 : " + vetDim3);
 
   // ritorna la dimensione del vettore
   System.out.println("\n il vettore ha nr. celle: " + vetDim3.size());

   // ritorna l'oggetto presente nella posizione x-esima
   System.out.println("\n valore dado posizione 3 : " + vetDim3.elementAt(3));

   Vector vetNumeri = new Vector(5); // vettore di 5 elementi
   vetNumeri.addElement(5);
   vetNumeri.addElement(3);
   vetNumeri.addElement(4);
   vetNumeri.addElement(8);
   vetNumeri.addElement(2);

   //ritorna il totale degli elementi
   System.out.println(" vetNumeri : " + vetNumeri);
   System.out.println("\n la somma dei dadi è:  " + somma(vetNumeri)); 
  }
}

class Dado{
  int valore;
  public Dado()
  {
    valore=(int)Math.floor(Math.random()*6)+1; // valore da 1 a 6
  }
  public String toString(){
    String s = "";
    return s + valore;
  }
}

