import java.util.Random;

public class ArrInverso {

	public static void main(String[] args) {
		// Creare un array i cui elementi sono disposti al contrario rispetto all'array di partenza
		Random ran = new Random();
		
		final int DIM = 6;
		int[] array = new int[DIM];
		for(int i=0; i < array.length; i++)
			array[i] = ran.nextInt(100);
		
		int[] array_reversed = new int[array.length];
		//int x = 0;
		
		for(int i=array.length-1, x=0; i >= 0; i--){ //x++
			array_reversed[x++] = array[i];
			//oppure, senza usare x
			array_reversed[array.length-i-1] = array[i];
			/*0 -> 5
			1 -> 4
			2 -> 3
			3 -> 2
			4 -> 1
			5 -> 0*/
			//x++;
		}
		

		for(int i=0; i < array.length; i++)
			System.out.print(array[i]+" ");
		for(int i=0; i < array_reversed.length; i++)
			System.out.print(array_reversed[i]+" ");
			
	}
}