import prog.utili.*;

public class EsempiGerarchia {

	public static void main(String[] args) {
		
		Rettangolo r = null;
		
		System.out.println(r instanceof Rettangolo); //false
		System.out.println(r instanceof Quadrato); //false
		
		r = new Quadrato(1);
		
		System.out.println(r instanceof Rettangolo); //true
		System.out.println(r instanceof Quadrato); //true
		
		r = new Rettangolo(1,1);
		
		System.out.println(r instanceof Rettangolo); //true
		System.out.println(r instanceof Quadrato); //false
		
		Object o = new Quadrato(1);
		String s = o.toString(); //esegue il metodo toString di Quadrato
		
		Rettangolo o = new Quadrato(1);
		String s = o.toString(); //esegue il metodo toString di Quadrato
		
		Rettangolo o = new Rettangolo(1,1);
		String s = o.toString(); //esegue il metodo toString di Rettangolo
		
		Rettangolo o = new Quadrato(1);
		Quadrato q = (Quadrato)o; //cast
		String s = q.toString(); //esegue il metodo toString di Quadrato
		
		Rettangolo o = new Rettangolo(1,1);
		Quadrato q = (Quadrato)o; //compilazione ok, errore in esecuzione
		String s = q.toString();
		
		Object o = new Frazione(1,1);
		Quadrato q = (Quadrato)o; //errore in compilazione
		String s = q.toString();
		
		Object o = new Object();
		String s = o.toString(); //esegue il metodo toString di Object
		
		Object o;
		Rettangolo r;
		Quadrato q;
		Frazione f;
		
		o = o; //corretto
		o = r; //corretto
		o = (Rettangolo)r; //corretto, cast inutile
		o = q; //corretto
		o = f; //corretto
		r = o; //non corretto
		r = q; //corretto
		r = f; //non corretto
		r = (Rettangolo)r; //corretto, cast inutile
		q = (Rettangolo)r; //non corretto, cast inutile
		o = (Quadrato)r; //possibile errore in esecuzione
		r = (Quadrato)r; //possibile errore in esecuzione
		f = (Frazione)o; //possibile errore in esecuzione
	}
}
		