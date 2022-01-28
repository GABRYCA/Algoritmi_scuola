import java.util.ArrayList;
public class EsempioArrayList3 {
  public static void main(String[] args) {
    ArrayList<Object> v = new ArrayList<Object>();
    //   ArrayList<String> v = new ArrayList<String>();
    System.out.println("n.elementi di v: "+v.size());
    v.add("albero");
    v.add("banana");
    v.add("denti");
    v.add("elevatore");
    v.add(2,"cuscino"); // inserisce “ccc” prima di “ddd”
    System.out.println("n. elementi di v: "+v.size());
    for (int i=0; i<v.size(); i++)
      System.out.println("elemento "+ i+": "+v.get(i));
    System.out.println("primo: "+v.get(0));
    System.out.println("ultimo: "+v.get(v.size()-1));
    String s = (String)v.get(0);         // downcast obbligatorio
  
  }
}