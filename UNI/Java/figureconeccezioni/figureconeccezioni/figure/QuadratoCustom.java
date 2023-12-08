package figure;

public class QuadratoCustom extends RettangoloCustom {
	
	public QuadratoCustom(int lato) throws FiguraNonValidaException{
		super(lato, lato);
	}
	
	public double getLato() {
		return super.getBase();
	}
	
	public void setLato(double l) {
		super.setBase(l);
		super.setAltezza(l);
	}
	
	public void setBase(double x) {
		setLato(x);
	}
		
	public void setAltezza(double x) {
		setLato(x);
	}
	
	public String getDescrizione1() {
		return this.toString();
	}
	
	public String getDescrizione2() {
		return super.toString();
	}
	
	public String toString() {
		return "Quadrato > lato: "+this.getLato();
	}
}
