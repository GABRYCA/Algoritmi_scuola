public class TemiEsame {

	public static void main(String[] args) {

		//indicare il valore di x e y, dopo l'esecuzione di A e B
		//A
		int x = 3, y = 3;
		x = x++ + y++; //y=4, x=6
		y = y-- + y - x; //y=1, x=6
		y = x + y; //y=7, x=6
		System.out.println("x="+x+", y="+y);

		//B
		x = 3; y = 3;
		x = --x + y++; //x=5, y=4
		x = y + ++y - x; //y=5, x=4
		y = x + y; //y=9, x=4
		System.out.println("x="+x+", y="+y);
		
		//condizione sempre vera, sempre falsa, o assegnare valori a x e y
		(x > 2 && y == 7 && !(x < 20)) || ((y != 7) && (x < 2 || x >= 20))
	}
}
