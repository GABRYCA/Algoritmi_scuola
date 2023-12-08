package esempiopackagelibreria;

import java.util.Date;
import java.text.SimpleDateFormat;

public class Rivista extends Libro {

	private SottoGenere tipologia;
	private Date dataPubblicazione;

	enum SottoGenere {
		QUOTIDIANO, MENSILE, SETTIMANALE
	}

	public Rivista(String titolo, String autore, int numeroPagine, Genere[] generi, boolean disponibile,
			SottoGenere tipologia, Date dataPubblicazione) {
		super(titolo, autore, numeroPagine, generi, disponibile);
		this.tipologia = tipologia;
		this.dataPubblicazione = dataPubblicazione;
	}

	public Rivista(String titolo) {
		super(titolo);
		tipologia = null;
		dataPubblicazione = new Date();
	}

	public SottoGenere getTipologia() {
		return tipologia;
	}

	public void setTipologia(SottoGenere tipologia) {
		this.tipologia = tipologia;
	}

	public Date getDataPubblicazione() {
		return dataPubblicazione;
	}

	public void setDataPubblicazione(Date dataPubblicazione) {
		this.dataPubblicazione = dataPubblicazione;
	}

	@Override
	public String toString() {
		String dataPattern = "DD-MM-YYYY";
		SimpleDateFormat dateFormat = new SimpleDateFormat(dataPattern);
		return "Rivista \"" + super.getTitolo() + "\", autore " + super.getAutore() + ", data di pubblicazione "
				+ dateFormat.format(dataPubblicazione) + ", tipologia " + tipologia
				+ (super.isDisponibile() ? "si" : "no") + " numero pagine: " + super.getNumeroPagine();
	}
}
