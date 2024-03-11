package esercizivari;

import java.util.Random;
import java.util.Scanner;

public class MatriceZero {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numRighe = 0;
		int numColonne = 0;
		do {
			System.out.println("Inserisci numero di righe [5, 10]");
			numRighe = in.nextInt();
			if (numRighe < 5 || numRighe > 10)
				System.out.println("Valore errato");
			else
				break;
		} while (true);

		in.nextLine();

		do {
			System.out.println("Inserisci numero di colonne [5, 10]");
			numColonne = in.nextInt();
			if (numColonne < 5 || numColonne > 10)
				System.out.println("Valore errato");
			else
				break;
		} while (true);

		int[][] matrice = new int[numRighe][numColonne];

		Random random = new Random();
		int max = 10;

		for (int r = 0; r < matrice.length; r++)
			for (int c = 0; c < matrice[r].length; c++)
				matrice[r][c] = (int) random.nextInt(max);

		System.out.println("Matrice iniziale: ");
		for (int r = 0; r < matrice.length; r++) {
			for (int c = 0; c < matrice[r].length; c++)
				System.out.print(matrice[r][c] + " ");
			System.out.println();
		}

		int[][] matriceZero = new int[numRighe][numColonne];
		for (int r = 0; r < matrice.length; r++) 
			for (int c = 0; c < matrice[r].length; c++)
				matriceZero[r][c] = matrice[r][c];
		
		
		for (int r = 0; r < matrice.length; r++) {
			for (int c = 0; c < matrice[r].length; c++) {
				if(matrice[r][c] == 0)
					cambiaValori(r, c, matriceZero);
			}
		}
		
		System.out.println("Matrice finale: ");
		for (int r = 0; r < matrice.length; r++) {
			for (int c = 0; c < matrice[r].length; c++)
				System.out.print(matriceZero[r][c] + " ");
			System.out.println();
		}
	}
	
	private static void cambiaValori(int riga, int colonna, int[][] matriceZero) {
		for(int c=0; c<matriceZero[riga].length; c++)
			matriceZero[riga][c] = 0;
		for(int r = 0; r < matriceZero.length; r++)
			matriceZero[r][colonna] = 0;
	}
}
