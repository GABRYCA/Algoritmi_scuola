import java.util.Random;
public class ArrayReverse{
	public static void main(String[] args) {
		
		Random numero = new Random();
		int Full = numero.nextInt(10);
		int[] arrayNormal = new int[Full], arrayReverse = new int[Full]; 
		
		System.out.print("Array di partenza -> [ ");
		for(int contNormal= 0; contNormal < arrayNormal.length; contNormal++){ 
			arrayNormal[contNormal] = numero.nextBoolean()? numero.nextInt(10) : -numero.nextInt(10);
			System.out.print(arrayNormal[contNormal] + " ");
		}
		System.out.println("]");
		
		System.out.print("Array al contrario -> [ ");
		//contNormal = array.length da OutOfBound, contNormal >= 0 perchè mi serve anche il caso in cui è uguale a 0
		for(int contNormal = arrayNormal.length - 1, contReverse = 0; contNormal >= 0; contNormal--, contReverse++){ 
			arrayReverse[contReverse] = arrayNormal[contNormal];
			System.out.print(arrayReverse[contReverse] + " ");
		}
		System.out.println("]");
	}
}