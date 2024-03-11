package figure;

public class QuadratoCustom extends RettangoloCustom {
	
	public QuadratoCustom(int lato) {
		super(lato, lato);
	}
	
	public double getLato() {
		return super.getBase();
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
