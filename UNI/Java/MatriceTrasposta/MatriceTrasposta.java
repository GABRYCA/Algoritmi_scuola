import java.util.Random;

public class MatriceTrasposta {
	
	public static void main(String[] args) {
		
		Random ran = new Random();
		
		int[][] matrix = generaMatrix(ran.nextInt(5)+1, ran.nextInt(5)+1);
		System.out.println("Matrice \n"+stampaMatrix(matrix));
		
		int[][] matrixTrasposta = traspostaMatrice(matrix);
		System.out.println("Matrice \n"+stampaMatrix(matrixTrasposta));
	}
	
	private static int[][] generaMatrix(int righe, int colonne) {
		Random ran = new Random();
		int[][] m = new int[righe][colonne];
		
		for(int i=0; i < righe; i++)
			for(int j=0; j < colonne; j++)
				m[i][j] = ran.nextInt(10);
		return m;
	}
	
	private static String stampaMatrix(int[][] m) {
		String ris = "";
		for(int i=0; i < m.length; i++) {
			for(int j=0; j < m[i].length; j++)
				ris += m[i][j]+" ";
			ris += "\n";
		}
		return ris;
	}
	
	private static int[][] traspostaMatrice(int[][] m) {
		int[][] mTrasposta = new int[m[0].length][m.length];
		for(int i=0; i<mTrasposta.length; i++) {
			for(int j=0; j<mTrasposta[i].length; j++)
				mTrasposta[i][j] = m[j][i];
		}
		return mTrasposta;
	}
}