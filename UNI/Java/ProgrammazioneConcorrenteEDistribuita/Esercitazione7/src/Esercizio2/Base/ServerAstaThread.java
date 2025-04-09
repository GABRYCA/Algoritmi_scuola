package Esercizio2.Base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.StringTokenizer;

public class ServerAstaThread extends Thread {
	private Asta lAsta;
	private Socket cliSocket;
	private BufferedReader in;
	private PrintWriter out;

	public ServerAstaThread(Asta a, Socket s) throws IOException {
		this.lAsta = a;
		this.cliSocket = s;
		this.in = new BufferedReader(new InputStreamReader(cliSocket.getInputStream()));
		this.out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(cliSocket.getOutputStream())), true);
		start();
	}

	public void run() {
		int off;
		String aggiudicatarioCorrente;
		while (true) {
			String str;
			try {
				str = in.readLine();
			} catch (IOException e) {
				str = "END";
			}
			System.out.println("Server received " + str);
			if (str.equals("END"))
				break;
			if (str.equals("read")) {
				off = lAsta.leggi_offerta();
				str = String.valueOf(off);
				out.println(str);
				aggiudicatarioCorrente = lAsta.leggi_titolare();
				out.println(aggiudicatarioCorrente);
			}
			if (str.startsWith("offer")) {
				StringTokenizer st = new StringTokenizer(str);
				String op = st.nextToken();
				String newOff = st.nextToken();
				String clientName = st.nextToken();
				off = Integer.parseInt(newOff);
				if (lAsta.fai_offerta(off, clientName)) {
					out.println("OK");
				} else {
					out.println("KO");
				}
			}
		}
		try {
			cliSocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
