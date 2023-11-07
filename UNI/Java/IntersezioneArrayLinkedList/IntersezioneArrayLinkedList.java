import java.util.LinkedList;
import java.util.Random;

public class IntersezioneArrayLinkedList {

	public static void main(String[] args) {
		Random ran = new Random();
		
		int[] a = generaArray(ran.nextInt(10));
		int[] b = generaArray(ran.nextInt(10));
		
		System.out.println("Array a > [ "+stampaArray(a));
		System.out.println("Array b > [ "+stampaArray(b));
		
		LinkedList<Integer> lista = new LinkedList<Integer>();
		
		for(int i=0; i < a.length; i++){
			for(int j=0; j < b.length; j++){
				if(a[i] == b[j] && !lista.contains(a[i])){
					lista.add(b[j]);
				}
			}
		}
		
		System.out.print("Lista intersezione > ");
		for(Integer tmp: lista)
			System.out.print(tmp + " ");
	}
	
	private static int[] generaArray(int num) {
		Random ran = new Random();
		int[] array = new int[num];
		for(int i=0; i < array.length; i++)
			array[i] = ran.nextBoolean() ? ran.nextInt(5): -ran.nextInt(5);
		return array;
	}
	
	private static String stampaArray(int[] array) {
		String ris = "";
		for(int i=0; i < array.length; i++)
			ris += array[i] + " ";
		ris += "]";
		return ris;
	}
}