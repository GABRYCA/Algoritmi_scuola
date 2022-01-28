import java.util.Vector;
import java.util.Random;

public class Vector0{

 public static void main(String[] args){
  Random random = new Random();
  int x, num, tanti;
  Vector<Integer> mioVet=new Vector<Integer>();
  // crea il vettore dinamicamente
  do{
   num = 1 + random.nextInt(9);
   mioVet.add(num);         // aggiunge in coda
  } while(num!=5);
  // visualizza il vettore
  System.out.println("\n"); // a linea nuova
  tanti = mioVet.size();    // nr. elementi
  for(x = 0; x < tanti; x++)
   System.out.print(mioVet.get(x) + " ");
 }
}



   // System.out.println("contenuto di v: "+mioVet);
