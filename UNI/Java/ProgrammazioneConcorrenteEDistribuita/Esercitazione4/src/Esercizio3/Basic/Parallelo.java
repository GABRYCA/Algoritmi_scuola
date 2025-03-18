package Esercizio3.Basic;

public class Parallelo {
	public Parallelo() {
		Labyrinth lab = new Labyrinth();
		lab.clear();
		new MazeSolver(lab, 0, 0).start();
	}
}
