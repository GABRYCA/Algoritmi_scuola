import java.util.Random;

public class ProvaMatrix {

	public static void main(String[] args) {
		
		Random ran = new Random();
		
		int[][] matrix = new int[5][5];
		
		for(int i=0; i < matrix.length; i++)
			for(int j=0; j < matrix[i].length; j++)
				matrix[i][j] = ran.nextInt(10);
			
		for(int i=0; i < matrix.length; i++) {
			for(int j=0; j < matrix[i].length; j++)
				System.out.print(matrix[i][j]+" ");
			System.out.println();
		}
		
		//estrarre gli elementi sulla diagonale
		if(matrix.length == matrix[0].length) { //errore in esecuzione se righe=0
			System.out.println("La matrice e' quadrata :-)");
			int[] diagonale = new int[matrix.length];
			for(int i=0; i < matrix.length; i++)
				diagonale[i] = matrix[i][i];
			for(int i=0; i < matrix.length; i++)
				System.out.print(diagonale[i]+" ");
		} else System.out.println("La matrice non e' quadrata :-(");
		
		//estrarre gli elementi sull'anti-diagonale
	}
}