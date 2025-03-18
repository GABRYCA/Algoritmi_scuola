package Esercizio1.Sequenziale;

public class Sequenziale {
	
	int matrix[][] = {
			{1,2,3,4,5},
			{2,2,2,2,2},
			{3,3,3,3,3},
			{4,4,4,4,3},
			{5,5,5,5,5}
	};
	int rows = matrix.length;
	int cols = matrix[0].length;
	int results[];
	
	public void stampa() {
		for (int i = 0; i < rows; i++) {
			System.out.print("[");
			for (int j = 0; j < matrix[i].length; j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println("]");
		}
	}
	
	private int sommaRiga(int[] in) {
		int somma = 0;
		for (int i = 0; i < in.length; i++) {
			somma += in[i];
		}
		return somma;
	}
	
	public Sequenziale() {
		results = new int[rows];
		stampa();
		for (int i = 0; i < rows; i++) results[i] = sommaRiga(matrix[i]);
		stampa();
	}

}