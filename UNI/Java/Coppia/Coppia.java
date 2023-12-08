package varie;

public class Coppia<E, F> {
	
	private E sinistro;
	private F destro;
	private static int nCoppie = 0;
	
	public Coppia(E e, F f) {
		sinistro = e;
		destro = f;
		nCoppie++;
	}
	
	public E getSinistro() { return sinistro; }
	public F getDestro() { return destro; }
	
	public static int numeroCoppie() { return nCoppie; }
	
	public String toString() {
		return "(" + sinistro + ", " + destro + ")";
	}
}
