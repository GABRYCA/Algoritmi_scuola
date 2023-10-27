public class ProvaForEach {

	public static void main(String[] args) {
		
		int[] numeri = {4, -3, 9, 0};
		
		System.out.print("numeri [ ");
		for(int tmp: numeri)
			System.out.print(tmp + " ");
		System.out.print("]");
		
		String[] stringhe = {"java", "prog", "uninsubria"};
		
		System.out.print("\nstringhe [ ");
		for(String tmp: stringhe)
			System.out.print(tmp + " ");
		System.out.print("]");
		
		System.out.println("\nDimensione array args > "+args.length);
		System.out.print("args [ ");
		for (String s : args)
			System.out.print(s + " ");
		System.out.println("]");
		
		if(args.length != 0) {
			String tmp = args[0];
			boolean numOK = true;
			for(int i=0; i<tmp.length() && numOK; i++) {
				char c = tmp.charAt(i);
				if(!Character.isDigit(c))
					numOK = false;
			}
			if(numOK) {
				int dimArray = Integer.parseInt(tmp);
				numeri = new int[dimArray];
				System.out.print("numeri [ ");
				for(int tmp2: numeri)
					System.out.print(tmp2 + " ");
				System.out.println("]");
			} else
				System.out.println("Usage: java ProvaForEach array_dim");
		} else 
			System.out.println("Usage: java ProvaForEach array_dim");
	}
}