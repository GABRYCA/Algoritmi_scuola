package Esercizio2;

import java.util.concurrent.Semaphore;

public class Coda {
	
	static int dimBuffer;
	private int nElementi = 0;
	private int[] elementi;
	private int primo, ultimo;
	Semaphore mutex, full, empty;
	
	Coda(int size) {
		dimBuffer = size;
		mutex = new Semaphore(1);
		full = new Semaphore(0);
		empty = new Semaphore(dimBuffer);
		primo = 0;
		ultimo = 0;
		elementi = new int[dimBuffer];
	}
	
	void printNome(String s, int v) {
		System.out.println(Thread.currentThread().getName() + " " + s + " " + v + " [" + nElementi + "]");
	}

	public int getElemento() {
		int tmp;
		try {
			full.acquire();
		} catch (InterruptedException e) {}
		
		try {
			mutex.acquire();
		} catch (InterruptedException e) {}
		
		nElementi--;
		tmp = elementi[primo];
		primo = (primo + 1) % dimBuffer;
		printNome(" letto ", tmp);
		mutex.release();
		empty.release();
		return tmp;
	}
	
	public void setElemento(int v) {
		try {
			empty.acquire();
		} catch (InterruptedException e) {}
		try {
			mutex.acquire();
		} catch (InterruptedException e) {}
		nElementi++;
		elementi[ultimo] = v;
		ultimo = (ultimo + 1) % dimBuffer;
		printNome(" Scritto ", v);
		mutex.release();
		full.release();
	}
	
	public int getNElementi() {
		return nElementi;
	}
}
