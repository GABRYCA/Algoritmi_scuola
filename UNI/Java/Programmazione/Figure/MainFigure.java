package figure;

public class MainFigure {

	public static void main(String[] args) {
		RettangoloCustom r1 = new RettangoloCustom(2,3);
		System.out.println(r1.toString());
		System.out.println("Perimetro > "+r1.getPerimetro());
		System.out.println("Area > "+r1.getArea());
	
		RettangoloCustom r2 = new RettangoloCustom(4,1);
		System.out.println(r2);
		System.out.println("Perimetro > "+r2.getPerimetro());
		System.out.println("Area > "+r2.getArea());
		
		System.out.println("Perimetro r1 > r2 -> "+r1.haPerimetroMaggiore(r2));
		System.out.println("Area r1 > r2 -> "+r1.haAreaMaggiore(r2));
	}

}
