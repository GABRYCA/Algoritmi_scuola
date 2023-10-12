import java.util.Random;
import java.util.Scanner;
public class ProvaAlberoBin{
  public static void main(String[] args){
    System.out.println("\f");

    System.out.println("AlberoBin mioAlbero1 = new AlberoBin();");
    AlberoBin mioAlbero0 = new AlberoBin();
    System.out.println(" mioAlbero0 : " + mioAlbero0);

    mioAlbero0.insNode(4);
    mioAlbero0.insNode(2);
    mioAlbero0.insNode(1);
    mioAlbero0.insNode(3);
    mioAlbero0.insNode(6);
    mioAlbero0.insNode(5);
    mioAlbero0.insNode(7);
    System.out.println(" mioAlbero0 : " + mioAlbero0);

    AlberoBin mioAlbero1 = new AlberoBin();
    int heap1[] = {10,8,-9,0,15,0,3};
    mioAlbero1.crea_da_array(heap1, 0, 7);
    System.out.println(" mioAlbero1 : " + mioAlbero1);
    
    AlberoBin mioAlbero2 = new AlberoBin();
    int heap2[] = {10,4,30,0,8,16,50};
    mioAlbero2.crea_da_array(heap2, 0, 7);
    System.out.println(" mioAlbero2 : " + mioAlbero2);
    
   
    
    System.out.print("\npreorder  : ");
    mioAlbero1.preorder(mioAlbero1.radice);
    System.out.print("\ninorder   : ");
    mioAlbero1.inorder(mioAlbero1.radice);
    System.out.print("\npostorder : ");
    mioAlbero1.postorder(mioAlbero1.radice);
   
    mioAlbero1.inorder1();
    mioAlbero1.preorder1();
    mioAlbero1.postorder1();
    
    
    Scanner in = new Scanner(System.in);
    System.out.print("\nnInserisci il numero da ricercare:  ");
    int k = (in.nextInt());        // ctr se c'e  ancora una riga
    if (mioAlbero1.ABR_cercaRic(mioAlbero1.radice, k))
      System.out.print("\nl'elemento è presente!");
    else
      System.out.print("\nl'elemento non è presente!  ");
    
    
   
    
    

  }
}
