package soluzione1;

class Messaggio {
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
