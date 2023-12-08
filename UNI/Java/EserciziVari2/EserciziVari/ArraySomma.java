package esercizivari;

import java.util.ArrayList;

public class ArraySomma {
	public static void main(String[] args) {
		int[] numeri = {2, 3, 5, 1, 4};
		int somma = 7;
		
		ArrayList<int[]> coppie = new ArrayList<int[]>();
		
		for(int i =0; i<numeri.length; i++) {
			for(int j = i + 1; j < numeri.length; j++) {
				
				int[] coppia = new int[2];
				if(numeri[i]+numeri[j] == somma) {
					coppia[0] = numeri[i];
					coppia[1] = numeri[j];
					coppie.add(coppia);
				}
			}
		}
		
		System.out.println("Coppie: ");
		for(int[] c: coppie)
			System.out.println("[" + c[0] + ", " + c[1] + "]");
	}
}
