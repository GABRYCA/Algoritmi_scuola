package Esercizio0;

import java.io.Serializable;

public class Point implements Serializable {
	private static final long serialVersionUID = 1;
	final double THRESHOLD = 0.0000001;
	private double x;
	private double y;

	public Point(double tx, double ty) {
		x = tx;
		y = ty;
	}

	public double getX() {
		return x;
	}

	public double getY() {
		return y;
	}

	public boolean isEqual(Point p) {
		return (Math.abs(x - p.getX()) < THRESHOLD) && (Math.abs(y - p.getY()) < THRESHOLD);

	}
}