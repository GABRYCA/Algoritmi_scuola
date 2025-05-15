package Esercizio1.Dato;

public class MCDimpl implements MCD {
	public int mcd(int n, int m) {
		int r;
		while (m != 0) {
			r = n % m;
			n = m;
			m = r;
		}
		return n;
	}
}
