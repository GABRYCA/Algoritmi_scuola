import prog.utili.Frazione;

public class ProvaString {
	public static void main(String[] args) {
		String s1 = new String("java");
		String s2 = "PROG";
		//s1 = s1.toUpperCase(); //sovrascrive s1
		//String s3 = s1.toUpperCase(); //s1 rimane invariato
		String s3 = s1.concat(s2).concat("!");
		
		System.out.println("s = " + "CiAo".toUpperCase().toLowerCase());
		System.out.println("s1 = " + s1);
		System.out.println("s2 = " + s2);
		System.out.println("s3 = " + s3);
		System.out.println("s3 = " + s1 + s2 + "!"); //stesso risultato di riga 13
		
		//operatore + e metodo concat non si "comportano" nello stesso modo
		System.out.println("ciao " + 5);
		System.out.println("ciao".concat("5"));
		System.out.println(3 + "ciao " + 5);
		System.out.println("3".concat("ciao").concat("5"));
		System.out.println("ciao " + (5 + 3));
		System.out.println("ciao".concat("5").concat("3"));
		System.out.println(5 + 3 + "ciao");
		System.out.println("5".concat("3").concat("ciao"));
		
		/*int x = 2;
		int y = 3;*/
		int x = 2, y = 3;
		String s = "stringa";
		System.out.println(x + y); //5
		System.out.println(s + x + y); //stringa23
		System.out.println(x + y + s); //5stringa
		System.out.println((x + y) + s); //5stringa
		System.out.println(s + (x + y)); //stringa5
		System.out.println("" + x + y + s); //23stringa
		System.out.println("" + (x + y) + s); //5stringa
		System.out.println(x + (y + s)); //23stringa
		
		System.out.println("s3.length()  " + s3.length());
		System.out.println("s3 sub1 " + s3.substring(0,4)); //cosa stampa?
		System.out.println("s3 sub2 " + s3.substring(4,8)); //cosa stampa?
		System.out.println("s3 sub3 " + s3.substring(8)); //cosa stampa?
		
		//stampare la prima metà di s3
		System.out.println("s3 prima meta' " + s3.substring(0, s3.length()/2));
		//stampare la seconda metà di s3
		System.out.println("s3  seconda meta' " + s3.substring(s3.length()/2));
	
		//è importante capire cosa succede in memoria in questi passaggi
		String a = "ciao";
		String b = "hello";
		b = a;
		a = "hello";
		a = b;
		
		char c = s1.charAt(0); //estrazione di un carattere da una stringa
		/*String z = null;
		System.out.println(z.length()) //nullpointerexception;
		Frazione f = null;
		System.out.println(f.getNumeratore()); //nullpointerexception*/
		
		//int k = 7; //NO
		//if(k == null) ; //NO
		
		//trasformare un intero in stringa
		int k = 7;
		String sk = String.valueOf(k); //invocazione di un metodo statico
		System.out.println("k convertito in stringa > " + sk);
		k = Integer.parseInt(sk);
		System.out.println("k riconvertito in int > " + k);
		double d = Double.parseDouble("5.4");
		System.out.println("stringa double convertita in double > " + d);		
	}
}