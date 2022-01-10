package me.gca;

class NodoBin { // nodo di albero binario
  int dato;
  NodoBin sinistro;
  NodoBin destro;

  public NodoBin(int d){
    dato = d;
    sinistro = null;
    destro = null;
  }

  public NodoBin(int d,NodoBin SX,NodoBin DX){
    dato = d;
    sinistro = SX;
    destro = DX;
  }

  // metodo della classe NodoBin - con parentesi anche esterne
  public String toString1(){
    String q = "("+ dato;
    if (sinistro != null)
      q += sinistro +",";
    else
      q += ",";
    if (destro != null)
      q += destro;
    else
      q += " ";
    return q + ")";
   }

  // metodo della classe NodoBin
  public String toString(){
    String q = "";
    q += dato;
    if (sinistro != null)
      q += "(" + sinistro + "),";
    else
      q += "(),";
    if (destro != null)
      q += "(" + destro+ ")";
    else
      q += "()";
    return q;
   }

  public void insNodeInternal(int val) {
    if (val<= dato){
      if (sinistro!=null)
        sinistro.insNodeInternal(val);
      else
        sinistro = new NodoBin(val); }
    else{
      if (destro!=null)
        destro.insNodeInternal(val);
      else
       destro = new NodoBin(val);
    }
   }

  public void nodoBinPreorder(){
    System.out.print(dato + " ");
    if (sinistro!=null)
      sinistro.nodoBinPreorder();
    if (destro!=null)
      destro.nodoBinPreorder();
   }

  public void nodoBinPostorder(){
    if (sinistro!=null)
      sinistro.nodoBinPostorder();
    if (destro!=null)
      destro.nodoBinPostorder();
    System.out.print(dato+ " ");
   }

   public void nodoBinInorder(){
     if (sinistro!=null)
       sinistro.nodoBinInorder();
     System.out.print(dato+ " ");
     if (destro!=null)
       destro.nodoBinInorder();
   }


  public boolean nodoBinInTree(int val) {
    if (val == dato)
      return true;
    else
      if (val<dato){
        if (sinistro!=null)
          return sinistro.nodoBinInTree(val);
        else
          return false;
      }
      else{
        if (destro!=null)
          return destro.nodoBinInTree(val);
         else
           return false;
      }
  }

   public int nodeHeight(int val, int h) {
    if (val == dato)
      return h;
    else if (val<dato) {
      if (sinistro!=null)
        return sinistro. nodeHeight(val, h+1);
      else return -1;
      }
      else {
        if (destro!=null)
          return destro. nodeHeight(val, h+1);
        else return -1;
      }
  }
}

