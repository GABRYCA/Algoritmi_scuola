package soluzione2;

import java.io.Serializable;

//Semplice classe POJO (Plain Old Java Object) per rappresentare un prodotto.
public class Prodotto implements Serializable {
	private static final long serialVersionUID = 1L;
	private final int id;

	public Prodotto(int id) {
		this.id = id;
	}

	public int getId() {
		return id;
	}

	@Override
	public String toString() {
		return "Prodotto[ID=" + id + "]";
	}
}