import java.util.*;
import java.util.Random;

public class EsercizioVector2{
   public static int somma(Vector a){
    int somma=0;
      for (int i = 0; i < a.size(); i++){
        Dado elem =(Dado)a.elementAt(i);
        somma = somma + elem.valore;  
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
    Vector<Dado> vetDadi = new<Dado> Vector();    // vettore vuoto
    vetDadi.addElement(d1);        
    vetDadi.addElement(d2);        
    vetDadi.addElement(d3);        
    vetDadi.addElement(d4);        
    vetDadi.addElement(d5);        
    vetDadi.addElement(d6);        
    System.out.println("\n");

    // rimuove elemento al posto 3
    vetDadi.removeElementAt(3);
    System.out.println("\n vetDim3 : " + vetDadi);
 
    // ritorna la dimensione del vettore
    System.out.println("\n il vettore ha nr. celle: " + vetDadi.size());

    // ritorna l'oggetto presente nella posizione x-esima
    System.out.println("\n valore dado posizione 3 : " + vetDadi.elementAt(3));

    System.out.println("\n la somma dei dadi è:  " + somma(vetDadi)); 
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

