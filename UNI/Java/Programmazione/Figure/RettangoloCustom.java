package figure;

public class RettangoloCustom extends FiguraCustom{

	//CAMPI
	private double base;
	private double altezza;
	
	//COSTRUTTORI
	/*public RettangoloCustom(double b, double a) {
		base = b;
		altezza = a;
	}*/
	
	public RettangoloCustom(double base, double altezza) {
		this.base = base;
		this.altezza = altezza;
	}
	
	//METODI
	public double getBase() {
		return base;
	}

	public void setBase(double base) {
		this.base = base;
	}

	public double getAltezza() {
		return altezza;
	}

	public void setAltezza(double altezza) {
		this.altezza = altezza;
	}
	
	public String toString() {
		return "Rettangolo > base: "+base+", altezza: "+altezza;
	}
	
	public double getArea() {
		return base*altezza;
	}
	
	public double getPerimetro() {
		return (base+altezza)*2;
	}
}
