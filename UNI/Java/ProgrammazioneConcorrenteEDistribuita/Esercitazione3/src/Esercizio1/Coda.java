package Esercizio1;

public class Coda {
	
	static int dimBuffer;
	private int nElementi = 0;
	private int[] elementi;
	private int primo, ultimo;
	
	Coda(int size) {
		dimBuffer = size;
		primo = 0;
		ultimo = 0;
		elementi = new int[dimBuffer];
	}
	
	void printNome(String s, int v) {
		System.out.println(Thread.currentThread().getName() + " " + s + " " + v + " [" + nElementi + "]");
	}

	synchronized public int getElemento() {
		int tmp;
		while (nElementi == 0) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		
		nElementi--;
		tmp = elementi[primo];
		primo = (primo + 1) % dimBuffer;
		printNome(" letto ", tmp);
		return tmp;
	}
	
	synchronized public void setElemento(int v) {
		while (nElementi == dimBuffer) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		
		nElementi++;
		elementi[ultimo] = v;
		ultimo = (ultimo + 1) % dimBuffer;
		printNome(" Scritto ", v);
		notifyAll();
	}
	
	public int getNElementi() {
		return nElementi;
	}
}
