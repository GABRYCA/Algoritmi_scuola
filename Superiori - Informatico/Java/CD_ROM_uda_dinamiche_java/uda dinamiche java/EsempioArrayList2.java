import java.util.ArrayList;
  public class EsempioArrayList2 {
    public static void main(String[] args) {
    ArrayList<String> lista = new ArrayList<String>();
    lista.add("Mele");
    lista.add("Pere");
    lista.add("Uova");
    lista.add(2, "Insalata");
    System.out.println(lista);   // metodo predefinito 
    lista.set(0, "Albicocche");
    System.out.println(lista);
    // utilizzando la funzione for-each
    for (String elemento : lista) {
      System.out.println(elemento);
    }
  }
}