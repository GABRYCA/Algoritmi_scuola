package Esercizio2;

import java.io.IOException;
import java.net.InetAddress;

public class ClientAsta {
	public static void main(String[] args) throws IOException, InterruptedException {
		final int numClients = 3;
		InetAddress addr = InetAddress.getByName(null);
		for (int i = 0; i < numClients; i++) {
			String cliName = "cli" + i;
			new ClienteAstaThread(addr, ServerAsta.PORT, cliName);
		}
	}
}
