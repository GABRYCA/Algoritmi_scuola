import java.util.Random;

public class ProvaArray {

	public static void main(String[] args) {
		Random ran = new Random();
		
		final int DIM = 10;
		
		//primo array
		//int[] array; //array dichiarato, ma non definito
		//int[] array = null;//array nullo
		int[] array = new int[DIM];
		
		for(int i=0; i < array.length; i++)
			array[i] = ran.nextBoolean() ? ran.nextInt(100): -ran.nextInt(100);
		
		System.out.print("Array 1 > [ ");
		for(int i=0; i < array.length; i++)
			System.out.print(array[i] + " ");
		System.out.println("]");
		
		//secondo array
		int[] array2 = new int[DIM];
		
		for(int i=0; i < array2.length; i++)
			array2[i] = ran.nextBoolean() ? ran.nextInt(100): -ran.nextInt(100);
		
		System.out.print("Array 2 > [ ");
		for(int i=0; i < array2.length; i++)
			System.out.print(array2[i] + " ");
		System.out.println("]");
		
		//SOMMA DI DUE ARRAY
		if(array.length == array2.length) {
			//creazione array per contenere il risultato
			int[] somma = new int[array.length];
			for(int i=0; i < array.length; i++)
				somma[i] = array[i] + array2[i];
			
			System.out.print("Somma > [ ");
			for(int i=0; i < somma.length; i++)
				System.out.print(somma[i] + " ");
			System.out.println("]");
		}
		
		//TROVARE L'ELEMENTO MAGGIORE/MINORE IN UN ARRAY
		int max = array[0];
		for(int i=1; i < array.length; i++)
			if(array[i] > max)
				max = array[i];
		System.out.println("Elemento maggiore contenuto nell'array > "+max);
		
		//e se array fosse null?
		if(array != null) {
			max = array[0];
			for(int i=1; i < array.length; i++)
				if(array[i] > max)
					max = array[i];
			System.out.println("Elemento maggiore contenuto nell'array > "+max);
		}
		
		//e se array fosse null? e se array avesse dimensione 0?
		//int max;
		for(int i=0; array != null && i < array.length; i++) //lazy evaluation
			if(i == 0 || array[i] > max) //lazy evaluation
				max = array[i];
		System.out.println("Elemento maggiore contenuto nell'array > "+max);
		
		//CREARE UN ARRAY CHE CONTIENE SOLO GLI ELEMENTI IN
		//POSIZIONE PARI/DISPARI DELL'ARRAY DI PARTENZA
		int[] pari = new int[DIM];
		int[] dispari = new int[DIM];
		for(int i = 0; i < array.length; i++){
			if (i % 2 == 0) { // Pari
				pari[i] = array[i];
				dispari[i] = 0;
			} else { // Dispari
				dispari[i] = array[i];
				pari[i] = 0;
			}
		}

		System.out.print("Array pari: [ ");
		for (int i = 0; i < array.length; i++){
			System.out.print(pari[i] + " ");
		}
		System.out.print("] \nArray Dispari: [ ");
		for(int i = 0; i < array.length; i++){
			System.out.print(dispari[i] + " ");
		}
		System.out.println("]");

		
		//REVERSE -> CREARE UN ARRAY I CUI ELEMENTI SONO DISPOSTI
		//AL CONTRARIO RISPETTO ALL'ARRAY DI PARTENZA
		int[] reverse = new int[DIM];
		for(int i = array.length - 1, j = 0; i >= 0; i--, j++){
			reverse[j] = array[i];
		}

		System.out.print("Array normale: [ ");
		for(int i = 0; i < array.length; i++){
			System.out.print(array[i] + " ");
		}

		System.out.print("] \nArray reverse: [ ");
		for(int i = 0; i < array.length; i++){
			System.out.print(reverse[i] + " ");
		}
		System.out.println("]");

	}
}