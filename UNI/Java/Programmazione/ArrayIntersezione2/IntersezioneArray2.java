import java.util.Random;

public class IntersezioneArray2 {

	public static void main(String[] args) {
		Random ran = new Random();
		
		int dimensioneA = ran.nextInt(20);
		int dimensioneB = ran.nextInt(20);
		int[] a = new int[dimensioneA];
		int[] b = new int[dimensioneB];
		
		for(int i=0; i < a.length; i++)
			a[i] = ran.nextBoolean() ? ran.nextInt(10): -ran.nextInt(10);
		
		System.out.print("Array a > [ ");
		for(int i=0; i < a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println("]");
		
		int contatore = 0;
		for(int i=0; i<a.length; i++){
			boolean controllo = false;
			for(int j=i-1; j >= 0 && !controllo; j--){
				if(a[j] == a[i])
					controllo = true;
			}
			if(!controllo)
				contatore++;
		}
		
		int[] a1 = new int[contatore];
		
		for(int i=0, i1=0; i<a.length; i++){
			boolean controllo = false;
			for(int j=i-1; j >= 0 && !controllo; j--){
				if(a[j] == a[i])
					controllo = true;
			}
			if(!controllo){
				a1[i1] = a[i];
				i1++;
			}
		}
		
		System.out.print("Array a senza ripetizioni > [ ");
		for(int i=0; i < a1.length; i++)
			System.out.print(a1[i] + " ");
		System.out.println("]");
		
		for(int i=0; i < b.length; i++)
			b[i] = ran.nextBoolean() ? ran.nextInt(10): -ran.nextInt(10);
		
		System.out.print("Array b > [ ");
		for(int i=0; i < b.length; i++)
			System.out.print(b[i] + " ");
		System.out.println("]");
		
		int cont = 0;
		for(int i=0; i < a1.length; i++){
			for(int j=0; j < b.length; j++){
				if(a1[i] == b[j]){
					cont++;
					j = b.length;
				}
			}
		}
		
		int[] ris = new int[cont];
		int k = 0;
		
		for(int i=0; i < a1.length; i++){
			for(int j=0; j < b.length; j++){
				if(a1[i] == b[j]){
					ris[k++] = a1[i];
					j = b.length;
				}
			}
		}
		
		System.out.print("Array intersezione > [ ");
		for(int i=0; i < ris.length; i++)
			System.out.print(ris[i] + " ");
		System.out.println("]");
	}
}