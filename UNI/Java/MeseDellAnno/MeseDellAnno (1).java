package varie;

public enum MeseDellAnno {
	
	GENNAIO("Gennaio", 31), FEBBRAIO("Febbraio", 28){
								public int numeroGiorni(boolean bisestile) {
									return bisestile ? 29 : 28;
								}
							},
	MARZO("Marzo", 31), APRILE("Aprile", 30),
	MAGGIO("Maggio", 31), GIUGNO("Giugno", 30),
	LUGLIO("Luglio", 31), AGOSTO("Agosto", 31),
	SETTEMBRE("Settembre", 30), OTTOBRE("Ottobre", 31),
	NOVEMBRE("Novembre", 30), DICEMBRE("Dicembre",31);
	
	// CAMPI
	private String nome;
	private int numGiorni;
	
	// COSTRUTTORI
	private MeseDellAnno(String nome, int numGiorni) {
		this.nome = nome;
		this.numGiorni = numGiorni;
	}
	
	public int numeroGiorni() {
		return this.numGiorni;
	}
	
	public int numeroGiorni(boolean isBisestile) {
		return this.numeroGiorni();
	}
	
	public int numeroGiorni(int anno) {
		return this.numeroGiorni(isAnnoBisestile(anno));
	}

	public String toString() {
		return this.nome;
	}
	
	private boolean isAnnoBisestile(int anno) {
		return (anno%4==0 && anno%100!=0 || anno%400==0);
	}
}
