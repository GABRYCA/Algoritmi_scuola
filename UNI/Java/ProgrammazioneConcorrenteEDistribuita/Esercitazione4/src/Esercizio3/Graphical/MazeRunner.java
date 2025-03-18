package Esercizio3.Graphical;

public class MazeRunner extends Thread {

	private static Labyrinth labyrinth;

	private int x;
	private int y;

	public MazeRunner(int x, int y) {

		this.x = x;
		this.y = y;
	}

	public static void setLabyrinth(Labyrinth lab) {
		labyrinth = lab;
	}

	public void run() {

		if (x == 0 || y == 0 || x == labyrinth.getSize() + 1 || y == labyrinth.getSize() + 1) return;

		if (labyrinth.isVisited(x, y)) return;

		labyrinth.visit(x, y);
		StdDraw.setPenColor(StdDraw.BLUE);
		StdDraw.filledCircle(x + 0.5, y + 0.5, 0.25);
		StdDraw.show();
		StdDraw.pause(30);

		if (labyrinth.isDone()) return;

		if (labyrinth.toNorth(x, y)) new MazeRunner(x, y + 1).start();
		
		if (labyrinth.toEast(x, y)) new MazeRunner(x + 1, y).start();
		
		if (labyrinth.toSouth(x, y)) new MazeRunner(x, y - 1).start();
		
		if (labyrinth.toWest(x, y)) new MazeRunner(x - 1, y).start();
	}
}
