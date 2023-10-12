import java.util.*;
public class PilaStack1{
  static void showStack(Stack mia){
  Stack tempo  = new Stack(); // ne fa una copia
  tempo.addAll(mia);
  while (!tempo.empty()){
   System.out.println("| "+ tempo.pop() + " |");
  }
  System.out.println("------\n");
 }
 public static void main(String args[]){
  Stack pila1 = new Stack();   // crea una pila
  System.out.println("\ninserisco 3 elementi:");
  pila1.push(new Integer(11));   // impila
  pila1.push(new Integer(22));
  pila1.push(new Integer(33));
  showStack(pila1);
  System.out.println("\nrimuovo un elemento:");
  pila1.pop();                   // spila
  showStack(pila1);
 }
}

/*
 static void showStack1(Stack mia){
  Stack tempo  = new Stack();   // ne fa una copia
  tempo.addAll(mia);
  while (!tempo.empty()){
   System.out.println("| "+ tempo.peek() + " |");
   tempo.pop();
  }
  System.out.println("------\n");
 }
*/

