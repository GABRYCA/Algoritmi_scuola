package figure;

public class RettangoloCustom extends FiguraCustom implements FigureInterface{

	//CAMPI
	private double base;
	private double altezza;
	
	//COSTRUTTORI
	/*public RettangoloCustom(double b, double a) {
		base = b;
		altezza = a;
	}*/
	
	public RettangoloCustom(double base, double altezza)throws FiguraNonValidaException {
		if(base < 0 && altezza >= 0) throw new BaseNonValidaException("Rettangolo: base non valida!");
		if(altezza < 0 && base >= 0) throw new AltezzaNonValidaException("Rettangolo: altezza non valida!");
		if(base < 0 && altezza < 0) throw new FiguraNonValidaException("Rettangolo: altezza e base non valide!");
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
	
	public boolean equals(RettangoloCustom r) {
		return this.base == r.base && this.altezza == r.altezza;
	}
	
	public boolean equals(Object o) {
		if(o instanceof RettangoloCustom)
			return this.equals((RettangoloCustom)o);
		return false;
	}
	
	public void metodoFigureInterface() {System.out.println("Prova FigureInterface!");}
}
