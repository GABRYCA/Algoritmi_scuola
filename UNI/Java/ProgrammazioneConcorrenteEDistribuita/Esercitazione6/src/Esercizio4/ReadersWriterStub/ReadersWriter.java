package Esercizio4.ReadersWriterStub;

public class ReadersWriter {

	public ReadersWriter() {
		Data d = new Data();
		new Writer("Writer", d).start();
		for(int i=0; i<3; i++) {
			new Reader("Reader_"+i, d).start();
		}
	}
}
