package Esercizio1.ConcorrenteMigliorato;

public class Summer extends Thread {
	int in[];
	Result ref;
	int row;
	
	public Summer(int v[], int row, Result r) {
		this.row = row;
		this.ref = r;
		this.in = v;
	}
	
	public void run() {
		int sum = 0;
		for (int i = 0; i < in.length; i++) {
			sum += in[i];
		}
		ref.setNums(row, sum);
		System.out.println("Risultato riga " + row + ": " + sum);
	}
}
