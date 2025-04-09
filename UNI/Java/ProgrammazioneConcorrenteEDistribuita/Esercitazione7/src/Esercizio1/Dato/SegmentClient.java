package Esercizio1.Dato;

public class SegmentClient {
	public static void main(String[] args) {
		Point p1 = new Point(0.0, 0.0);
		Point p2 = new Point(4.0, 4.0);
		Point px = new Point(0.0, 4.0);
		Segment sgm = new Segment();
		sgm.set(p1, p2);
		Point simm = sgm.simmetric(px);
		System.out.println("Il punto simmetrico e` (" + simm.getX() + "," + simm.getY() + ")");
	}
}
