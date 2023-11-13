package varie;

public class FrazioneCustom {

	//CAMPI
	private int num;
	private int den;
	
	//COSTRUTTORI
	/*public FrazioneCustom(int num, int den){
		this.num = num;
		this.den = den;
	}*/
	
	public FrazioneCustom(int num, int den){
		if (den == 0)
			throw new ArithmeticException("Frazione non valida: " +
			"denominatore 0");
		else {
			//memorizza il segno
			boolean negativo = (num < 0 && den > 0) || (num > 0 && den < 0);
			if (num < 0)
				num = -num; //elimina l'eventuale segno meno davanti a x
			if (den < 0)
				den = -den; //elimina l'eventuale segno meno davanti a y
			int m = mcd(num, den);
			if(negativo)
				this.num = -num / m; //il segno viene memorizzato al numeratore
			else
				this.num = num / m;
			this.den = den / m;
		}
	}
	
	public FrazioneCustom(int num){
		/*this.num = num;
		this.den = 1;*/
		this(num,1);
	}
	
	//METODI
	public int getNumeratore() {
		return num;
	}
	
	public int getDenominatore() {
		return den;
	}
		
	public FrazioneCustom per(FrazioneCustom f) {
		int n = this.num * f.num;
		int d = this.den * f.den;
		FrazioneCustom g = new FrazioneCustom(n, d);
		return g;
		//return new FrazioneCustom(n, d);
	}
	
	public FrazioneCustom piu(FrazioneCustom f) {
		int n = this.num * f.den + this.den * f.num;
		int d = this.den * f.den;
		return new FrazioneCustom(n, d);
	}
	
	public FrazioneCustom meno(FrazioneCustom f) {
		int n = this.num * f.den - this.den * f.num;
		int d = this.den * f.den;
		return new FrazioneCustom(n, d);
	}
	
	public FrazioneCustom diviso(FrazioneCustom f) {
		int n = this.num * f.den;
		int d = this.den * f.num;
		return new FrazioneCustom(n, d);
	}
	
	public boolean equals(FrazioneCustom f) {
		FrazioneCustom g = this.meno(f);
		/*if (g.num == 0)
			return true;
		else
			return false;*/
		return g.num == 0;
	}
	
	public boolean isMinore(FrazioneCustom f) {
		FrazioneCustom g = this.meno(f);
		return (g.num < 0 && g.den > 0) || (g.num > 0 && g.den < 0);
	}
	
	public boolean isMaggiore(FrazioneCustom f) {
		FrazioneCustom g = this.meno(f);
		return (g.num < 0 && g.den < 0) || (g.num > 0 && g.den > 0);
		}
	
	public String toString() {
		return "Frazione > num: "+num+", den: "+den;
	}
	
	//private methods
	private static int mcd(int a, int b) {
		int resto;
		do {
			resto = a % b;
			a = b;
			b = resto;
		} while (resto != 0);
		return a;
	}
}
