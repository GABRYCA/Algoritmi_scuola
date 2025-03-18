package Esercizio3.Basic;

public class Labyrinth {
	private int rows;
	private int cols;

	private static boolean north[][] =
		{
		{ false, false, false, false, false, false, false, false, false, false},
		{ true, false, true, true, false, true, true, false, false, true },
		{ true, false, false, false, true, false, true, true, true, false },
		{ false, true, true, false, true, true, false, false, true, true},
		{ true, false, false, true, true, false, false, true, false, false}
		};
	
	private static boolean[][] east =
		{
		{ true, true, false, true, true, true, true, true, true, false},
		{ false, true, false, true, false, true, false, false, true, false},
		{ true, false, true, false, true, false, true, false, false, false},
		{ true, true, false, true, false, true, false, true, true, false},
		{ true, true, true, false, true, false, true, true, true, false}
		};
	
	private static boolean[][] south =
		{
		{ true, false, true, true, false, true, true, false, false, true},
		{ true, false, false, false, true, false, true, true, true, false},
		{ false, true, true, false, true, true, false, false, true, true},
		{ true, false, false, true, true, false, false, true, false, false},
		{ false, false, false, false, false, false, false, false, false, false}
		};
	
	private static boolean[][] west =
		{
		{ false, true, true, false, true, true, true, true, true, true},
		{ false, false, true, false, true, false, true, false, false, true},
		{ false, true, false, true, false, true, false, true, false, false},
		{ false, true, true, false, true, false, true, false, true, true},
		{ false, true, true, true, false, true, false, true, true, true}
		};

	private static boolean[][] visited={
		{ false, false, false, false, false, false, false, false, false, false},
		{ false, false, false, false, false, false, false, false, false, false},
		{ false, false, false, false, false, false, false, false, false, false},
		{ false, false, false, false, false, false, false, false, false, false},
		{ false, false, false, false, false, false, false, false, false, false}
	};
	
	private boolean done = false;
	
	public void clear(){
		System.out.println("Ripulendo il labirinto da " + rows + " righe e " + cols + " colonne");
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				visited[i][j] = false;
			}
		}
	}
	public Labyrinth() {
		this.rows = north.length;
		this.cols = north[0].length;
		System.out.println("Il labirinto ha " + rows + " righe e " + cols + " colonne");
	}
	
	public int getNumColumns(){
		return cols;
	}
	
	public int getNumRows(){
		return rows;
	}
	
	public boolean isVisited(int r, int c){
		return visited[r][c];
	}
	public synchronized void visit(int r, int c){
		visited[r][c] = true;
		if(c == cols - 1 && r == rows - 1){
			System.out.println("Visitando uscita");
			done = true;
		}
	}
	public  boolean isDone(){
		return done;
	}
	public  boolean toNorth(int r, int c){
		return north[r][c];
	}
	public  boolean toEast(int r, int c){
		return east[r][c];
	}
	public  boolean toWest(int r, int c){
		return west[r][c];
	}
	public  boolean toSouth(int r, int c){
		return south[r][c];
	}
}