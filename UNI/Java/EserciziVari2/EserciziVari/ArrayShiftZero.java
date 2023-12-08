package esercizivari;

public class ArrayShiftZero {

	public static void main(String[] args) {
		int[] numeri = { 13, 4, 0, 43, 0, 3 };

		System.out.println("Array iniziale: ");
		System.out.print("[ ");
		for (int num : numeri)
			System.out.print(num + " ");
		System.out.println("]");

		for (int i = 0; i < numeri.length; i++)
			if (numeri[i] == 0) {
				for (int j = i; j < numeri.length -1; j++) {
					numeri[j] = numeri[j + 1];
				}
				numeri[numeri.length - 1] = 0;
			}
		
		System.out.println("Array finale: ");
		System.out.print("[ ");
		for(int num: numeri)
			System.out.print(num + " ");
		System.out.println("]");
	}
}
