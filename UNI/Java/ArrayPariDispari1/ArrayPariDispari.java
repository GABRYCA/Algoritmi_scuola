import java.util.Random;
public class ArrayPariDispari{
	public static void main(String[] args) {
		
		Random numero = new Random();
		//Full = grandezza dell'array completo, Dis = quello dispari, Par = quello pari
		int Full = numero.nextInt(10), Dis = (Full % 2 == 0) ? Full/2 : (Full/2) + 1, Par = Full/2; 
		int[] arrayFull = new int[Full], arrayDis = new int[Dis], arrayPar = new int[Par]; 
		
		System.out.print("Array di partenza -> [ ");
		//contFull = contatore per spostarmi di 1 nell'array completo
		for(int contFull = 0; contFull < arrayFull.length; contFull++){ 
			arrayFull[contFull] = numero.nextBoolean()? numero.nextInt(10) : -numero.nextInt(10);
			System.out.print(arrayFull[contFull] + " ");
		}
		System.out.println("]");
		
		System.out.print("Array con termini dispari dell'array di partenza -> [ ");
		//contDis = per spostarmi di 2 in quello dispari
		for(int contFull = 0, contDis = 0; contDis < arrayFull.length; contFull++, contDis += 2){ 
			arrayDis[contFull] = arrayFull[contDis];
			System.out.print(arrayDis[contFull] + " ");
		}
		System.out.println("]");
		
		System.out.print("Array con termini pari dell'array di partenza -> [ ");
		//contPar = per spostarmi di 1 in quello pari
		for(int contFull = 0, contPar = 1; contPar < arrayFull.length; contFull++, contPar += 2){ 
			arrayPar[contFull] = arrayFull[contPar];
			System.out.print(arrayPar[contFull] + " ");
		}
		System.out.println("]");
	}
}