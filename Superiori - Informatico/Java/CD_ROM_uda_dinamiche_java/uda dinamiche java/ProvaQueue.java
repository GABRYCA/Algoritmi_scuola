import java.util.Random;
public class ProvaQueue{
  public static void main(String[] args){
    System.out.println("\f");
    System.out.println(" miaCoda1 = new Queue();");
    Queue miaCoda1 = new Queue();
    System.out.println(" C: " + miaCoda1);
        
    if (miaCoda1.isEmpty())
      System.out.println(" La coda e' vuota");
         
    System.out.println("\n enqueue(11);\n enqueue(22);\n enqueue(33);\n enqueue(44);");
    miaCoda1.enqueue(11);
    miaCoda1.enqueue(22);
    miaCoda1.enqueue(33);
    miaCoda1.enqueue(44);
    System.out.println(" C: " + miaCoda1);

    System.out.println("\n dequeue();\n dequeue();");
    miaCoda1.dequeue();
    System.out.println(" C: " + miaCoda1);
   
    System.out.println("\n dequeue();\n dequeue();");
    miaCoda1.dequeue();
    miaCoda1.dequeue();
    System.out.println(" C: "    + miaCoda1);
  
  }
}