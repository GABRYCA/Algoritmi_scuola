package Esercizio2;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ServerAstaThread extends Thread {
	private Asta lAsta;
	private Socket cliSocket;
	private ObjectInputStream obj_in_s;
	private ObjectOutputStream obj_out_s;
	private String myName=null;

	public ServerAstaThread(Asta a, Socket s, int id) throws IOException{
		this.lAsta=a;
		this.cliSocket=s;
		this.obj_out_s = new ObjectOutputStream(s.getOutputStream());
		this.obj_in_s = new ObjectInputStream(s.getInputStream());
		myName="slave_"+id;
		start();
	}
	public void run(){
		Offerta off=new Offerta(0, myName);
		while(true) {
			String str;
			try {
				str = (String) obj_in_s.readObject();
			} catch (IOException | ClassNotFoundException e) {
				str="END";
			}
			System.out.println(myName+" received "+str);
			if(str.equals("END")) break;
			if(str.equals("read")){
				try {
					Offerta off2=new Offerta();
					lAsta.leggi_copia_offerta(off2);
					obj_out_s.writeObject(off2);
					obj_out_s.flush();
					System.out.println(myName+" sent "+off2);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if(str.equals("offer")){
				try {
					off = (Offerta) obj_in_s.readObject();
					System.out.println(myName+" ha ricevuto "+off);
					obj_out_s.writeObject(lAsta.nuova_offerta(off)); obj_out_s.flush();
				} catch (ClassNotFoundException | IOException e) {
					e.printStackTrace();
				}
			} 
		}
		try {
			cliSocket.close();
		} catch (IOException e) { e.printStackTrace(); }
	}
}
