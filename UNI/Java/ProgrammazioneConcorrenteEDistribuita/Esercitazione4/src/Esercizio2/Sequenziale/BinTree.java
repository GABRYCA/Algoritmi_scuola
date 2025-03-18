package Esercizio2.Sequenziale;

public class BinTree {
	private int value;
	private BinTree left = null;
	private BinTree right = null;
	
	public BinTree(int v, BinTree l, BinTree r) {
		this.value = v;
		this.left = l;
		this.right = r;
	}
	
	public BinTree getLeft() {
		return this.left;
	}
	
	public BinTree getRight() {
		return this.right;
	}
	
	public int getValue() {
		return this.value;
	}
	
	public void addLeft(BinTree bt) {
		this.left = bt;
	}
	
	public void addRight(BinTree bt) {
		this.right = bt;
	}
	
	public void stampaBT() {
		if (this != null) {
			if (this.getLeft() != null) {
				System.out.print("[");
				this.getLeft().stampaBT();
				System.out.print("]");
			}
			System.out.print(" " + this.getValue() + " ");
			if (this.getRight() != null) {
				System.out.print("[");
				this.getRight().stampaBT();
				System.out.print("]");
			}
		}
	}
	
	public int getSize() {
		int s = 1;
		if (this.getLeft() != null) s += this.getLeft().getSize();
		if (this.getRight() != null) s += this.getRight().getSize();
		return s;
	}
	
	public BinTree ricercaSequenziale(int v) {
		BinTree r = null;
		
		if (this.getValue() == v) return this;
		
		if (this.getLeft() != null) {
			r = this.getLeft().ricercaSequenziale(v);
			if (r != null) return r;
		}
		
		return (BinTree) null;
	}
}
