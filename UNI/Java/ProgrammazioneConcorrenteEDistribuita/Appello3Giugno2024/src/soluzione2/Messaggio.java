package soluzione2;

import java.io.Serializable;

class Messaggio implements Serializable {
	private static final long serialVersionUID = 1L;
	private String mittente;
	private String destinatario;
	private String contenuto;

	Messaggio(String m, String d, String c) {
		this.mittente = m;
		this.destinatario = d;
		this.contenuto = c;
	}

	public String getMittente() {
		return mittente;
	}

	public String getDestinatario() {
		return destinatario;
	}

	public String toString() {
		return "messaggio da " + mittente + " a " + destinatario + "  : " + contenuto;
	}
}
