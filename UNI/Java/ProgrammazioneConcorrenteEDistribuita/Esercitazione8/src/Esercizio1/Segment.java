package Esercizio1;

class PointCreationFailed extends Exception {
	private static final long serialVersionUID = 1L;

	public PointCreationFailed() {
	}

	public PointCreationFailed(String message) {
		super(message);
	}
}

public class Segment {
	private Point p1 = null;
	private Point p2 = null;

	public Segment(Point p1, Point p2) throws PointCreationFailed {
		if (!p1.isEqual(p2)) {
			this.p1 = p1;
			this.p2 = p2;
		} else {
			throw new PointCreationFailed("cannot build segment");
		}
	}

	public Point midPoint() {
		double mx, my;
		mx = (p1.getX() + p2.getX()) / 2;
		my = (p1.getY() + p2.getY()) / 2;
		return (new Point(mx, my));
	}

	public Point symmetric(Point p) {
		Point m = this.midPoint();
		double simmX = 2 * m.getX() - p.getX();
		double simmY = 2 * m.getY() - p.getY();
		return new Point(simmX, simmY);
	}
}