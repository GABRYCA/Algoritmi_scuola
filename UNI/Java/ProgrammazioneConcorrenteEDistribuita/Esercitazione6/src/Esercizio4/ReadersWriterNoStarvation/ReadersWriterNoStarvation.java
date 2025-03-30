package Esercizio4.ReadersWriterNoStarvation;

public class ReadersWriterNoStarvation {

	public ReadersWriterNoStarvation() {
		Data d = new Data();
		new Writer("Writer", d).start();
		for (int i = 0; i < 3; i++) {
			new Reader("Reader_" + i, d).start();
		}
	}
}
