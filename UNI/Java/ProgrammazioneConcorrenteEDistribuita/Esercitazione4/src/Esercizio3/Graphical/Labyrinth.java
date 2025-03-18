package Esercizio3.Graphical;

public class Labyrinth {

	private int size;

	private boolean[][] north;
	private boolean[][] east;
	private boolean[][] south;
	private boolean[][] west;
	private boolean[][] visited;

	private boolean done = false;

	public Labyrinth(int n) {

		this.size = n;

		StdDraw.setXscale(0, n + 2);
		StdDraw.setYscale(0, n + 2);

		init();
		generate(1, 1);
	}

	private void init() {

		visited = new boolean[size + 2][size + 2];
		for (int x = 0; x < size + 2; x++) {
			visited[x][0] = true;
			visited[x][size + 1] = true;
		}
		for (int y = 0; y < size + 2; y++) {
			visited[0][y] = true;
			visited[size + 1][y] = true;
		}

		north = new boolean[size + 2][size + 2];
		east = new boolean[size + 2][size + 2];
		south = new boolean[size + 2][size + 2];
		west = new boolean[size + 2][size + 2];
		for (int x = 0; x < size + 2; x++) {
			for (int y = 0; y < size + 2; y++) {
				north[x][y] = true;
				east[x][y] = true;
				south[x][y] = true;
				west[x][y] = true;
			}
		}
	}

	private void generate(int x, int y) {
		visited[x][y] = true;

		while (!visited[x][y + 1] || !visited[x + 1][y] || !visited[x][y - 1] || !visited[x - 1][y]) {

			while (true) {

				// Con questa definizione toglie al massimo un muro per stanza,
				// Fino a che non ho visitato i 4 vicini

				double r = StdRandom.uniform(4);
				if (r == 0 && !visited[x][y + 1]) {
					north[x][y] = false;
					south[x][y + 1] = false;
					generate(x, y + 1);
					break;
				} else if (r == 1 && !visited[x + 1][y]) {
					east[x][y] = false;
					west[x + 1][y] = false;
					generate(x + 1, y);
					break;
				} else if (r == 2 && !visited[x][y - 1]) {
					south[x][y] = false;
					north[x][y - 1] = false;
					generate(x, y - 1);
					break;
				} else if (r == 3 && !visited[x - 1][y]) {
					west[x][y] = false;
					east[x - 1][y] = false;
					generate(x - 1, y);
					break;
				}
			}
		}
	}

	public boolean isDone() {
		return done;
	}

	public boolean toNorth(int i, int j) {
		return !north[i][j];
	}

	public boolean toEast(int i, int j) {
		return !east[i][j];
	}

	public boolean toSouth(int i, int j) {
		return !south[i][j];
	}

	public boolean toWest(int i, int j) {
		return !west[i][j];
	}

	public boolean isVisited(int i, int j) {
		return visited[i][j];
	}

	public void visit(int i, int j) {
		visited[i][j] = true;

		if (i == size && j == size)
			done = true;
	}

	public int getSize() {
		return size;
	}

	// draw the maze
	public void draw() {
		StdDraw.setPenColor(StdDraw.RED);
		StdDraw.filledCircle(size + 0.5, size + 0.5, 0.375); // L'uscita
		StdDraw.filledCircle(1.5, 1.5, 0.375); // L'ingresso

		StdDraw.setPenColor(StdDraw.BLACK);
		for (int x = 1; x <= size; x++) {
			for (int y = 1; y <= size; y++) {
				if (south[x][y])
					StdDraw.line(x, y, x + 1, y);
				if (north[x][y])
					StdDraw.line(x, y + 1, x + 1, y + 1);
				if (west[x][y])
					StdDraw.line(x, y, x, y + 1);
				if (east[x][y])
					StdDraw.line(x + 1, y, x + 1, y + 1);
			}
		}
		StdDraw.show();
		StdDraw.pause(1000);
	}

	public void clear() {
		for (int x = 1; x <= size; x++)
			for (int y = 1; y <= size; y++)
				visited[x][y] = false;
		done = false;
	}

	private void solve(int x, int y) {
		if (x == 0 || y == 0 || x == size + 1 || y == size + 1)
			return;
		if (done || visited[x][y])
			return;
		visited[x][y] = true;

		StdDraw.setPenColor(StdDraw.BLUE);
		StdDraw.filledCircle(x + 0.5, y + 0.5, 0.25);
		StdDraw.show();
		StdDraw.pause(30);

		// Uscita in alto a destra
		if (x == size && y == size) done = true;

		if (!north[x][y]) solve(x, y + 1);
		if (!east[x][y]) solve(x + 1, y);
		if (!south[x][y]) solve(x, y - 1);
		if (!west[x][y]) solve(x - 1, y);

		if (done)
			return;

		StdDraw.setPenColor(StdDraw.GRAY);
		StdDraw.filledCircle(x + 0.5, y + 0.5, 0.25);
		StdDraw.show();
		StdDraw.pause(30);
	}

	/* Versione multithread */
	private void solveMT(final int x, final int y) {

		if (x == 0 || y == 0 || x == size + 1 || y == size + 1)
			return;
		if (done || visited[x][y])
			return;
		visited[x][y] = true;

		StdDraw.setPenColor(StdDraw.BLUE);
		StdDraw.filledCircle(x + 0.5, y + 0.5, 0.25);
		StdDraw.show();
		StdDraw.pause(30);

		// Uscita in alto a destra
		if (x == size && y == size)
			done = true;

		Thread tn, te, ts, tw;
		tn = te = ts = tw = null;

		if (!north[x][y]) {
			tn = new Thread() {
				public void run() {
					solveMT(x, y + 1);
				}
			};
			tn.start();
		}
		
		if (!east[x][y]) {
			te = new Thread() {
				public void run() {
					solveMT(x + 1, y);
				}
			};
			te.start();
		}
		
		if (!south[x][y]) {
			ts = new Thread() {
				public void run() {
					solveMT(x, y - 1);
				}
			};
			ts.start();
		}
		
		if (!west[x][y]) {
			tw = new Thread() {
				public void run() {
					solveMT(x - 1, y);
				}
			};
			tw.start();
		}

		if (done) return;
	}

	// test client
	public static void main(String[] args) {
		int n = 50;
		Labyrinth lab = new Labyrinth(n);

		StdDraw.enableDoubleBuffering();

		lab.draw();
		lab.clear();

		lab.solveMT(1, 1); // Cella di partenza
	}
}