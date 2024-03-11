public class EsempiWrapper {

	public static void main(String[] args){
		int max = Integer.MAX_VALUE;
		int min = Integer.MIN_VALUE;
		
		System.out.println("MAX_VALUE > " + max);
		System.out.println("MIN_VALUE > " + min);
		
		Integer a = 3; //costruttore deprecated
		Integer b = 2; //meccanismo di auto-boxing
		int c =  a + b; 
		int x = a; //meccanismo di un-boxing
		int ris = a.compareTo(x);
		//int ris = x.compareTo(a); //errore in compilazione
		
		System.out.println("compareTo " + ris);
	}
}