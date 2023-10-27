import java.util.Random;

public class ArrPari {

	public static void main(String[] args) {
		// Creare un array che contiene solo gli elementi in posizione pari dell'array di partenza
		Random ran = new Random();
		
		final int DIM = 10;
		int[] array = new int[DIM];
		for(int i=0; i < array.length; i++)
			array[i] = ran.nextInt(100);
		
		int[] array_out;
		
		if (array.length%2 == 1)
			array_out = new int[(array.length/2)+1];
		else
			array_out = new int[array.length/2];
		
		int x = 0;
		
		for(int i=0; i < array.length; i++){
			if ((i+1)%2 == 0){
				//System.out.println("In");
				array_out[x] = array[i];
				x++;
				
			}
		}
			
		for(int i=0; i < array_out.length; i++)
			System.out.println(array_out[i]);
			
	}
}