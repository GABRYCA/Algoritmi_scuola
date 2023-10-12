import java.util.Random;
public class AlberoBinOKTest{
  public static void main(String[] args){ 
    System.out.println("\n");
	System.out.println("");
	System.out.println("\n");
	AlberoBinOK t7 = new AlberoBinOK(7);
	AlberoBinOK t6 = new AlberoBinOK(6);
	AlberoBinOK t5 = new AlberoBinOK(5, t6, t7);
	AlberoBinOK t4 = new AlberoBinOK(4);
	AlberoBinOK t3 = new AlberoBinOK(3);
	AlberoBinOK t2 = new AlberoBinOK(2, t4, t5);
	AlberoBinOK t1 = new AlberoBinOK(1, t2, t3);		
	System.out.println("t1: " + t1);
	System.out.println("Visita in ampiezza  : " + t1.visitaInAmpiezza());
	System.out.println("Visita in profondita: " + t1.visitaInProfondita());
  }
}
