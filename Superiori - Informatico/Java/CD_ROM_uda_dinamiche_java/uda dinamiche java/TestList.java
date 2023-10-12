import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class TestList {
  public static void main(String[] args) {
    Object[] a = {1,2,3}; 
    List la = new ArrayList();
    fill(la,a);
    List ll = new LinkedList();
    fill(ll,a);
    Object[] o = {new Studente("001"),new Studente("002"),3};
    List lista = new ArrayList();
    fill(lista,o);
  }

  protected static void fill(List l, Object[] a) {
    for (int i = 0; i < a.length; i++) {
     l.add(i,a[i]);
    }
    for (int i = 0; i < l.size(); i++) {
     System.out.println("elemento in posizione "+ i + " " + l.get(i));
    }
  }
}