import java.util.Arrays;
import java.util.Random;
public class ArrayElementiPariDispari{
    public static void main(String[] args){
        final int DIM=10;
        int[] array1=new int[DIM];
        Random random=new Random();
        
        for(int i=0;i<array1.length;i++){
            array1[i]=random.nextInt(100);
        }
        System.out.println("\nprimo array:");
        for(int i=0;i<array1.length;i++){
            System.out.print(array1[i]+" ");
        }
        int[] array2=new int[DIM];
        for(int i=0;i<array2.length;i++){
            array2[i]=random.nextInt(10);
        }
        System.out.println("\nsecondo array:");
        for(int i=0;i<array2.length;i++){
            System.out.print(array2[i]+" ");
        }
        
		//creare un array che contiene solo elementi in posizione pari/dispari dell'array di partenza;
            int npari=0;
            int ndispari=0;
            for(int i=0;i<array1.length;i++){
                if(array1[i]%2==0){
                    npari++;
                }
                else{
                    ndispari++;
                }
            }
            int[]pari=new int[npari];
            int[]dispari=new int[ndispari];
            for(int i=0,p=0,d=0; i<array1.length;  i++){
                if(array1[i]%2==0){
                    pari[p]=array1[i];
                    p++;
                }
                else{
                    dispari[d]=array1[i];
                    d++;
                }
            }

            System.out.println("\narray pari:");
            for(int i=0;i<pari.length;i++){
                System.out.print(pari[i]+" ");
            }
            System.out.println("\narray dispari");
            for(int i=0;i<dispari.length;i++){
                System.out.print(dispari[i]+" ");
            }
                 

        
    }
}
