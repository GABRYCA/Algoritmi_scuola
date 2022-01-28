
public class UsaAlberoGenealogico {
  public static void main ( String [] args ) {
    Individuo bart = new Individuo (" Bart Simpson ");
    Individuo marge = new Individuo (" Marge Bouvier ");
    bart . setMadre ( marge );
    Individuo homer = new Individuo (" Homer Simpson ");
     bart . setPadre ( homer );
    Individuo nonno1 = new Individuo (" Abraham Simpson ");
    homer . setPadre ( nonno1 ); // nota : metodo invocato su homer !
    Individuo nonna1 = new Individuo (" Mona Simpson ");
    homer . setMadre ( nonna1 ); // nota : metodo invocato su homer !
    Individuo nonno2 = new Individuo (" Clancy Bouvier ");
    marge . setPadre ( nonno2 ); // nota : metodo invocato su marge ! 
    Individuo nonna2 = new Individuo (" Jacqueline Bouvier ");
    marge . setMadre ( nonna2 ); // nota : metodo invocato su marge !
    
    bart . stampaAlberoGenealogico ();
    
    bart . stampaAlberoGenealogico (0);
    
  }
}
