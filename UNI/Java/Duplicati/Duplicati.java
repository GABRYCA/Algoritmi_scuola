import java.util.Random;

public class Duplicati {
	
	public static void main(String[] args) {
		
		Random ran = new Random();
		
		int[][] matrix = generaMatrix(ran.nextInt(5)+1, ran.nextInt(5)+1);
		System.out.println("Matrice \n"+stampaMatrix(matrix));
		
		System.out.println(verificaDuplicati(matrix, ran.nextInt(10)));
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
	
	private static int verificaDuplicati(int[][] m, int valore) {
		System.out.print("Numero di duplicati del valore " + valore + " > ");
		int contatore = 0;
		for(int i=0; i < m.length; i++) {
			for(int j=0; j < m[i].length; j++) {
				if(m[i][j] == valore)
					contatore++;
			}
		}
		return contatore;
	}
}