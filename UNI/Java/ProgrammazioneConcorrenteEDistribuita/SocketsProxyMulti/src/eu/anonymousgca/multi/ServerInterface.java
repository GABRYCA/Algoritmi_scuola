package eu.anonymousgca.multi;

import java.io.IOException;

public interface ServerInterface {

	static final int PORT = 8000;
	
	int reset() throws IOException;
	int increment() throws IOException;
}
