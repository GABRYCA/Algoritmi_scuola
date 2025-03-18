package Esercizio3.Basic;

public class MazeSolver extends Thread {
	
	int row;
	int col;
	Labyrinth lab;
	
	public MazeSolver(Labyrinth l, int r, int c) {
		this.row = r;
		this.col = c;
		System.out.println("Risolutore " + this.getName() + " creato con coordinate (" + col + ", " + row + ")");
		this.lab = l;
	}
	public void run() {
		System.out.println("Risolutore " + this.getName() + " avviato con coordinate (" + col + ", " + row + ")");
		if (!lab.isVisited(row, col)) {
			
			lab.visit(row, col);
			
			if (!lab.isDone()) {
				
				if (lab.toNorth(row, col)) {
					System.out.println("Risolutore " + this.getName() + " da (" + col + ", " + row + ") si sta muovendo verso nord a (" + col + ", " + (row - 1) + ")");
					new MazeSolver(lab, row-1, col).start();
				}
				
				if (lab.toSouth(row, col)) {
					System.out.println("Risolutore " + this.getName() + " da (" + col + ", " + row + ") si sta muovendo verso sud a (" + col + ", " + (row + 1) + ")");
					new MazeSolver(lab, row+1, col).start();
				}
				
				if (lab.toWest(row,col)) {
					System.out.println("Risolutore " + this.getName() + " da (" + col + ", " + row + ") si sta muovendo verso ovest a (" + (col - 1) + ", " + row + ")");
					new MazeSolver(lab, row, col-1).start();
				}
				
				if (lab.toEast(row,col)) {
					System.out.println("Risolutore " + this.getName() + " da (" + col + ", " + row + ") si sta muovendo verso est a (" + (col + 1) + ", " + row + ")");
					new MazeSolver(lab, row, col+1).start();
				}			
			}
		}
	}
}
