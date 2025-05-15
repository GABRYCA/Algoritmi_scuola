package Esercizio1.Dato;

public class Client {
	public static void main(String[] args) {
		MCDimpl euclMCD = new MCDimpl();
		int x, y;
		x = 18;
		y = 3;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
		x = 18;
		y = 6;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
		x = 18;
		y = 7;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
		x = 18765;
		y = 345435;
		System.out.println("MCD(" + x + "," + y + ")=" + euclMCD.mcd(x, y));
	}
}
