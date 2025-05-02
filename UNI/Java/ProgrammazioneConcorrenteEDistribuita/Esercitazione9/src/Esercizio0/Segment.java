package Esercizio0;

public class Segment implements SegmentInterface {
	private Point p1 = null;
	private Point p2 = null;

	public Segment() {
	}

	public boolean set(Point p1, Point p2) {
		if (!p1.isEqual(p2)) {
			this.p1 = p1;
			this.p2 = p2;
			return true;
		} else {
			return false;
		}
	}

	private Point midPoint() {
		double mx, my;
		mx = (p1.getX() + p2.getX()) / 2;
		my = (p1.getY() + p2.getY()) / 2;
		return (new Point(mx, my));
	}

	public Point simmetric(Point p) {
		Point m = this.midPoint();
		double simmX = 2 * m.getX() - p.getX();
		double simmY = 2 * m.getY() - p.getY();
		return new Point(simmX, simmY);
	}
}