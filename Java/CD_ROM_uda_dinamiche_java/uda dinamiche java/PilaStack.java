import java.util.*;
public class PilaStack{
 public static void main(String args[]){
  Stack pTesta1 = new Stack();   // crea una pila
  System.out.println("\ninserisco tre elementi:");
  pTesta1.push(new Integer(11));   // impila
  pTesta1.push(new Integer(22));
  pTesta1.push(new Integer(33));
  System.out.println(pTesta1);
  System.out.println("\nrimuovo un elemento:");
  pTesta1.pop();                   // spila
  System.out.println(pTesta1);
 }
}


