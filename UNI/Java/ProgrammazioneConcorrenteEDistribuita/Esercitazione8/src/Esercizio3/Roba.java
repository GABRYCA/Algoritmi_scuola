package Esercizio3;

import java.io.Serializable;

public class Roba implements Serializable {
	private static final long serialVersionUID = 1L;
	int ID;
	String type;
	String descr;

	Roba(int id, String t, String d) {
		ID = id;
		type = t;
		descr = d;
	}

	public String toString() {
		return "Roba_" + ID + " di tipo " + type + " : " + descr;
	}
}
