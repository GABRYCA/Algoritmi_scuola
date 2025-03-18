package Esercizio1.Concorrente;

public class MatConcorrente {
	
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
	
	public MatConcorrente() {
		results = new int[rows];
		Result res = new Result(results, rows);
		stampa();
		for (int i = 0; i < rows; i++) {
			new Summer(matrix[i], i, res).start();
		}
		
		while (!res.isCompleted()) {
			System.out.println("Main in attesa...");
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {}
		}
		stampa();
	}

}
