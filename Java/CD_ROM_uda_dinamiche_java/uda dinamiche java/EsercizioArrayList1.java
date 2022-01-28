/** Esercizio 3 Si progettino i seguenti metodi statici:

    - frequenza(): prende come parametro un'array di interi, e restituisce una
      nuova array con la frequenza dei valori (quante volte un numero compare nell'array).
    - eliminaDuplicati(): prende come parametro un'array di interi, e restituisce un 
      arraylist che contiene i valori dell'array senza duplicati.
    - seleziona(): prende come parametri un numero intero 'n' ed un'array di interi, 
      e restituisce una nuova array che contiene solo i valori maggiori od uguali ad 'n'.
    - isOrdered(): prende come parametro un'array di interi, e restituisce true se
      l'array e' ordinata, false altrimenti.

Scrivete una classe di test che prende in input un numero 'k' e crea un'array 
con 'k' numeri interi random (compresi tra 0 e 9), e chiama tutti i metodi, stampandone i risultati.
*/

 
import java.util.Random;
import java.util.*;
import java.util.Scanner;

public class EsercizioArrayList1 {

    public static int[] frequenza(int[] a){
        int[] frequenza = new int[a.length];
        for(int i=0;i<a.length;i++) {
            int contatore=0;
            for(int j=0;j<a.length;j++) 
                if(a[i]==a[j])
                    contatore++;
            frequenza[i]=contatore;
        }
        return frequenza;
    }
    
    public static ArrayList<Integer> eliminaDuplicati(int[] a) {
        ArrayList<Integer> b = new ArrayList<Integer>();
        for(int i=0;i<a.length;i++) 
            if(!b.contains(a[i]))
                b.add(a[i]);
        return b;
    }
    
    public static int[] seleziona(int n, int[] a){
        int contatore=0;
        for(int i=0;i<a.length;i++)
            if(a[i]>=n)
                contatore++;
        
        int[] b = new int[contatore];
        int j=0;
        for(int i=0;i<a.length;i++)
            if(a[i]>=n) {
                b[j]=a[i];
                j++;
            }
        return b;
    }
    
    public static boolean isOrdered(int[] a) {
        for(int i=0;i<a.length-1;i++) 
            if(a[i]>a[i+1])
                return false;
        return true;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Inserisci il numero di elementi: ");
        int k = (in.nextInt()); // ctr se c'e  ancora una riga
        Random g = new Random();
        int[] a = new int[k];
        for(int i=0;i<k;i++) {
            a[i]=g.nextInt(10);
            System.out.print(a[i]+" ");
        }
                
        System.out.print("\nFrequenza: ");
        int[] f = frequenza(a);
        for(int i=0;i<f.length;i++) {
            System.out.print(f[i]+" ");
        }
        
        System.out.print("\nElimina duplicati: ");
        ArrayList<Integer> e = eliminaDuplicati(a);
        for(int elemento : e) {
            System.out.print(elemento+" ");
        }
        
        System.out.print("\nSeleziona con n=3: ");
        int[] s = seleziona(3,a);
        for(int i=0;i<s.length;i++) {
            System.out.print(s[i]+" ");
        }
        
        System.out.print("\nL'array e' ordinata? "+isOrdered(a));
    }
}
