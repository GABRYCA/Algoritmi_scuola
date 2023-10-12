public class Individuo {
 // nome dell ’individuo
 private String nome ;
 // riferimento al padre (di tipo Individuo )
 private Individuo padre ;
 // riferimento alla madre (di tipo Individuo )
 private Individuo madre ;
 // costruttore : inizializza solo il nome
 public Individuo(String nome ){
   // padre e madre inizializzati di default a null
   this . nome = nome ;
 }
 // restituisce il nome
 public String getNome(){ 
   return nome ; 
 }
  // restituisce l’individuo padre
 public Individuo getPadre(){
   return padre ; 
 }
  // imposta il padre (se non ancora impostato )
 public void setPadre(Individuo padre){
   if( this . padre == null )
     this . padre = padre ;
 }
 // restituisce l’individuo madre
 public Individuo getMadre(){
   return madre ; 
 }
 // imposta la madre (se non ancora impostata )
 public void setMadre(Individuo madre){
   if ( this . madre == null ) 
     this . madre = madre ;
 }

 // nuovo metodo della classe Individuo
  public void stampaAlberoGenealogico0(){
   System.out.println(nome);
   if ( padre != null ) 
     padre.stampaAlberoGenealogico();
   if ( madre != null ) 
     madre.stampaAlberoGenealogico();
 }
 
 // nuovo metodo della classe Individuo
  public void stampaAlberoGenealogico(){
   System.out.println(nome);
   if (padre != null){
     System.out.print(" --");
     padre.stampaAlberoGenealogico();
   }
   if (madre != null ) {
     System.out.print(" --");
     madre.stampaAlberoGenealogico();
   }
 }
 
  // nuovo metodo della classe Individuo
  public void stampaAlberoGenealogico(int contatore){ 
    // stampa tanti trattini quanti indicati da contatore
    for(int i = 0; i < contatore ; i ++)
      System.out.print (" --");
    System.out.println( nome );
    // chiamate ricorsive con contatore aumentato
    if(padre != null ) 
      padre.stampaAlberoGenealogico(contatore + 1);
    if(madre != null ) 
      madre.stampaAlberoGenealogico(contatore + 1);
  }
 
 
 
}

