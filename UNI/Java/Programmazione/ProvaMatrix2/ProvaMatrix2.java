import java.util.Random;

public class ProvaMatrix2 {
	
	public static void main(String[] args) {
		
		Random ran = new Random();
		
		int[][] matrix = generaMatrix(ran.nextInt(5)+1, ran.nextInt(5)+1);
		/*String matrixToPrint = stampaMatrix(matrix);
		System.out.println(matrixToPrint);*/
		System.out.println("Matrice 1\n"+stampaMatrix(matrix));
		
		//estrarre gli elementi sull'anti-diagonale
		int[] antidiagonale = antiDiagonale(matrix);
		if(antidiagonale != null){
			System.out.print("La matrice e' quadrata :-) Antidiagonale > ");
			for(int i=0; i < antidiagonale.length; i++)
				System.out.print(antidiagonale[i]+" ");
		}
		else System.out.println("La matrice non e' quadrata :-(");
		
		//creare una seconda matrice e sommarla alla prima, se possibile
		int[][] matrix2 = generaMatrix(matrix.length, matrix[0].length); //la seconda matrice ha la stessa dimensione della prima
		System.out.println("Matrice 2\n"+stampaMatrix(matrix2));
		
		int[][] somma = sommaMatrici(matrix, matrix2);
		if(somma != null) 
			System.out.print("Matrice somma :-)\n"+stampaMatrix(somma));
		else 
			System.out.println("Le matrici non hanno la stessa dimensione, quindi non possono essere sommate :-(");
	
		//matrice trasposta TODO
	}
	
	//generare una matrice
	private static int[][] generaMatrix(int righe, int colonne){
		Random ran = new Random();
		int[][] m = new int[righe][colonne];
		
		for(int i=0; i < righe; i++)
			for(int j=0; j < colonne; j++)
				m[i][j] = ran.nextInt(10);
		return m;
	}
	
	//stampare una matrice
	private static String stampaMatrix(int[][] m){
		String ris = "";
		for(int i=0; i < m.length; i++) {
			for(int j=0; j < m[i].length; j++)
				ris += m[i][j]+" ";
			ris += "\n";
		}
		return ris;
	}
	
	//estrarre gli elementi sull'anti-diagonale
	private static int[] antiDiagonale(int[][] m){
		int[] antiDiagonale = null;
		if(m.length == m[0].length) {
			antiDiagonale = new int[m.length];
			for(int i=0; i < m.length; i++)
				antiDiagonale[i] = m[i][m[0].length-1-i];
		}
		return antiDiagonale;
	}
	
	//somma di due matrici
	private static int[][] sommaMatrici(int[][] m1, int[][] m2){
		int[][] somma = null;
		if(m1.length == m2.length && m1[0].length == m2[0].length) { //verifica che le due matrici abbiano la stessa dimensione
			somma = new int[m1.length][m1[0].length];
			for(int i=0; i < m1.length; i++)
				for(int j=0; j < m1[i].length; j++)
					somma[i][j] = m1[i][j] + m2[i][j];
		}
		return somma;
	}
	
	//trasposta di una matrice TODO
}