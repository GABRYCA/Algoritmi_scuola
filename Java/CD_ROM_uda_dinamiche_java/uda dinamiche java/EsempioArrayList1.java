import java.util.ArrayList;
public class EsempioArrayList1 {
public static void main(String[] args) {
ArrayList<String> lista = new ArrayList<String>();
lista.add("Mele");
lista.add("Pere");
lista.add("Uova");
lista.add(2, "Insalata");
System.out.println(lista);
}
}