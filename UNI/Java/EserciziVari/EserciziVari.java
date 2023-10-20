public class EserciziVari {

	public static void main(String[] args){
		//indicare il contenuto di i e j
		int i=4,j=7;
		j = i + (i = j); //i = 7, j = 11
		j = i + (i = i); //i = 4, j = 8
		j = (i = j) + i; //i = 7, j = 14
		j = i-- + --j; //i = 3, j = 10
		j = i + (j = j + 1) + (j = i + 2) + (i = j); //i = 6, j = 24
	//  j = 4 + 8 + 6 + 6
	
		//indicare il contenuto di x e y
		int x = 0, y = 0; //caso 1
		int x = 4, y = 0; //caso 2
		int x = 1, y = 4; //caso 3
		if(x <= y && (x = y--) > 0)
			x = y;
		//caso 1 -> x = 0, y = -1 false
		//caso 2 -> x = 4, y = 0 false (lazy evaluation)
		//caso 3 -> x = 3, y = 3 true
		
		int x = 3, y = 3; //caso 1
		int x = 2, y = 0; //caso 2
		int x = 2, y = 1; //caso 3
		if(x != y && (x = y++) > 0)
			x = y;
		//caso 1 -> x = 3, y = 3 false (lazy evaluation)
		//caso 2 -> x = 0, y = 1 false
		//caso 3 -> x = 2, y = 2 true
		
		//indicare delle dichiarazioni per le variabili
		//in modo che le espressioni siano corrette dal
		//punto di vista dei tipi (se non è possibile,
		//spiegare il motivo)
		
		x = (y-- > 4) && !z; //boolean x, int y, boolean z
		x = (x == y); //boolean x,y;
		x = (x == 1); //impossibile, x dovrebbe essere sia int che boolean
		x = x = 1; //int x;
		x = !x; //boolean x;
		x = x = x; //qualsiasi tipo per x è ok :-)
		x = (x == x); //boolean x;
		
		//indicare il risultato delle espressioni
		int x = 8, y = 9;
		x = y; //x = 9, y = 9
		x == y; //false
		x != y; //true
		++x; //x = 9, y = 9
		
		int x = 8, y = 9;
		((x-y) > (y = x)) && (x == y--); //x = 8, y = 8 false //lazy evaluation
		((x-y) < (y = x)) && (x == y--); //x = 8, y = 7 true
		((x-y) > (y = x)) || (x == y--); //x = 8, y = 7 true
		((x-y) < (y = x)) || (x == y--); //x = 8, y = 8 true //lazy evaluation
		
		!((x-y) > (y = x)) && (x == y--); //x = 8, y = 7 true
		!((x-y) < (y = x)) && (x == y--); //x = 8, y = 8 false //lazy evaluation
		!((x-y) > (y = x)) || (x == y--); //x = 8, y = 8 true //lazy evaluation
		!((x-y) < (y = x)) || (x == y--); //x = 8, y = 7 true
		
		int x = 8, y = 9;
		x++ == y--; //x = 9, y = 8 false
		x++ == --y; //x = 9, y = 8 true
		++x == --y; //x = 9, y = 8 false
		++x == y--; //x = 9, y = 8 true
		
		x == y ? x++ : --y; //x = 8, y = 8 false
		x != y ? x++ : --y; //x = 9, y = 9 true
	
	}
}