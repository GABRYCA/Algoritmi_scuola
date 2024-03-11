package figure;

public abstract class FiguraCustom {

	public abstract double getArea();
	public abstract double getPerimetro();
	
	public boolean haAreaMaggiore(FiguraCustom f) {
		if(this.getArea() > f.getArea())
			return true;
		else return false;
	}
	
	public boolean haPerimetroMaggiore(FiguraCustom f) {
		if(this.getPerimetro() > f.getPerimetro())
			return true;
		else return false;
	}
}
