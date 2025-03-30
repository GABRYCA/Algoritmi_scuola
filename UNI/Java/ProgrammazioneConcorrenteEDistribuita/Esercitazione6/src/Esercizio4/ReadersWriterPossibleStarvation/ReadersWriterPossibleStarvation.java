package Esercizio4.ReadersWriterPossibleStarvation;

public class ReadersWriterPossibleStarvation {

	public ReadersWriterPossibleStarvation() {
		Data d = new Data();
		new Writer("Writer", d).start();
		for (int i = 0; i < 3; i++) {
			new Reader("Reader_" + i, d).start();
		}
	}

}
