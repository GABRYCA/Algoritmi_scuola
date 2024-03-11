import java.util.Random;

public class ProvaMatrixString {

	public static void main(String[] args) {
		
		Random ran = new Random();
		
		String[][] matrix = new String[Integer.parseInt(args[0])][Integer.parseInt(args[1])];
	
		for(int i=0; i < matrix.length; i++)
			for(int j=0; j < matrix[i].length; j++)
				matrix[i][j] = i+"java"+j;
			
		for(int i=0; i < matrix.length; i++) {
			for(int j=0; j < matrix[i].length; j++)
				System.out.print(matrix[i][j]+" ");
			System.out.println();
		}
		
		//concatenare le stringhe appartenente alla riga in poszione index
		int index = ran.nextInt(matrix.length);
		String concatenazione = "";
		for(int i=0; i < matrix[index].length; i++)
			concatenazione += matrix[index][i] + " ";
		System.out.println("Concatenazione riga "+index+" > "+concatenazione);
	}
}