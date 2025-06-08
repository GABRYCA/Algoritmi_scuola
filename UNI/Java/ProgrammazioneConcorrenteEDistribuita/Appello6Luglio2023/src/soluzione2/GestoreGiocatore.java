package soluzione2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class GestoreGiocatore implements Runnable {

	Socket s;
	TavoloGioco t;
	ObjectOutputStream out;
	ObjectInputStream in;

	public GestoreGiocatore(Socket s, TavoloGioco t) {
		this.s = s;
		this.t = t;
		try {
			this.out = new ObjectOutputStream(s.getOutputStream());
			this.in = new ObjectInputStream(s.getInputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		String comando;
		try {
			while ((comando = (String) in.readObject()) != null && comando != "<fine>") {
				switch (comando) {
				case "<aspettaturno>": {
					int giocatore = (int) in.readObject();
					t.aspettaTurno(giocatore);
					break;
				}
				case "<mossa>": {
					int giocatore = (int) in.readObject();
					String mossa = (String) in.readObject();
					t.mossa(giocatore, mossa);
					break;
				}
				default: {
					System.out.println("Comando sconosciuto!");
					break;
				}
				}
			}
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("Un giocatore ha finito di giocare.");
			return;
		}
	}

}
