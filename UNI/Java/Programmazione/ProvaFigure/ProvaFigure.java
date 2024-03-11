import java.util.Scanner;
import java.util.LinkedList;
import prog.utili.Rettangolo;
import prog.utili.Quadrato;

public class ProvaFigure {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		LinkedList<Rettangolo> list = new LinkedList<Rettangolo>();
		
		System.out.println("Inserimento rettangoli/quadrati (zero per terminare)");
		double b, a;
		Rettangolo tmp, areaMax = null;
		
		do {
			System.out.print("Inserire la base > ");
			b = in.nextDouble();
			System.out.print("Inserire l'altezza > ");
			a = in.nextDouble();
			
			if(b == a)
				tmp = new Quadrato(b);
			else 
				tmp = new Rettangolo(b,a);
			
			if(a != 0 && b != 0)
				list.add(tmp);
			
			if(areaMax == null || tmp.haAreaMaggiore(areaMax))
				areaMax = tmp;
			
		} while(a != 0 && b != 0); //verificare che l'utente non inserisca valori negativi
		
		int contQ=0;
		System.out.println("\n*** Figure inserite ***");
		for(Rettangolo x: list)
			if(x instanceof Quadrato) {
				contQ++;
				System.out.println("Quadrato > "+x.toString()+", perimetro: "+x.getPerimetro()+", area: "+x.getArea());
			}
			else 
				System.out.println("Rettangolo > "+x.toString()+", perimetro: "+x.getPerimetro()+", area: "+x.getArea());
		
		System.out.println("\n*** Numero di quadrati > "+contQ);	
		System.out.println("\n*** Numero di rettangoli che non sono quadrati > "+(list.size()-contQ));		
		System.out.println("\n*** Figura con area maggiore ***");
		System.out.println(areaMax.toString()+", perimetro: "+areaMax.getPerimetro()+", area: "+areaMax.getArea());
	}
}
