package Esercizio2.Concorrente;

public class BinConcorrente {
	
	public void ricercaSequenziale(int v, BinTree bt) {
		BinTree r = bt.ricercaSequenziale(v);
		if (r == null) {
			System.out.println("Valore " + v + " non trovato");
		} else {
			System.out.println("Trovato " + v);
		}
	}

	public void ricercaParallela(int v, BinTree bt) {
		Result res = new Result(bt.getSize());
		Thread ricercatore = new RicercaParallelaThread(bt, v, res);
		System.out.println("Avviando il thread: " + ricercatore.getName());
		ricercatore.start();
		while (!res.isCompleted()) {
			System.out.println("Attesa...");
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {}
		}
		if (res.isSuccess()) {
			System.out.println("Trovato: " + v);
		} else {
			System.out.println("Valore " + v + " non trovato!");
		}
	}
	
	public BinConcorrente() {
		BinTree root = null;
		BinTree bt1 = new BinTree(3, null, null);
		BinTree bt2 = new BinTree(11, bt1, null);
		bt1 = new BinTree(4, null, bt2);
		bt2 = new BinTree(8, null, bt1);
		root = bt2;
		bt1 = new BinTree(2, null, null);
		bt2 = new BinTree(12, bt1, null);
		bt1 = new BinTree(1, null, null);
		bt2 = new BinTree(7, bt1, bt2);
		bt1 = new BinTree(9, null, null);
		bt2 = new BinTree(5, bt1, bt2);
		root.addLeft(bt2);
		root.stampaBT(); 
		System.out.println();
		System.out.println("================================");
		ricercaParallela(13, root);
		System.out.println("================================");
		ricercaParallela(6, root);
		System.out.println("================================");
		ricercaParallela(12, root);
	}
	
}
