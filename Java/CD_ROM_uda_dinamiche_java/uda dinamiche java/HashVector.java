import java.util.*;
import java.util.Random;
import java.util.Vector;

public class HashVector{
  static int NUM = 10;  
  static int hash_function(int data){
    return data % NUM;
  }
  
  static void inizializza (Vector[] tabella){  
  //inizializza la tabella con liste vuote 
   for (int x = 0; x < NUM; x++)
     tabella[x] = new Vector<Integer>();
  }
  
  static void visualizza (Vector[] tabella){  
    for (int x = 0; x < 10; x++)
      System.out.println ("bucket " + x +":->"+ tabella[x]);   
  }

  static int cerca (Vector<Integer> lista, int nuovo){  
    int bucket = hash_function (nuovo); // determino il bucket
    for (int x = 0; x < lista.size(); x ++)
      if (nuovo == lista.get(x))
         return 1;
    return 0;
  }
  static void add_elemento(Vector[] tabella, int nuovo){
    int bucket;
    bucket = hash_function (nuovo); // determino il bucket
    if (cerca(tabella[bucket], nuovo) == 1)
      return ; // se l’elemento esiste gia’ non lo inserisco 
    else
      tabella[bucket].add(nuovo); // lo accodo alla lista  
  }
  public static void main(String[] args){
    Random random = new Random();
    // vettore di Vector  
    Vector<Integer> tabella[] = new Vector[NUM];  //crea la tabella di hash      
    // inizializza la tabella con liste vuote 
    inizializza(tabella);  
    // inseriamo alcuni elementi  
    for (int n = 0; n < 20; n ++)
      add_elemento(tabella, random.nextInt(100));
    // visualizziamo la tabella di liste  
    visualizza(tabella);
  }
 
   public static void nonServono(Vector a){
    // System.out.println("\n");
    // Scanner in = new Scanner(System.in);
    // System.out.print("Inserisci il numero di elementi: ");
    // int k = (in.nextInt()); // ctr se c'e  ancora una riga
    //  non servono =========================   
    // un vector  
    Vector<Integer> v = new Vector<Integer>(3);
    // un vector di vector   
    Vector<Vector<Integer>> myVector = new Vector<Vector<Integer>>();
    // tabella di interi 
    int tabellaInt[] = new int[NUM];
    
    
   // System.out.println("contenuto di v: "+v);
   // System.out.println("capacita' di v: "+v.capacity());
   // System.out.println("n.elementi di v: "+v.size());
   // for (int i=0; i < v.size(); i++)
   //   System.out.println("elemento "+ i+": "+v.get(i));
   
   // Integer first = v.get(0);
   // System.out.println("primo elemento di v: "+ first);
   // System.out.println("ultimo elemento di v: "+v.get(v.size()-1));
   // System.out.println("la somma è di v: "+somma(v));
   // System.out.println("la somma è di v: "+sommaIter(v));
  }
}

