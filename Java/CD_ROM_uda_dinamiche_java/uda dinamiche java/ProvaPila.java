import java.util.Random;
public class ProvaPila{
  public static void main(String[] args){


    Pila pTesta1 = new Pila();
    System.out.println(" P: " + pTesta1);
    System.out.println("\n inserisco tre elementi:");
    pTesta1.push(11);
    pTesta1.push(22);
    pTesta1.push(33);
    System.out.println(" P: " + pTesta1);

    System.out.println("\n rimozione di un elemento:");
    pTesta1.pop();
    System.out.println(" P: " + pTesta1);


    System.out.println("\n pop();\n pop();");
    pTesta1.pop();
    pTesta1.pop();
    System.out.println(" P: " + pTesta1);


    if (pTesta1.isEmpty())
      System.out.println(" La pila e' vuota");


  }
}
