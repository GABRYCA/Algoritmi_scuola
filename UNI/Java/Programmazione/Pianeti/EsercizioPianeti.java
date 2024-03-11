public class EsercizioPianeti {
	
    public static void main(String[] args){
       
		Pianeti[] array = Pianeti.values();

		System.out.println("Ordine crescente: ");
		for (Pianeti pianeti: array)
			System.out.println(pianeti.ordinal() +" > " + pianeti.toString());
		
		Pianeti[] reverse = new Pianeti[array.length]; //creazione dell'array con gli elementi in ordine inverso
		for (int i=0; i< reverse.length; i++)
			reverse[i] = array[array.length-i-1];

		System.out.println("Ordine decrescente: ");
			for (Pianeti pianeti: reverse)
				System.out.println(pianeti.ordinal() +" > "+ pianeti.name());

    }
}
