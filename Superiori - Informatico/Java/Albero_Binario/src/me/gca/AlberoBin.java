package me.gca;

public class AlberoBin {

  // Crea nodo di base.
  protected NodoBin padre;

  /**
   * Costruttore, setto il nodo padre iniziale a null.
   * */
  public AlberoBin() { // come AlberoGen
    padre = null;
  }

  /**
   * Stampa da stringa l'albero.
   * */
  public String toString(){
    String q = "";
    if (padre == null) {
      return "NULL";
    }
    return "" + padre + "";
  }

  /**
   * Albero da vettore di interi.
   * */
  void creaDaVettore(int[] vettore, int inizio, int tanti){
    padre = daVettore(vettore,inizio,tanti);
  }

  /**
   * Creo singolo nodo da vettore in modo ricorsivo.
   * */
  public NodoBin daVettore(int[] vettore, int iniz, int tanti){
    NodoBin temp;
    // Se vera, superato il limite del vettore.
    if (iniz >= tanti) {
      return null;
    }
    // Nessun valore rimasto da aggiungere.
    if (vettore[iniz] == 0) {
      return null;
    // Creo il nodo.
    } else {
      temp = new NodoBin(vettore[iniz], null, null);
    }
    // Albero sinistro.
    temp.sinistro = daVettore(vettore, 2*iniz+1, tanti);
    // Albero destro.
    temp.destro   = daVettore(vettore, 2*iniz+2, tanti);
    // Ritorno padre/Nodo.
    return temp;
   }

   /**
    * Ritorna true se l'albero è vuoto.
    * */
   public boolean alberoVuoto(){
    return (padre ==null);
  }

  /**
   * Inserisci nodo da valore.
   * */
  public void insNode(int val){
    if (alberoVuoto()){
      padre = new NodoBin(val);
    } else {
      padre.insNodoInterno(val);
    }
  }

  /**
   * Legge in modo ricorsivo dal nodo specificato in modalità preorder.
   * */
  public void preorder(NodoBin radice){
    if(radice != null){
      System.out.print(radice.dato + " ");
      preorder(radice.sinistro);
      preorder(radice.destro);
    }
  }

  /**
   * Legge in modo ricorsivo dal nodo specificato in modalità postorder.
   * */
  public void postorder(NodoBin radice){
    if(radice != null){
      postorder(radice.sinistro);
      postorder(radice.destro);
      System.out.print(radice.dato + " ");
    }
  }

  /**
   * Legge in modo ricorsivo dal nodo specificato in modalità inorder.
   * */
  public void inorder(NodoBin radice){
    if(radice != null){
      inorder(radice.sinistro);
      System.out.print(radice.dato + " ");
      inorder(radice.destro);
    }
  }

  /**
   * Leggo l'intero albero da questo nodo in modo ricorsivo, in modalità preorder.
   * */
  public void preorder1(){
    System.out.print("\n preorder  : ");
    if (padre != null)
      padre.nodoBinPreorder();
  }

  /**
   * Leggo l'intero albero da questo nodo in modo ricorsivo, in modalità postorder.
   * */
  public void postorder1(){
    System.out.print("\n postorder : ");
    if (padre != null) {
      padre.nodoBinPostorder();
    }
  }

  /**
   * Leggo l'intero albero da questo nodo in modo ricorsivo, in modalità inorder.
   * */
  public void inorder1(){
    System.out.print("\n inorder   : ");
    if (padre != null) {
      padre.nodoBinInorder();
    }
  }

  /**
   * Ritorna true se il valore specificato è presente nell'albero.
   * */
  public boolean inAlbero(int val){
    if (alberoVuoto()) {
      return false;
    }
    return padre.nodoBinInAlbero(val);
  }

  /**
   * Ritorna l'altezza dell'albero.
   * */
  public int altezza(int val){
   if (alberoVuoto()) {
     return -1;
   }
   return padre.altezzaNodo(val, 0);
  }

  /**
   * Cerca a partire dal nodo specificato il valore richiesto, ritorna true se trovato.
   * */
  public boolean cerca(NodoBin nodo, int val){
    if (val == nodo.dato) {
      return true;
    } else {
      if (val < nodo.dato) {
        if (nodo.sinistro != null) {
          return cerca(nodo.sinistro, val);
        } else {
          return false;
        }
      } else {
        if (nodo.destro != null) {
          return cerca(nodo.destro, val);
        } else {
          return false;
        }
      }
    }
  }
  
  /**
   * Cerca nel nodo specificato il valore.
   * */
  public boolean ABR_cercaRic(NodoBin nodo, int val){
    if (nodo==null) {
      return false;
    }
    if (val == nodo.dato) {
      return true;
    }
    if (val<nodo.dato) {
      if (nodo.sinistro != null) {
        return ABR_cercaRic(nodo.sinistro, val);
      }
      return false;
    }
    if (nodo.destro!=null) {
      return ABR_cercaRic(nodo.destro, val);
    }
    return false;
  }
}
    
  


