import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.Scanner;


public class Studente implements Comparable {
	
	//campi privati
	private double media;
	private String matricola;
	
	//metodi publici
	public Studente(){
		matricola = "inv";
		media = 0.;
	}
	
	//costruttore
	public Studente(String m){
		matricola = m;
		media = 0.;
	}
	
	//aggiornare la media
	public void setMedia(double media) {
		this.media = media;
	}

	//ritorna la matricola
	public String getMatricola() {
		return matricola;
	}
	
	//ritorna la media
	public double getMedia() {
		return media;
	}
	
	public void computeMedia(){
		this.media =  computeMediaFromInput();
	}
		
	//calcola la media da un insieme di reali letti in input
	private double computeMediaFromInput(){
		System.out.println("inserisci i voti dello studente, per terminare inserisci un qualsiasi carattere");
		
		Scanner sc = new Scanner(System.in);
		int numDouble = 0; //contatore di double letti
		double acc = 0.; //accumulatore dei valori letti
		while (sc.hasNextDouble()){
			numDouble++; //incremento il contatore
			acc += sc.nextDouble(); //accumulo il valore del dato letto
		}
		return acc/numDouble;		
	}

	
	/**
	 * Confronta le informazioni rilevanti per l'oggetto di invocazione con 
	 * l'oggetto passato come parametro.
	 * Ritorna true se tali informazioni sono uguali, false altrimenti
	 * <p>
	 * Due studenti sono considerati uguali se hanno la stessa matricola
	 * 
	 * @param obj l'oggetto con cui voglio verificare l'uguaglianza dell'oggetto di invocazione
	 * @retrun true se obj e' di tipo Studente e se le informazioni rilevanti per 
	 * obj e per l'oggetto di invocazione sono uguali. 
	 * */	
	public boolean equals(Object obj) {
	      System.out.println("metodo non implementato");
	      return false;
	}
	
	
	public static void main(String[] args) throws IOException {
		Studente s1 = new Studente(new String("VR0001"));
		Studente s2 = new Studente(new String("VR0001"));

		System.out.println("s1: "+s1); 
		System.out.println("s2: "+s2); 
		

		//test equals
		System.out.println("s1 == s2 : "+(s1==s2)); 
		System.out.println("s1.equals(s2) : "+(s1.equals(s2))); 
		
		s1 = s2;
		System.out.println("s1: "+s1); 
		System.out.println("s2: "+s2); 
		
		System.out.println("s1 == s2 : "+(s1==s2));
		System.out.println("s1.equals(s2) : "+(s1.equals(s2)));		
		
		
		//test massimo 
		Studente s3 = new Studente("VR0003");
		s1.setMedia(30);
		s3.setMedia(30);
		Studente m = (Studente) massimo(s1,s3);
		System.out.println("s3 : "+s3);
		System.out.println("massimo tra s1 ed s3 = "+m);
		
		String st1 = new String("primo");
		String st2 = new String("secondo");
		
		System.out.println("String maggiore : "+massimo(st1, st2));

		System.out.println("Oggetto maggiore (studente s1 e string st2): "+massimo(s1, st2));		
	
	}

	
	/**
	 * Confronta due studenti e ritorna il massimo tra i due. 
	 * Se i due studenti sono uguali ritorna il primo 
	 * 	
	 * @param o1 primo oggetto
	 * @param o2 secondo oggetto
	 * @retrun il massimo tra o1 ed o2 
	 * */	
	public static Comparable massimo(Comparable o1, Comparable o2) {
		if (o1.compareTo(o2)<0){
			return o2;
		} else {
			return o1;
		}
	}

	/**
	 * Confronta l'oggetto di invocazione con l'oggetto passato come parametro.
	 * Ritorna un intero negativo/positivo/nullo se l'oggetto di invocazione e' 
	 * minore/maggiore/uguale di o 
	 * <p>
	 * Uno studente s1 e': 
	 * minore di s2 se s1.media < s2.media
	 * maggiore di s2 se s1.media > s2.media
	 * <p>
	 * Se s1.media==s2.media: s1 < s2 se s1.matricola < s2.matricola, e s1 > s2 se s1.matricola > s2.matricola
	 * L'ordine tra le matricole e' quello lessicografico. 
	 * Due studenti sono uguali se hanno stessa media stessa mtaricola.
	 * 	
	 * @param o l'oggetto con cui voglio confrontare l'oggetto di invocazione
	 * @retrun un intero negativo/positivo/nullo se l'oggetto di invocazione e' 
	 * minore/maggiore/uguale di o 
	 * */	
	public int compareTo(Object obj) throws IllegalArgumentException{
			if (obj instanceof Studente) {
				Studente s = (Studente) obj;
				double diff = (media - s.getMedia());
				if (diff == 0){
					return this.getMatricola().compareTo(s.getMatricola());
				} else {
				    return (diff>0)?1:-1;
				}
			} else {
				throw new IllegalArgumentException("tipo non comparabile");
			}
	}

	@Override
	public String toString() {
		return "<"+matricola+", "+media+">";
	}

	public static Studente[] leggiStudentiFile(String filename) throws IOException {
		
		FileReader fr = new FileReader(filename);
		BufferedReader aux = new BufferedReader(fr);
		String line = aux.readLine();
		int numStud = 0;
		while(line!=null){
			numStud++;
			aux.readLine(); // leggo media
			line = aux.readLine(); // leggo prossima matricola
		}
		Studente[] s = new Studente[numStud];
		
		fr = new FileReader(filename);
		BufferedReader br = new BufferedReader(fr);
		for (int i = 0; i < s.length; i++) {
			s[i] = new Studente(br.readLine());
			s[i].setMedia(Double.valueOf(br.readLine()));
		}
		return s;
	}
	
	
	
}