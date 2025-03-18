package Esercizio3.Graphical;

public class Graphical {

	public Graphical() {
		int n = 20;
		Labyrinth lab = new Labyrinth(n);
		StdDraw.enableDoubleBuffering();

		lab.draw();
		lab.clear();

		MazeRunner.setLabyrinth(lab);

		new MazeRunner(1, 1).start();
	}
}
