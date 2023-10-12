public class AlberoBin {
  protected NodoBin radice; // riferimento a radice

   public AlberoBin() { // come AlberoGen
    radice = null;
  }

    public String toString(){
    String q = "";
    if (radice == null)
      return "NULL";
    else
      return "" + radice + "";
  }

  // carica albero a partire da un vettore heap
  void crea_da_array(int[] heap, int inizio, int tanti){
    radice = da_heap(heap,inizio,tanti);
  }
  public NodoBin da_heap(int[] heap, int iniz, int tanti){
    NodoBin tmp;
    if (iniz >= tanti)
      return null;          // superata DIM  del vettore
    if (heap[iniz] == 0)
      return null;          // non c'e' nodo da aggiungere
    else{                   // creo il nuovo nodo
      tmp = new NodoBin(heap[iniz], null, null);
    }
    // chiamata  per creare il sottoalbero sinistro
    tmp.sinistro = da_heap(heap, 2*iniz+1, tanti);
    // chiamata  per creare il sottoalbero destro
    tmp.destro   = da_heap(heap, 2*iniz+2, tanti);
    return tmp;        //restituisco la radice
   }


  public boolean emptyTree(){ // come AlberoGen
    return (radice==null);
  }

  public void insNode(int val){
    if (emptyTree())
      radice = new NodoBin(val);
    else
      radice.insNodeInternal(val);
  }

  public void preorder(NodoBin radice){
    if(radice != null){
      System.out.print(radice.dato + " ");
      preorder(radice.sinistro);
      preorder(radice.destro);
    }
  }

  public void postorder(NodoBin radice){
    if(radice != null){
      postorder(radice.sinistro);
      postorder(radice.destro);
      System.out.print(radice.dato + " ");
    }
  }

  public void inorder(NodoBin radice){
    if(radice != null){
      inorder(radice.sinistro);
      System.out.print(radice.dato + " ");
      inorder(radice.destro);
    }
  }

  public void preorder1(){
    System.out.print("\n preorder  : ");
    if (radice != null)
      radice.nodoBinPreorder();
  }

  public void postorder1(){
    System.out.print("\n postorder : ");
    if (radice != null)
      radice.nodoBinPostorder();
  }

  public void inorder1(){
    System.out.print("\n inorder   : ");
    if (radice != null)
      radice.nodoBinInorder();
  }

  public boolean inTree(int val){
    if (emptyTree())
      return false;
    else return radice.nodoBinInTree(val);
  }

  public int height(int val){
   if (emptyTree())
     return -1;
   else return radice.nodeHeight(val, 0);
  }
  
  public boolean cerca(NodoBin nodo, int val){
    if (val == nodo.dato)
      return true;
    else
      if (val<nodo.dato){
        if (nodo.sinistro!=null)
          return cerca(nodo.sinistro,val);
        else
          return false;
      }
      else{
        if (nodo.destro!=null)
          return cerca(nodo.destro,val);
         else
           return false;
      }
  }
  
  
  public boolean ABR_cercaRic(NodoBin nodo, int val){
    if (nodo==null)
      return false;
    else   
      if (val == nodo.dato)
        return true;
      else
        if (val<nodo.dato)
          if(nodo.sinistro!=null)
            return ABR_cercaRic(nodo.sinistro,val);
          else return false;
        else
          if (nodo.destro!=null)
            return ABR_cercaRic(nodo.destro,val);
          else return false;    
    }
  }
    
  


