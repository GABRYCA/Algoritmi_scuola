import java.util.Random;
public class ProvaQueue1{
  public static void main(String[] args){
    Queue miaCoda1 = new Queue();
    System.out.println(" C: " + miaCoda1);
    System.out.println("\n accodo 4 elementi:");
    miaCoda1.enqueue(11);
    miaCoda1.enqueue(22);
    miaCoda1.enqueue(33);
    miaCoda1.enqueue(44);
    System.out.println(" C: " + miaCoda1);
    System.out.println("\n tolgo due elementi:");
    miaCoda1.dequeue();
    miaCoda1.dequeue();
    System.out.println(" C: "    + miaCoda1);

  }
}