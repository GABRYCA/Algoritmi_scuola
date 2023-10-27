import java.util.Random;

public class EserciziArray {
	public static void main(String[] args){
		
		Random ran = new Random();
		
		final int DIM = 9;
		int[] array = new int[DIM];
		
		for(int i=0; i < array.length; i++){
			array[i] = ran.nextBoolean() ? ran.nextInt(100) : -ran.nextInt(100);
		}
		
		System.out.print("Array > [");
		for(int i=0; i < array.length; i++){
			System.out.print(array[i] + " ");
		}
		System.out.println("]");
		
		
		//ARRAY CHE CONTIENE SOLO LE POSIZIONI PARI/DISPARI DI UN ARRAY DI PARTENZA
		/*int contP = 0, contD = 0;
		
		for(int i=0; i < array.length; i++){
			if(i % 2 ==0){
				contP++;
			}
			else{
				contD++;		
			}
		} */
		
		int[] pari = new int[(DIM + 1) / 2];
		int[] dispari = new int[DIM / 2];
		
		for(int i=0, j=0, k=0; i < array.length; i++){
			if(i % 2 ==0){
				pari[j] = array[i];
				j++;
			}
			else{
				dispari[k] = array[i];
				k++;				
			}
		}
		
		System.out.print("posizioni pari > [");
		for(int i=0; i < pari.length; i++){
			System.out.print(pari[i] + " ");
		}
		System.out.println("]");
		
		System.out.print("posizioni dispari > [");
		for(int i=0; i < dispari.length; i++){
			System.out.print(dispari[i] + " ");
		}
		System.out.println("]");
		
		
		// REVERSE-> CREARE UN ARRAY I CUI ELEMENTI SONO DISPOSTI AL CONTRARIO RISPETTO A QUELLO DI PARTENZA
		int[] reverse = new int[DIM];
		
		if(array.length == reverse.length){
			for(int i = DIM-1, j = 0; i >= 0 || j < DIM; i--, j++){
				reverse[j] = array[i];
			}
		}
		
		System.out.print("array > [");
		for(int i=0; i < array.length; i++){
			System.out.print(array[i] + " ");
		}
		System.out.println("]");
		
		System.out.print("reverse > [");
		for(int i=0; i < reverse.length; i++){
			System.out.print(reverse[i] + " ");
		}
		System.out.println("]");
	}
}