
public class EsempiLazy {
	public static void main(String[] args){
		
		int a = 2, b = 3, c = 0;
		
		if(a > b && b > 0) //lazy evaluation
		//if(a > b || b > 0)
		//if(a > b && b++ > 0) //lazy evaluation
		//if(a > b || b++ > 0)
		//if(a > b || b++ > 3)
		//if(a > b || ++b > 3)
		//if(a > b & b++ > 0) //"evitare" la lazy evaluation
			c = a + b;
		else 
			c = a - b;
		
		System.out.println("a = "+a);
		System.out.println("b = "+b);
		System.out.println("c = "+c);
		
		//operatore condizionale ternario
		c = (a > b & b++ > 0)? (a+b):(a-b);
		//c = (a > b & b++ > 0)? (a+b):"ciao"; //NO! i tipi devono essere compatibili
		
		a = 2; b = 3;
		//String s = (++a >= b--)? "ciao": "hello";
		//String s = (++a >= --b)? "ciao": "hello";
		//String s = (a++ >= --b)? "ciao": "hello";
		String s = (a++ >= b--)? "ciao": "hello";
		System.out.println("a = "+a);
		System.out.println("b = "+b);
		System.out.println("s = "+s);
		
		a = 2; b = 3;
		//s = (a++ >= --b)? "ciao": null;
		s = (a++ >= b--)? "ciao": null;
		System.out.println("a = "+a);
		System.out.println("b = "+b);
		
		if(s != null)
			System.out.println("s = "+s+", lunghezza = "+s.length());
		else
			System.out.println("s = "+s);
		
		if(s != null && s.length() > 10) //lazy evaluation -> NO errore in esecuzione
		//if(s.length() > 10 && s != null) //errore in esecuzione
		//if(s != null & s.length() > 10) //"evitare" lazy evaluation -> errore in esecuzione
			System.out.println("lunghezza stringa > 10");
			
		String tmp = (s != null && s.length() > 10) ? "lunghezza stringa > 10\n" : "";
		System.out.print(tmp);
	}
}