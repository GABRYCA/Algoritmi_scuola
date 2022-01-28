import java.util.Random;
import java.util.Scanner;
public class ProvaLista{
  public static void main(String[] args){
  Scanner in = new Scanner(System.in);
  System.out.println("\n");
  System.out.println("");

  System.out.println("\n");
  System.out.println("Lista l = new Lista();");
  Lista miaLista1 = new Lista();
  System.out.println(" l: " + miaLista1);

  /*
  // crea una lista di 5 elementi
  System.out.println("\n");
  System.out.println(" l = l.cons(5);\n l = l.cons(15);\n l = l.cons(1);\n l = l.cons(3);\n l = l.cons(30);");
  miaLista1 = miaLista1.cons(5);
  miaLista1 = miaLista1.cons(15);
  miaLista1 = miaLista1.cons(1);
  miaLista1 = miaLista1.cons(3);
  miaLista1 = miaLista1.cons(30);
  System.out.println(" l: " + miaLista1);
*/

  // crea una lista inserendo in testa 4 elementi
  System.out.println("\n");
  System.out.println(" l = l.addTesta(6);\n l = l.addTesta(16);\n l = l.addTesta(2);\n l = l.addTesta(4);");
  miaLista1.addTesta(6);
  miaLista1.addTesta(16);
  miaLista1.addTesta(2);
  miaLista1.addTesta(4);
  System.out.println("l: " + miaLista1);

  // crea una lista inserendo ordinati 4 elementi 
  // funziona

  System.out.println("\n");
  System.out.println(" l = l.inserisci(6);\n l = l.inserisci(16);\n l = l.inserisci(8);\n l = l.inserisci(3);\n l = l.inserisci(6);\n l = l.inserisci(8);");
  miaLista1.inserisci(6);
  miaLista1.inserisci(16);
  miaLista1.inserisci(8);
  miaLista1.inserisci(3);
  miaLista1.inserisci(6);
  miaLista1.inserisci(8);
  System.out.println(" l: " + miaLista1);


  System.out.println(" l: togli testa ");
  miaLista1.togliTesta();
  System.out.println(" l: " + miaLista1);
  miaLista1.togliTesta();
  System.out.println(" l: " + miaLista1);

  System.out.println(" l: togli coda ");
  miaLista1.togliCoda();
  System.out.println(" l: " + miaLista1);
  miaLista1.togliCoda();
  System.out.println(" l: " + miaLista1);
  
  System.out.println(" l: togli in mezzo il numero : " );
  int x = (in.nextInt());        // ctr se c'e  ancora una riga
  miaLista1.togliMezzo(x);
  System.out.println(" l: " + miaLista1);
  
 System.out.println(" l: togli in mezzo il numero : " );
 x = (in.nextInt());        // ctr se c'e  ancora una riga
  miaLista1.togliMezzo(x);
  System.out.println(" l: " + miaLista1);
 System.out.println(" l: togli in mezzo il numero : " );
   x = (in.nextInt());        // ctr se c'e  ancora una riga
  miaLista1.togliMezzo(x);
  System.out.println(" l: " + miaLista1);
 System.out.println(" l: togli in mezzo il numero : " );
   x = (in.nextInt());        // ctr se c'e  ancora una riga
  miaLista1.togliMezzo(x);
  System.out.println(" l: " + miaLista1);

  
  System.out.println("\n");
  System.out.println(" miaLista1.removeAll(8, false)");
  miaLista1.removeAll(8, false);
  System.out.println(" l: " + miaLista1);


  System.out.println("\n");
  System.out.println(" miaLista1.removeAll(6, true)");
  miaLista1.removeAll(6, true);
  System.out.println(" l: " + miaLista1);
  System.out.print("\n\n Ricerca di un elemento 9");

  // cerco un elemento    //da ctr 
  if (miaLista1.inLista(9))
    System.out.print("\n l'elemento 9 e' nella lista\n");
  else 
    System.out.print("\n l'elemento 9 non e' nella lista\n");

  System.out.print("\n\n Inserisci il numero da cercare: " );
  int k = (in.nextInt());        // ctr se c'e  ancora una riga
  if (miaLista1.inLista(k))
    System.out.print("\n l'elemento e' nella lista\n");
  else 
    System.out.print("\n l'elemento non e' nella lista\n");

  System.out.print("\n\n Inserisci il numero da cercare: " );
  k = (in.nextInt());        // ctr se c'e  ancora una riga
  if (miaLista1.inLista(k))
    System.out.print("\n l'elemento e' nella lista\n");
  else 
    System.out.print("\n l'elemento non e' nella lista\n");
      
  System.out.print("\n\n Crea lista random ");  
  System.out.print("\n\n Inserisci il numero di elementi: " );  
  k = (in.nextInt());        // ctr se c'e  ancora una riga
  // miaLista1= creaListaCasuale(k); 


  // crea una lista di 4 elementi
  System.out.println("\n");
  System.out.println(" l = l.add(6);\n l = l.add(16);\n l = l.add(2);\n l = l.add(4);");
  miaLista1.add(6);
  miaLista1.add(16);
  miaLista1.add(2);
  miaLista1.add(4);
  System.out.println(" l: " + miaLista1);

// crea una lista accodando 4 elementi

  System.out.println("\n");
  System.out.println(" l = l.addCoda(6);\n l = l.addCoda(16);\n l = l.addCoda(2);\n l = l.addCoda(4);");
  miaLista1.addCoda(6);
  miaLista1.addCoda(16);
  miaLista1.addCoda(2);
  miaLista1.addCoda(4);
  System.out.println(" l: " + miaLista1);
  }
}