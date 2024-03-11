/* Si scriva il codice del metodo
public static int[] intersezione(int[] a, int[] b)
che deve restituire l’array che contiene tutti e soli gli elementi che compaiono sia nell’array a che nell’array b senza
ripetizioni, cio `e se un elemento compare in a e b piu di una volta, compare comunque una sola volta nell’intersezione
dei due array. Si assuma che il metodo venga sempre invocato con argomenti diversi da null. Alcuni esempi di
esecuzione sono i seguenti (negli esempi viene indicato con [] l’array vuoto, cio`e l’array di lunghezza zero
*/
public class IntersezioneArray {

	public static void main(String[] args) {
		
		int[] a = {4, -3, 9, 0};
		int[] b = {4, 4, 3, 0, 0, 3};
		int cont = 0;
		
		//si scorrono i due array con due cicli for innestati
		for(int i=0; i < a.length; i++)
			for(int j=0; j < b.length; j++)
				//confronto tra l'elemento in posizione i di args
				//con tutti gli elementi in posizione j di b
				//se trovo un valore uguale, aggiorno un contatore
				
		//il contatore è la dimensione dell'array risultato
		int[] ris = new int[cont];
		int k = 0;
		
		//si ri-eseguono i cicli for innestati per inserire gli elementi
		//nell'array risultato
		for(int i=0; i < a.length; i++)
			for(int j=0; j < b.length; j++)
				//confronto
				ris[k++] = //assegnamento
	}
}
		