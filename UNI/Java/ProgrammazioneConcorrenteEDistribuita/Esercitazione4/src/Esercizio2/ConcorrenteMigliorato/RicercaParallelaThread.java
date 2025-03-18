package Esercizio2.ConcorrenteMigliorato;

public class RicercaParallelaThread extends Thread {
	
	private BinTree bt;
	private int x;
	private Result result = null;
	
	public RicercaParallelaThread(BinTree bt, int x, Result r) {
		this.bt = bt;
		this.x = x;
		this.result = r;
	}
	
	private void search(BinTree bt, int v) {
		if (bt != null) {
			System.out.println(this.getName()+" ha iniziato a cercare " + x + " at [" + bt.getValue() + "]");
			result.incVisits();
			if (bt.getValue() == v) {
				result.setNode(bt);
				result.setSuccess();
				System.out.println(this.getName() + " ha trovato " + v + "!");
			} else {
				System.out.println(this.getName() + " ha visitato " + bt.getValue());
			}
			
			if (bt.getRight() != null) {
				if (bt.getLeft() != null) new RicercaParallelaThread(bt.getRight(), v, result).start();
				search(bt.getLeft(), v);
			} else {
				search(bt.getRight(), v);
			}
		}
	}
	
	public void run() {
		System.out.println(this.getName() + " in corso...");
		search(this.bt, x);
		System.out.println(this.getName() + " completato!");
	}

}
