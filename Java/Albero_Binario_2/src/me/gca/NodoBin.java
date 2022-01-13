package me.gca;

class NodoBin {

  // Parametri, come valore e nodo sinistro e destro se presenti.
  int dato;
  NodoBin sinistro;
  NodoBin destro;

  /**
   * Costruttore da singolo dato.
   *
   * @param dato
   */
  public NodoBin(int dato){
    this.dato = dato;
    sinistro = null;
    destro = null;
  }

  /**
   * Costruttore da dato e valore di sinistra e destra.
   *
   * @param dato
   * @param SX
   * @param DX
   */
  public NodoBin(int dato, NodoBin SX, NodoBin DX){
    this.dato = dato;
    sinistro = SX;
    destro = DX;
  }

  /**
   * Ritorna dato.
   *
   * @return
   */
  public int getDato(){
    return dato;
  }

  /**
   * Setta dato.
   *
   * @param dato
   */
  public void setDato(int dato){
    this.dato = dato;
  }

  /**
   * Scrive il contenuto del nodo.
   *
   * @return
   */
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
   *
   * @return
   */
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
    *
    * @param val
    */
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
    *
    * @param val
    * @return
    */
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
    *
    * @param val
    * @param h
    * @return
    */
   public int altezzaNodo(int val, int h) {
     if (val == dato) {
       return h;
     }
     if (val < dato) {
       if (sinistro != null) return sinistro.altezzaNodo(val, h+1);
       return -1;
     } else {
       if (destro != null) return destro.altezzaNodo(val, h+1);
       return -1;
     }
   }
}