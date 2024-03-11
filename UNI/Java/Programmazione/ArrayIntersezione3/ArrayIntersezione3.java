import java.util.*;

public class ArrayIntersezione3{
	public static void main(String[] args){
		final int DIM = 5;
		
		//NOTA: l'esercizio non prevedeva di supporre che tutti gli
		//array avvessero uguale dimensione
		int[] a = new int[DIM];
		int[] b = new int[DIM];
		
		Random rand = new Random();
		
		for(int i=0; i < a.length; i++){
			a[i] = rand.nextInt(3);
			b[i] = rand.nextInt(3);
		}
		stampaArray(a);
		stampaArray(b);
		
		int[] c = new int[DIM];
		
		for(int i=0, k=0; i < a.length; i++){
			for(int j=0; j < b.length; j++){
				if(a[i] == b[j]){
					boolean flag = true;
					for(int h=0; h < c.length; h++){
						if(a[i] == c[h]){
							flag = false;
							break;
						}
					}
					if(flag){
						c[k] = a[i];
						k++;
					}
				}
			}
		}
		stampaArray(c);
	}
	public static void stampaArray(int[] x){
		System.out.println("");
		System.out.print("[ ");
		for(int i=0; i < x.length; i++){
			System.out.print(x[i] + " ");
		} 
		System.out.print("]");
	}
}