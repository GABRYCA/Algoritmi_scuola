package figure;

import java.util.LinkedList;

public class MainFigure {

	public static void main(String[] args) {
		try {
			RettangoloCustom r1 = new RettangoloCustom(3,3);
			System.out.println(r1.toString());
			System.out.println("Perimetro > "+r1.getPerimetro());
			System.out.println("Area > "+r1.getArea());
		
			RettangoloCustom r2 = new RettangoloCustom(4,1);
			System.out.println(r2);
			System.out.println("Perimetro > "+r2.getPerimetro());
			System.out.println("Area > "+r2.getArea());
			
			System.out.println("Perimetro r1 > r2 -> "+r1.haPerimetroMaggiore(r2));
			System.out.println("Area r1 > r2 -> "+r1.haAreaMaggiore(r2));
		
			QuadratoCustom q1 = new QuadratoCustom(3);
			q1.setLato(4);
			//RettangoloCustom q1 = new QuadratoCustom(3);
			System.out.println(q1.toString());
			System.out.println(q1.getDescrizione1());
			System.out.println(q1.getDescrizione2());
			System.out.println("Perimetro > "+q1.getPerimetro());
			System.out.println("Area > "+q1.getArea());
			
			System.out.println("q1.equals(r1) > "+q1.equals(r1));
			System.out.println("r1.equals(q1) > "+r1.equals(q1));
			
			Object r3 = new Object();
			System.out.println("r1.equals(r3) > "+r1.equals(r3));
			r3 = new RettangoloCustom(3,2);
			System.out.println("r1.equals(r3) > "+r1.equals(r3));
			r3 = new RettangoloCustom(3,3);
			System.out.println("r1.equals(r3) > "+r1.equals(r3));
			
			FiguraCustom[] a = new RettangoloCustom[5]; //consentito dalla gerarchia dei tipi
			//LinkedList<FiguraCustom> list = new LinkedList<RettangoloCustom>(); //NON consentito dalla gerarchia dei tipi
			LinkedList<? extends FiguraCustom> list = null;
			
			char scelta = 'q';
			switch(scelta) {
				case 'r':
					LinkedList<RettangoloCustom> rlist = new LinkedList<RettangoloCustom>();
					rlist.add(r1);
					rlist.add(r2);
					list = rlist; //!!!
					break;
				case 'q':
					LinkedList<QuadratoCustom> qlist = new LinkedList<QuadratoCustom>();
					qlist.add(q1);
					list = qlist; //!!!
					break;
			}
			for(FiguraCustom f: list)
				System.out.println(f.toString());
			
			q1.metodoFigureInterface();
		}catch(FiguraNonValidaException e) {
			System.err.println(e.getMessage());
		}
	}

}
