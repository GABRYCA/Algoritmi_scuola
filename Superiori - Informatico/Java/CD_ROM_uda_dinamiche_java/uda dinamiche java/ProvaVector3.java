import java.util.*;
import java.util.Random;
import java.util.Vector;
public class ProvaVector3{
  public static void main(String[] args){
    System.out.println("\n");
    Vector<Integer> v = new Vector<Integer>(3);
    System.out.println("contenuto di v: "+v);
    System.out.println("capacita' di v: "+v.capacity());
    System.out.println("n.elementi di v: "+v.size());
    v.add(5);
    v.add(3);
    v.add(4);
    v.add(8);
    v.add(2);
    
    System.out.println("contenuto di v: "+v);
    System.out.println("capacita' di v: "+v.capacity());
    System.out.println("n.elementi di v: "+v.size());
    for (int i=0; i < v.size(); i++)
      System.out.println("elemento "+ i+": "+v.get(i));
   
    Integer first = v.get(0);
    System.out.println("primo elemento di v: "+ first);
    System.out.println("ultimo elemento di v: "+v.get(v.size()-1));
    System.out.println("la somma è di v: "+somma(v));
    System.out.println("la somma è di v: "+sommaIter(v));
    
  }
  public static int somma(Vector a){
    int somma=0;
      for (int i=0;i<a.size();i++){
        Integer elem=(Integer)a.get(i);
        somma=somma+elem.intValue(); //tipo primitivo
      }
    return somma;
  }
   public static int sommaIter(Vector a){
     int somma = 0;
     Iterator i = a.iterator();
     while (i.hasNext()){
	Integer val=(Integer)i.next();
	somma = somma  +val.intValue();
     }
    return somma;
  }
}

