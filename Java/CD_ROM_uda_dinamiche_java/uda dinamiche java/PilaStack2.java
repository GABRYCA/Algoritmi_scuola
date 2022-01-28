import java.util.*;
public class PilaStack2{
 public static void main(String args[]){
  Stack pila2 = new Stack();    // crea una pila
  System.out.print("\ninserisco tre numeri:\n");
  pila2.push(new Integer(11));  // inserisce (impila)
  pila2.push(new Integer(22));
  pila2.push(new Integer(33));
  System.out.println(pila2);    // mostra la pila come array
  System.out.print("\nli visualizzo a rovescio:\n ");
  System.out.print("["+pila2.peek()+", "); // accede al top
  pila2.pop();                             // rimuove (spila)
  System.out.print(pila2.peek()+", ");
  pila2.pop();
  System.out.print(pila2.peek()+"]");
  pila2.pop();
 }
}
