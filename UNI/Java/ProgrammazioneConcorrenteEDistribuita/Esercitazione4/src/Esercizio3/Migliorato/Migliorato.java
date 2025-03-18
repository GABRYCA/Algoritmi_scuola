package Esercizio3.Migliorato;

public class Migliorato {
	
	public Migliorato() {
		Labyrinth lab = new Labyrinth();
    	lab.clear();
        new MazeSolver(lab, 0, 0).start();
	}
}
