import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class ListeGeneriche {
  public static void main(String[] args){
    // lista oggetti <Integer
    Integer num1 = new Integer(10);
    Integer num2 = new Integer(18);
    LinkedList<Integer> listaI = new LinkedList<Integer>();
    listaI.add(num1);
    listaI.add(num2);
    double media1 = mediaInteri(listaI);
    System.out.println("media interi "+ media1);
    // lista oggetti Studenti
    Studente s1 = new Studente("M001");
    s1.setMedia(25);
    Studente s2 = new Studente("M002");
    s2.setMedia(27);
    LinkedList<Studente> listaS = new LinkedList<Studente>();
    listaS.add(s1);
    listaS.add(s2);
    double media2 = mediaStudenti(listaS);
    System.out.println("media studenti "+ media2);
  }

  private static double mediaInteri(List<Integer> lista1){
    double media = 0.;
    for (int i = 0; i < lista1.size(); i++){
      Integer num1 = lista1.get(i);
      media+=num1;
    }
    return (media/lista1.size());
  }

  private static double mediaStudenti(List<Studente> lista1){
    double media = 0.;
    for (int i = 0; i < lista1.size(); i++){
      Studente s = lista1.get(i);
      media+=s.getMedia();
    }
    return (media/lista1.size());
  }

}


