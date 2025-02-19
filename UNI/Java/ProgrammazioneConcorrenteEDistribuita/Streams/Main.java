import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws IOException {
		System.out.println("Programma di GCA... Caricamento");
		// copiaFile(args[0], args[1]);
		//leggiFile(args[0]);
		//scriviFile(args[0]);
		//leggiFileRigaPerRiga(args[0]);
		scriviFileRigaPerRiga(args[0]);
	}
	
	public static void copiaFile(String sorgente, String destinazione) throws IOException {
		System.out.println("Sto copiando " + sorgente + " in " + destinazione);
		
		int c = 0;
		FileInputStream in = new FileInputStream(sorgente);
		FileOutputStream out = new FileOutputStream(destinazione);
		while ((c = in.read()) != -1) {
			out.write(c);
		}
		out.close();
		in.close();
		
		System.out.println("Copiato con successo!");
	}
	
	public static void leggiFile(String sorgente) throws IOException {
		System.out.println("Sto leggendo il contenuto di " + sorgente);
		
		FileReader reader = new FileReader(sorgente);
		
		int c;
		while((c = reader.read()) != -1) {
			System.out.print((char) c);
		}
		reader.close();
		
		System.out.println("\nFine lettura!");
	}
	
	public static void scriviFile(String sorgente) throws IOException {
		System.out.println("Sto scrivendo in " + sorgente);
		
		FileWriter writer = new FileWriter(sorgente);
		String testo = "Ciao";
		
		for (char c : testo.toCharArray()) {
			writer.write(c);
		}
		writer.close();
		
		System.out.println("File scritto con successo!");
	}
	
	public static void leggiFileRigaPerRiga(String sorgente) throws IOException {
		System.out.println("Sto leggendo, riga per riga, da " + sorgente);
		FileReader reader = new FileReader(sorgente);
		BufferedReader bufferedReader = new BufferedReader(reader);
		
		String riga;
		while((riga = bufferedReader.readLine()) != null) {
			System.out.println(riga);
		}
		bufferedReader.close();
		reader.close();
		
	
		System.out.println("Finito di leggere il file!");
	}
	
	public static void scriviFileRigaPerRiga(String destinazione) throws IOException {
		FileWriter writer = new FileWriter(destinazione);
		PrintWriter printWriter = new PrintWriter(writer);
		
		ArrayList<String> arrayDiString = new ArrayList<String>();
		arrayDiString.add("Riga1");
		arrayDiString.add("Riga2");
		for (String riga : arrayDiString) {
			printWriter.println(riga);
		}
		printWriter.close();
		writer.close();
		
		System.out.println("Finito di scrivere il file!");
	}
}
