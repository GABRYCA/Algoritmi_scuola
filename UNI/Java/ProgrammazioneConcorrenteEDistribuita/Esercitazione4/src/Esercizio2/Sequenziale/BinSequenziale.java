package Esercizio2.Sequenziale;

public class BinSequenziale {
	
	public void ricerca(int v, BinTree bt) {
		BinTree r = bt.ricercaSequenziale(v);
		if (r == null ) {
			System.out.println("Valore " + v + " non trovato!");
		} else {
			System.out.println("Trovato " + v);
		}
	}
	
	public BinSequenziale() {
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
		ricerca(13, root);
		ricerca(6, root);
		ricerca(8, root);
		ricerca(7, root);
		ricerca(3, root);
	}
}
