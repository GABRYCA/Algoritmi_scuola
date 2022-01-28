import java.util.*;
import java.util.Scanner;
public class NotazionePolacca{
 public static int valutaPolacca(String s1){
  Integer valore = 0 , cifra = 0;
  Integer num1 = 0, num2 = 0;
  Stack s  = new Stack();
  // parsing della stringa input
  int lunga = s1.length();
  for (int x = 0; x < lunga; x ++){
   char c = s1.charAt(x); // prossimo carattere
   if (c != 32)           // diverso da spazio
    if ((c) > 47){        // (char)48 -> "0"
     cifra =Integer.parseInt(String.valueOf(c));
     s.push(cifra);
    }
    else{                   // e' un operatore
     num2=(Integer)s.pop(); // estraggo operandi
     num1=(Integer)s.pop();
     switch (c){
      case 43:  // (char)43 -> +
        valore = num1 + num2;
        break;
      case 45:  // (char)45 -> -
        valore = num1 - num2;
        break;
      case 42:  // (char)42 -> *
        valore = num1 * num2;
        break;
      }
      s.push(valore);    // impila risultato
    }
  }
  return valore;
 }

  //* trasforma da infissa a postfissa
  public String infissaPolacca(String strIn){
    String strOut = "";

    return strOut;
  }

  //* trasforma da postfissa a infissa
  public String polaccaInfissa(String strIn){
    String strOut = "";

    return strOut;
  }

  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    Integer risultato = 0;
    System.out.println("Valutazione polacca postfissa");
    // int k = (in.nextInt());   //
    String infissa= "( 1 + 2 ) * ( 6 - 4 )";
    String postfissa = "1 2 + 6 4 - *";
    risultato = valutaPolacca(postfissa);
    System.out.println("esp. infissa: " + infissa);
    System.out.println("esp. postfissa: " + postfissa);
    System.out.println("Risultato  : " + risultato.toString());

    infissa= "( 5 - 1 ) + ( 3 * 2 )";
    postfissa = "5 1 - 3 2 * +";
    risultato = valutaPolacca(postfissa);
    System.out.println("\nesp. infissa: " + infissa);
    System.out.println("esp. postfissa: " + postfissa);
    System.out.println("Risultato  : " + risultato.toString());


  }
}