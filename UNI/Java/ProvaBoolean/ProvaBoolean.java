
public class ProvaBoolean {
	
	public static void main(String[] args){
		
		boolean x, y, z, b;
		int a;
		
		b = (x == x) || (x == !x); //sempre vera
		b = (x == x) && (x == !x); //sempre falsa
		b = (x == y) || (x == !y); //sempre vera
		b = (x == y) && (x == !y); //sempre falsa
		b = (z || !z); //sempre vera
		b = (z && !z); //sempre falsa
		b = x || (y && !x); //dipende
		b = x || (y || !x); //sempre vera
		b = x && (y && !x); //sempre falsa
		
		b = (a >= 10) && (a <= 25); //vera se 10<=a<=25
		b = (a >= 10) || (a <= 25); //sempre vera
		b = (a < 10) && (a > 25); //sempre falsa
		b = (a < 10) || (a > 25); //dipende
		
		b = x || (a != 10); //dipende da a e x
		b = x && (a != 10); //dipende da a e x
		b = x || (a != a); //dipende da x
		b = x && (a != a); //sempre falsa
		
		b = x || (a >= 10) && (a <= 25); //dipende da a e x
		b = (x || (a >= 10)) && (a <= 25); //dipende da a e x
		b = x || (a >= 10) || (a <= 25); //sempre vera
		b = (x && (a >= 10)) || (a <= 25); //dipende da a e x
		b = x && ((a >= 10) || (a <= 25)); //dipende da x
	}
}