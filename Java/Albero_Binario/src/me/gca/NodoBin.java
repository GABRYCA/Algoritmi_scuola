package me.gca;

class NodoBin {

  // Parametri, come valore e nodo sinistro e destro se presenti.
  int dato;
  NodoBin sinistro;
  NodoBin destro;

  /**
   * Costruttore da singolo dato.
   * */
  public NodoBin(int d){
    dato = d;
    sinistro = null;
    destro = null;
  }

  /**
   * Costruttore da singolo dato e valore di sinistra e destra.
   * */
  public NodoBin(int d, NodoBin SX, NodoBin DX){
    dato = d;
    sinistro = SX;
    destro = DX;
  }

  /**
   * Scrive il contenuto del nodo.
   * */
  public String toString1(){
    String q = "("+ dato;
    if (sinistro != null){
      q += sinistro +",";
    } else {
      q += ",";
    }
    if (destro != null) {
      q += destro;
    } else {
      q += " ";
    }
    return q + ")";
   }

  /**
   * Scrive il contenuto del nodo, utilizzato nell'albero binario insieme all'intero albero.
   * */
  public String toString(){
    String q = "";
    q += dato;
    if (sinistro != null) {
      q += "(" + sinistro + "),";
    } else {
      q += "(),";
    }
    if (destro != null) {
      q += "(" + destro + ")";
    } else {
      q += "()";
    }
    return q;
  }

   /**
    * Inserisce il valore specificato al nodo.
    * */
  public void insNodoInterno(int val) {
    if (val <= dato) {
      if (sinistro != null) {
        sinistro.insNodoInterno(val);
      } else {
        sinistro = new NodoBin(val);
      }
    } else {
      if (destro != null) {
        destro.insNodoInterno(val);
      } else {
        destro = new NodoBin(val);
      }
    }
  }

   /**
    * Lettura in preorder singolo nodo.
    * */
   public void nodoBinPreorder(){
     System.out.print(dato + " ");
     if (sinistro != null) sinistro.nodoBinPreorder();
     if (destro != null) destro.nodoBinPreorder();
   }

   /**
    * Lettura in postorder singolo nodo.
    * */
  public void nodoBinPostorder(){
    if (sinistro != null) sinistro.nodoBinPostorder();
    if (destro != null) destro.nodoBinPostorder();
    System.out.print(dato + " ");
  }

   /**
    * Lettura in inorder singolo nodo.
    * */
   public void nodoBinInorder(){
     if (sinistro != null) sinistro.nodoBinInorder();
     System.out.print(dato + " ");
     if (destro != null) destro.nodoBinInorder();
   }

   /**
    * Ritorna true se il valore è contenuto nel nodo.
    * */
   public boolean nodoBinInAlbero(int val) {
     if (val == dato) {
       return true;
     }
     if (val<dato){
       if (sinistro!=null) return sinistro.nodoBinInAlbero(val);
       return false;
     } else {
       if (destro!=null) return destro.nodoBinInAlbero(val);
       return false;
     }
   }

   /**
    * Altezza.
    * */
   public int altezzaNodo(int val, int h) {
    if (val == dato) {
      return h;
    }
    if (val<dato) {
      if (sinistro!=null) return sinistro.altezzaNodo(val, h+1);
      return -1;
    } else {
      if (destro!=null) return destro.altezzaNodo(val, h+1);
      return -1;
    }
  }
}

